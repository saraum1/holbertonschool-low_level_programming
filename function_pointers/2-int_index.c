#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: int array
 * @size: size of array
 * @cmp: compare function pointer
 * Return: index of first match or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}
	return (-1);
}
