#include "hash_tables.h"

/**
	* hash_table_set - Adds or updates an element in the hash table.
	* @ht: Pointer to the hash table.
	* @key: Key (cannot be empty).
	* @value: Value associated with the key.
	* Return: 1 on success, 0 on failure.
	*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *tmp;
	char *value_copy;

	if (!ht || !key || !*key || !value)
	return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
	if (strcmp(tmp->key, key) == 0)
	{
	free(tmp->value);
	tmp->value = strdup(value);
	return (1);
	}
	tmp = tmp->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (!node)
	return (0);

	node->key = strdup(key);
	value_copy = strdup(value);
	if (!node->key || !value_copy)
	{
	free(node->key);
	free(node);
	return (0);
	}

	node->value = value_copy;
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
