#include "main.h"

/**
 * _sqrt_bs - recursive binary search for natural square root
 * @n: number to find its natural square root
 * @low: lower bound
 * @high: upper bound
 *
 * Return: the natural square root if it exists, otherwise -1
 */
int _sqrt_bs(int n, int low, int high)
{
	int mid, q;

	if (low > high)
		return (-1);

	mid = low + (high - low) / 2;

	/* Avoid mid*mid overflow by using division */
	q = n / mid;

	/* Exact square root: mid * mid == n  <=>  mid == n/mid && n%mid==0 */
	if (mid == q && (n % mid) == 0)
		return (mid);

	/* If mid^2 > n  <=>  mid > n/mid */
	if (mid > q)
		return (_sqrt_bs(n, low, mid - 1));

	/* Otherwise mid^2 < n */
	return (_sqrt_bs(n, mid + 1, high));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: input number
 *
 * Return: the natural square root, or -1 if it does not exist
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	/* Upper bound: n/2 + 1 is safe for n >= 2 */
	return (_sqrt_bs(n, 1, (n / 2) + 1));
}

