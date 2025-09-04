#include "main.h"

/**
 * _strncat - Concatenates up to n bytes of src to dest.
 * @dest: Destination buffer.
 * @src:  Source string.
 * @n:    Max number of bytes from src.
 *
 * Return: Pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
