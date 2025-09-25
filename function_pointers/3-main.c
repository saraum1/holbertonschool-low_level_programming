#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - simple calculator
 * @argc: args count
 * @argv: args vector
 * Return: 0 on success, or exits with codes 98/99/100 per spec
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*opf)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	opf = get_op_func(argv[2]);
	if (opf == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = opf(a, b);
	printf("%d\n", result);
	return (0);
}
