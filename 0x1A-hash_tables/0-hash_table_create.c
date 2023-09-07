#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * struct hash_table_entry - Structure for hash table entry
 * @key: The key of the entry
 * @value: The value of the entry
 * @next: Pointer to the next entry in case of collision
 */
typedef struct hash_table_entry {
	char *key;
	char *value;
	struct hash_table_entry *next;
} hash_table_entry_t;

/**
 * struct hash_table - Structure for hash table
 * @size: The size of the hash table array
 * @entries: Array of pointers to the entries in the hash table
 */
typedef struct hash_table {
	unsigned long int size;
	hash_table_entry_t **entries;
} hash_table_t;

/**
 * hash_function - Hash function to map keys to array indices
 * @key: The key to be hashed
 * @size: The size of the array
 *
 * Return: The hash value
 */
unsigned long int hash_function(char *key, unsigned long int size)
{
	unsigned long int hash = 0;
	int c;

	while ((c = *key++))
		hash = c + (hash << 6) + (hash << 16) - hash;

	return (hash % size);
}

/**
 * hash_table_create - Create a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table, or NULL if an error occurred
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->size = size;
	hash_table->entries = calloc(size, sizeof(hash_table_entry_t *));
	if (hash_table->entries == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	return (hash_table);
}

