#include <stdio.h>
#include "main.h"
/**
 * clear_bit - function that clears a bit at the given index
 * @n: the pointer to a number to modify
 * @index: the index of a bit to clear
 * Return: 1 (successful),
 * or -1 (Error) if index is out of range
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	{
		return (-1);
	}

	*n &= ~(1UL << index);

	return (1);
}
