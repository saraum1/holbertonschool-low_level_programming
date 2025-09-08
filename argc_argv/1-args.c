#include <stdio.h>

/**
 * main - prints the number of arguments passed into the program
 * @argc: argument count
 * @argv: argument vector (unused)
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argv; /* silence unused variable */
	printf("%d\n", argc - 1);
	return (0);
}

