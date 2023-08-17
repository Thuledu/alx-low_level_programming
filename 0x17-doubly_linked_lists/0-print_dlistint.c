#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_dlistint - Prints all the elements of a dlistint_t list
 * @h: Pointer to the head of the list
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
    const dlistint_t *current;
    size_t count = 0;

    if (h == NULL)
    {
        return (0);
    }

    current = h;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
        count++;
    }

    return (count);
}
