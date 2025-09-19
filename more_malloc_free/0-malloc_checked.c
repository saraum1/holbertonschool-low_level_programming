#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory
 * If malloc fails, exit with status 98
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}

