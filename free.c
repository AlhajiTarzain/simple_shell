#include "header.h"

/**
 * empty - cleans memory area
 * @prr: pointer
 */
void empty(char **prr)
{
	int r = 0;

	if (prr)
	{
		while (prr[r])
		{
			free(prr[r]);
			r++;
		}
		free(prr);
	}
}
