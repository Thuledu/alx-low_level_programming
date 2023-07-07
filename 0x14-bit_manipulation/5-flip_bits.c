#include <stdio.h>
#include "main.h"
/**
 * flip_bits - function that returns the number of bits you
 * would need to flip to get from one number to another
 * @n: the 1st number
 * @m: the 2nd number
 * Return: the number of bits that are needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int excl = n ^ m;
	unsigned int cnt = 0;

	while (excl != 0)
	{
		cnt++;
		excl &= (excl - 1);
	}

	return (cnt);
}
