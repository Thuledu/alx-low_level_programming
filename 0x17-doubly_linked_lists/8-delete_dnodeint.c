#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - Deletes the node at a given index of a dlistint_t linked list.
 * @head: A double pointer to the head of the linked list.
 * @index: The index of the node to be deleted (starts at 0).
 *
 * Return: 1 if deletion is successful, -1 otherwise.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	dlistint_t *previous = NULL;

	if (current == NULL)
	{
		return -1; /* List is empty */
	}

	while (current != NULL && index > 0)
	{
		previous = current;
		current = current->next;
		index--;
	}

	if (current == NULL)
	{
		return -1; /* Index is out of range */
	}

	if (previous == NULL)
		*head = current->next;
	else
		previous->next = current->next;

	if (current->next != NULL)
	{
		current->next->prev = previous;
	}

	free(current);
	return 1;
}
