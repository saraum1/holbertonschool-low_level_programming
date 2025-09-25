#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison function
 * @array: pointer to int array
 * @size: number of elements in array
 * @cmp: pointer to comparison function (returns non-zero if match)
 *
 * Return: index of first element for which cmp != 0, or -1 on failure/no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}
