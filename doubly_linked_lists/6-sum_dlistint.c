#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data of a dlistint_t linked list
 * @head: pointer to head
 *
 * Return: sum or 0
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
