#include "header.h"

/**
 * myputchar - writes a single character to the output.
 *
 *@c:character to be written to output.
 *Return:Character held in c written out.
 */

int myputchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _myprintf - invokes myputchar and prints a string.
 *
 *@str:pointer to string to be looped over and printed.
 *
 * Return:returns string.
 */

void _myprintf(const char *str)
{
	int l;

	for (l = 0; str[l] != '\0'; l++)
		myputchar(str[l]);
}
