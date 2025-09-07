#include "main.h"

/**
 * _prime_helper - recursively checks divisibility skipping even numbers
 * @n: number to test
 * @d: current odd divisor candidate (>= 3)
 *
 * Return: 1 if prime, 0 otherwise
 */
int _prime_helper(int n, int d)
{
	/* If d exceeded sqrt(n): no divisors found */
	if (d > (n / d))
		return (1);

	/* If divisible by current odd divisor */
	if ((n % d) == 0)
		return (0);

	/* Recurse to the next odd divisor */
	return (_prime_helper(n, d + 2));
}

/**
 * is_prime_number - returns 1 if n is a prime number, otherwise 0
 * @n: input integer
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	/* Handle negatives, 0, 1 */
	if (n <= 1)
		return (0);

	/* Handle 2 explicitly (only even prime) */
	if (n == 2)
		return (1);

	/* Even numbers > 2 are not prime */
	if ((n % 2) == 0)
		return (0);

	/* Check odd divisors starting from 3 */
	return (_prime_helper(n, 3));
}

