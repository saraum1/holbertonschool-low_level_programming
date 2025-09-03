#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: converted integer (0 if no numbers)
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	int acc = 0;

	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
			started = 1;
		if (!started)
			i++;
	}
	if (!started)
		return (0);

	while (s[i] >= '0' && s[i] <= '9')
	{
		int d = s[i] - '0';

		if (sign > 0)
		{
			if (acc > (INT_MAX - d) / 10)
				return (INT_MAX);
			acc = acc * 10 + d;
		}
		else
		{
			if (acc < (INT_MIN + d) / 10)
				return (INT_MIN);
			acc = acc * 10 - d;
		}
		i++;
	}
	return (acc);
}

