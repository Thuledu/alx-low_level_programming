#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_binary - function that prints the binary
* equivalent of a decimal number
* @n: the number to print in binary
* Return: void
*/
void print_binary(unsigned long int n)
{

	unsigned long int curr;
	int j;

	for (j = 63; j >= 0; j--)
	{
		curr = n >> j;

		if (curr & 1)
		{
			putchar('1');
			break;
		}
		else if (j == 0)
			putchar('0');
	}

	for (; j >= 0; j--)
	{
		curr = n >> j;

		if (curr & 1)
			putchar('1');
		else
			putchar('0');
	}
}

