#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: converted integer (0 if no numbers)
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	unsigned int num = 0;

	/* skip non-digit prefix while counting signs */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			sign *= 1;
		else if (s[i] >= '0' && s[i] <= '9')
			started = 1;
		else
		{
			/* ignore other chars */
		}

		if (!started)
			i++;
	}

	/* collect digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}

	if (sign < 0)
		return ((int)(-((int)num)));
	return ((int)num);
}

