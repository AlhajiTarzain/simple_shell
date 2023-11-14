#include "header.h"

/**
 * length - string length
 * @str: input string
 * Return: str lenght
 */
int length(const char *str)
{
	int counter = 0;

	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

/**
 * duplicator - duplicates atring in memroy
 * @str: the string to be duplicated
 * Return: 0 when success
 */
char *duplicator(const char *str)
{
	/* to check if string to be duplicated is empty */
	int len = 0;
	char *clone;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}


	/* to claculate string length for memory allocation*/
	while (str[len] != '\0')
	{
		len++;
	}

	clone = (char *)malloc(len + 1);

	if (clone != NULL)
	{
		for (i = 0; i <= len; i++)
		{
			clone[i] = str[i];
		}
	}
	return (clone);
}

/**
 * comp - compare between two given strings
 * @first: first string
 * @second: second string
 * Return: for confirm 1
 */
int comp(char *first, char *second)
{
	int r;

	for (r = 0; first[r] != '\0' || second[r] != '\0'; r++)
	{

		if (first[r] != second[r])
			return (first[r] - second[r]);
	}
	return (1);
}
