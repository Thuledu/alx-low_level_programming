#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: the pointer to string containing the binary number
 * Return: converted number or otherwise 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0;
	int j;

	if (b == NULL)
	{
		return (0);
	}

	for (j = 0; b[j] != '\0'; j++)
	{
		if (b[j] != '0' && b[j] != '1')
		{
			return (0);
		}

		decimal = decimal << 1;

		if (b[j] == '1')
		{
			decimal += 1;
		}
	}
	return (decimal);
}
