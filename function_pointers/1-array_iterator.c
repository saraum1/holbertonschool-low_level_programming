#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an int array
 * @array: pointer to int array
 * @size: number of elements
 * @action: pointer to function that takes int and returns void
 *
 * Return: nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
