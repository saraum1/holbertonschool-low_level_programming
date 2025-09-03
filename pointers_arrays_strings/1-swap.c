#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: first int pointer
 * @b: second int pointer
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

