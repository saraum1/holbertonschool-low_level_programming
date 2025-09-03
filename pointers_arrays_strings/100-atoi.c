#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: converted integer (0 if no numbers)
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	int acc = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] == ' ')
			;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		int d = s[i] - '0';

		if (sign > 0)
			acc = acc * 10 + d;
		else
			acc = acc * 10 - d;

		i++;
	}
	return (acc);
}

