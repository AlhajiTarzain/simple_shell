#include "header.h"
/**
 * copy - copies the string pointed by src
 * @s1: string dest
 * @s2: string crc
 * Return: location holder 9s10
 */
char *copy(char *s1, char *s2)
{
	int j;

	for (j = 0; s2[j] != '\0'; j++)
	{
		s1[j] = s2[j];
	}

	s1[j] = '\0';

	return (s1);
}

/**
 * concat - concatenates two string
 * @s1: dest of the str
 * @s2: src pf str
 *
 * Return: returns cocatenated location
 */

char *concat(char *s1, const char *s2)
{
	char *ptr = s1;

	while (*s1 != '\0')
	{
		s1++;
	}

	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';

	return (ptr);
}
