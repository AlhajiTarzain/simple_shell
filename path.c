#include "shell.h"

/**
 * create_path - compose full path to  executable by searching in PATH.
 * @args: executbles
 *
 * Return: string containing the full path to the executabl
 */
char *create_path(char *args)
{
	char buffer[BUFSIZ];
	char **direct, *clone;
	int i;
	struct stat file_num;

	if (args == NULL)
	{
		perror("Invalid input");
		return (NULL);
	}
	clone = getenv("PATH");
	if (clone == NULL)
	{
		perror("PATH environment variable not found");
		return (NULL);
	}
	copy(buffer, clone);
	direct = mktoken(buffer, ":");
	for (i = 0; direct[i]; i++)
	{
		clone = malloc(sizeof(char) * (length(direct[i]) + length(args) + 2));
		if (clone == NULL)
		{
			perror("Memory not allocated");
			break;
		}
		copy(clone, direct[i]);
		concat(clone, "/");
		concat(clone, args);
		if (stat(clone, &file_num) == 0)
		{
			if (direct != NULL)
				empty(direct);
			return (clone);
		}
		free(clone);
	}
	empty(direct);
	return (NULL);
}
