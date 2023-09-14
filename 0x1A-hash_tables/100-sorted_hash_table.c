#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);

/**
 * shash_table_create - Create a sorted hash table
 * @size: The size of the hash table
 * Return: A pointer to the created hash table, or NULL if it fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (unsigned long int i = 0; i < size; i++)
        ht->array[i] = NULL;

    return (ht);
}

/**
 * shash_table_set - Insert a key-value pair into a sorted hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value
 * Return: 1 if success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *node, *current, *prev;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];
    prev = NULL;

    while (current != NULL && strcmp(current->key, key) < 0)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL && strcmp(current->key, key) == 0)
    {
        free(current->value);
        current->value = strdup(value);
    }
    else
    {
        node = malloc(sizeof(shash_node_t));
        if (node == NULL)
            return (0);

        node->key = strdup(key);
        node->value = strdup(value);

        if (prev == NULL)
        {
            node->next = ht->array[index];
            ht->array[index] = node;
        }
        else
        {
            node->next = prev->next;
            prev->next = node;
        }
    }

    return (1);
}

/**
 * shash_table_get - Retrieve the value associated with a key in a sorted hash table
 * @ht: The hash table
 * @key: The key
 * Return: The value associated with the key, or NULL if the key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];

    while (current != NULL && strcmp(current->key, key) != 0)
        current = current->next;

    if (current != NULL)
        return (current->value);

    return (NULL);
}

/**
 * shash_table_print - Print the key-value pairs in a sorted hash table
 * @ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *current;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];

        while (current != NULL)
        {
            if (flag == 1)
                printf(", ");

            printf("'%s': '%s'", current->key, current->value);

            flag = 1;
            current = current->next;
        }
    }

    printf("}\n");
}

/**
 * shash_table_print_rev - Print the key-value pairs in a sorted hash table in reverse order
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *current;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");

    for (i = ht->size - 1; i >= 0; i--)
    {
        current = ht->array[i];

        while (current != NULL)
        {
            if (flag == 1)
                printf(", ");

            printf("'%s': '%s'", current->key, current->value);

            flag = 1;
            current = current->next;
        }
    }

    printf("}\n");
}

/**
 * shash_table_delete - Delete a sorted hash table
 * @ht: The hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *current, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];

        while (current != NULL)
        {
            temp = current;
            current = current->next;

            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);
    free(ht);
}

