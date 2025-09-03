#include "main.h"
#include <limits.h>

/**
 * is_digit - check if c is '0'..'9'
 * @c: char
 * Return: 1 if digit else 0
 */
static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * acc_pos - accumulate positive with overflow clamp
 * @r: current (>= 0)
 * @d: digit 0..9
 * Return: INT_MAX if overflow else new value
 */
static int acc_pos(int r, int d)
{
	if (r > (INT_MAX - d) / 10)
		return (INT_MAX);
	return (r * 10 + d);
}

/**
 * acc_neg - accumulate negative with underflow clamp
 * @r: current (<= 0)
 * @d: digit 0..9
 * Return: INT_MIN if underflow else new value
 */
static int acc_neg(int r, int d)
{
	if (r < (INT_MIN + d) / 10)
		return (INT_MIN);
	return (r * 10 - d);
}

/**
 * _atoi - convert string to int
 * @s: input string
 * Return: converted int or 0 if no digits
 */
int _atoi(char *s)
{
	int sign = 1, r = 0;

	if (!s)
		return (0);

	/* skip to first digit, tallying '-' signs */
	while (*s && !is_digit(*s))
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}

	if (!*s) /* no digits at all */
		return (0);

	/* parse contiguous digits with clamping */
	while (*s && is_digit(*s))
	{
		int d = *s - '0';

		if (sign == 1)
		{
			r = acc_pos(r, d);
			if (r == INT_MAX)
				return (INT_MAX);
		}
		else
		{
			r = acc_neg(r, d);
			if (r == INT_MIN)
				return (INT_MIN);
		}
		s++;
	}
	return (r);
}

