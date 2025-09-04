#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination buffer (must have enough space).
 * @src:  Source string to append.
 *
 * Return: Pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
