#include "hash_tables.h"

/**
	* hash_table_get - Retrieves a value associated with a key.
	* @ht: Hash table.
	* @key: The key.
	* Return: The value, or NULL if key not found.
	*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !key || !*key)
	return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
	if (strcmp(node->key, key) == 0)
	return (node->value);
	node = node->next;
	}

	return (NULL);
}
