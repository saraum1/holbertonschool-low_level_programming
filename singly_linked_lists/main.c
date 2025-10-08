#include "lists.h"

/**
 * main - test linked list functions
 *
 * Return: Always 0.
 */
int main(void)
{
	list_t *head = NULL;

	add_node_end(&head, "Sara");
	add_node_end(&head, "Soso");
	print_list(head);
	free_list(head);

	return (0);
}
