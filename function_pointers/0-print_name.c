#include "function_pointers.h"
#include <stddef.h> /* for NULL */

/**
 * print_name - prints a name using a function pointer
 * @name: string to print
 * @f: pointer to function that prints
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
    if (name == NULL || f == NULL)
        return;

    f(name);
}

