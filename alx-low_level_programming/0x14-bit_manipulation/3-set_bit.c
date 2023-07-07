#include <stdio.h>
#include "main.h"
/**
 * set_bit - function that sets the bit at the given index to 1.
 * @n: the pointer to an unsigned long int.
 * @index: The index of a bit to set.
 * Return: 1 (successful),
 * or -1 if error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	{
		return (-1);
	}

	*n |= 1UL << index;

	return (1);
}
