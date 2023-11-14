#include "header.h"

/**
 * main - program stats.
 * Return: program status.
 */

int main(void)
{
	char *prompt = "THE BIG BASH:$ ";
	char *input = NULL;
	char **token_arr;
	int result = 0;
	size_t size = 0;
	ssize_t iread;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			_myprintf(prompt);
		iread = getline(&input, &size, stdin);
		if (iread == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				myputchar('\n');
			break;
		}
		/*Remove the trailing newline character */
		if (input[iread - 1] == '\n')
			input[iread - 1] = '\0';

		token_arr = mktoken(input, " \t");
		if (token_arr[0] == NULL)
		{
			free(token_arr);
			continue;
		}
		if (comp(input, "exit") == 1)
		{
			_myprintf("Exiting shell...\n");
			exit(0);
		}

		result = inbuilt(token_arr, input, result);
		if (result == 1)
			result = checker(token_arr, input);
	}
	free(input);
	return (result);
}

