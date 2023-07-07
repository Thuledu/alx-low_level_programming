#include <stdio.h>
#include "main.h"
/**
 * get_endianness - function that checks
 * the endianness of a machine.
 * Return: 0 (big edian), or 1 (little edian)
 */
int get_endianness(void)
{
	int j = 1;
	char *a = (char *)&j;

	if (*a)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
