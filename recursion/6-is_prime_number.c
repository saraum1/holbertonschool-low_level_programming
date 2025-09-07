#include "main.h"

/**
 * _prime_helper - checks divisibility recursively
 * @n: number
 * @d: current divisor
 * Return: 1 if prime, 0 otherwise
 */
static int _prime_helper(int n, int d)
{
	if (d * d > n)
		return (1);
	if (n % d == 0)
		return (0);
	return (_prime_helper(n, d + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: number
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (_prime_helper(n, 2));
}

