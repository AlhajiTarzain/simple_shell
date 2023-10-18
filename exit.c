#include "header.h"

/**
 * exitshell - handle exit command
 * @cmd: array of strings conting command and args
 * @input: buffer
 * @status: exit status
 *
 * Return: 0 not continued, 1 invalid input, ezit
 */
int exitshell(char **cmd, char *input, int status)
{
	int exitStatus, i;

	if (cmd[1] == NULL)
	{
		empty(cmd);
		free(input);
		exit(status);
	}
	for (i = 0; cmd[1][i]; i++)
	{
		if (isdigit(cmd[1][i]) == 0)
		{
			empty(cmd);
			return (1);
		}
	}
	exitStatus = ston(cmd[1]);
	free(cmd);
	exit(exitStatus);
}
