#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Description:
 * Parses the first contiguous digit sequence in the string.
 * Considers all preceding '+' and '-' signs before the first digit.
 * Clamps on overflow to INT_MAX / INT_MIN and returns 0 if no digits.
 *
 * Return: the converted integer (or 0 if no digits are found)
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int started = 0;
	int d;

	if (s == 0)
		return (0);

	/* Move until the first digit; count signs on the way */
	while (*s && !(*s >= '0' && *s <= '9'))
	{
		if (*s == '-')
			sign = -sign;
		/* '+' does nothing */
		s++;
	}

	/* Build number; stop at the first non-digit after starting */
	while (*s && (*s >= '0' && *s <= '9'))
	{
		d = *s - '0';
		started = 1;

		if (sign == 1)
		{
			/* Check overflow before result * 10 + d */
			if (result > (INT_MAX - d) / 10)
				return (INT_MAX);
			result = (result * 10) + d;
		}
		else
		{
			/*
			 * Accumulate as negative to reach INT_MIN safely:
			 * result = result * 10 - d; check underflow first.
			 */
			if (result < (INT_MIN + d) / 10)
				return (INT_MIN);
			result = (result * 10) - d;
		}
		s++;
	}

	if (!started)
		return (0);

	return (result);
}

