#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: string pointer
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char tmp;

	while (s[j] != '\0')
		j++;
	j--;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

