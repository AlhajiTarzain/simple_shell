#include "header.h"
/**
 * inbenv -handles env variable
 * Return:0 on success
 */

int inbenv(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

