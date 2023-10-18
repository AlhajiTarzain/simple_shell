#include "header.h"
/**
 * mtoken - Tokeze agiven string
 * @input_str: the input string
 * @delimiter: the char used to tokenize
 * Return: rray of tkens
 */
char **mtoken(char *input_str, char *delimiter)
{
	char *token, *input_copy, **token_array;
	int num_tokens;

	input_copy = duplicator(input_str);

	if (input_copy == NULL)
		return (NULL);

	token = strtok(input_copy, delimiter);
	num_tokens = 0;
	while (token != NULL)
	{
		++num_tokens;
		token = strtok(NULL, delimiter);
	}
	token_array = (char **)malloc(sizeof(char *) * (num_tokens + 1));
	if (token_array == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	token = strtok(input_str, delimiter);
	num_tokens = 0;
	while (token != NULL)
	{
		token_array[num_tokens] = duplicator(token);
		if (token_array[num_tokens] == NULL)
		{
			free(token_array);
			free(input_copy);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		++num_tokens;
	}
	free(input_copy);
	token_array[num_tokens] = NULL;
	return (token_array);
}

