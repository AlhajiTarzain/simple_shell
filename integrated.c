#include "shell.h"

int inbuilt(char **args, char *input,int status)
{
	char *builtins[] = {"exit", "env", NULL};
	int i = 0;

	while(builtins[i] != NULL)
	{
		if (comp(builtins[i], args[0]) == 0)
		{
			if (i == 0)
			{ 
				return exitshell(args,input,status);
			}
			else if (i == 1)
			{
				return inbenv();
			}
		}
		i++;
	}
	return (1);
}
