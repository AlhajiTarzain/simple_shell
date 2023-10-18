#include "header.h"

/**
 * ston - converts a string to a num
 * @str: string to be converted
 *
 * Return: converted number
 */
int ston(char *str)
{
	int index = 0;
	int minus_count = 0;
	int number = 0;
	int length = 0;
	int sign = 0;
	int has_number = 0;

	while (str[length] != '\0')
	{
		if (str[index] == '-')
			++minus_count;

		if (str[index] >= '0' && str[index] <= '9')
		{
			has_number = str[index] - '0';
			if (minus_count % 2)
				has_number = -has_number;
			number = number * 10 + has_number;
			sign = 1;
			if (str[index + 1] < '0' || str[index + 1] > '9')
				break;
			sign = 0;
		}
		index++;
	}

	if (sign == 0)
		return (0);

	return (number);
}
