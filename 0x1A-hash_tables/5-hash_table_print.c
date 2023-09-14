#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 */
void hash_table_print(const hash_table_t *ht) {
	hash_node_t *node;
	unsigned long int i;
	unsigned char comma_flag = 0;
	
	if (ht == NULL) {
		return;
    }
	
	for (int i = 0; i < ht->size; i++) {
		mode_t *current = ht->array[i];

        while (current != NULL) {
		printf("%s: %s\n", current->key, current->value);
		current = current->next;
        }
    }
}
