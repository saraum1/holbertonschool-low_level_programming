#include "main.h"

/**
 * _strcmp - Compares two strings (like strcmp).
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: <0 if s1<s2, 0 if equal, >0 if s1>s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
