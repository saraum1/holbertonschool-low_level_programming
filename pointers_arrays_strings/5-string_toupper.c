#include "main.h"

/**
 * string_toupper - Converts all lowercase letters to uppercase.
 * @s: String pointer.
 *
 * Return: Pointer to s.
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}
