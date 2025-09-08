#include <stdio.h>

/**
 * main - prints the program name (including its path), followed by a new line
 * @argc: argument count (unused)
 * @argv: array of argument strings; argv[0] is the program name/path
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argc; /* silence unused-parameter warning */

	printf("%s\n", argv[0]);
	return (0);
}

