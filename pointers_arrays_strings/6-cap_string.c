#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @s: String pointer.
 *
 * Separators:
 * space, tab, newline, ',', ';', '.', '!', '?', '"', '(', ')', '{', '}'.
 *
 * Return: Pointer to s.
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;

	for (i = 1; s[i] != '\0'; i++)
	{
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (s[i - 1] == sep[j] && (s[i] >= 'a' && s[i] <= 'z'))
			{
				s[i] -= 32;
				break;
			}
		}
	}
	return (s);
}
