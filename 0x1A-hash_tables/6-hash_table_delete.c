#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int i;

    if (ht == NULL) {
        return;
    }

    for (int i = 0; i < ht->size; i++) {
        mode_t *current = ht->array[i];

        while (current != NULL) {
            mode_t *temp = current;
            current = current->next;

            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);
    free(ht);
}
