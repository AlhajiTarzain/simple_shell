#include "header.h"

/**
 * checker - Check whether a given command exists and then execute it
 * @args: Array of strings containing the command and its arguments
 * @buffer: Buffer for the input strings
 * Return: 0 if successful, 127 if the command is not found
 */
int checker(char **args, char *buffer)
{
	int cmd_status;
	char *path;
	struct stat status;

	if (stat(args[0], &status) == 0)
		cmd_status = execute_cmd(args, buffer);
	else
	{
		path = create_path(args[0]);
		if (path != NULL)
		{
			free(args[0]);
			args[0] = path;
			cmd_status = execute_cmd(args, buffer);
		}
		else
		{
			empty(args);
			return (127);
		}
	}
	empty(args);
	return (cmd_status);
}


/**
 * execute_cmd - Execute a command with its arguments in a child process.
 * @args: Array of strings containing the command and its arguments.
 * @line: Buffer for the input strings (unused).
 *
 * Return: 0 if command is executed, or -1 in case of an error.
 */
int execute_cmd(char **args, __attribute__((unused)) char *line)
{
	int stat;

	stat = 0;

	switch (fork())
	{
		case -1:
			perror("error\n");
			break;
		case 0:
			execve(args[0], args, environ);
			exit(0);
		default:
			wait(NULL);
			break;
	}
	return (stat);
}
