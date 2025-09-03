#include "main.h"

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: string pointer
 */
void print_rev(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	while (len > 0)
	{
		len--;
		_putchar(s[len]);
	}
	_putchar('\n');
}

