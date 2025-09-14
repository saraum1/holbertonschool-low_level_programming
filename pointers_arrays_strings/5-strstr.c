#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: main string
 * @needle: substring to find
 *
 * Return: pointer to beginning of substring or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	if (*needle == '\0')
		return (haystack);

	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return (haystack);
		haystack++;
	}
	return (NULL);
}

