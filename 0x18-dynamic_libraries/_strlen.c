#include "main.h"
#include <stdio.h>

/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 * Return: The length of @s.
 */
int _strlen(char *s)
{
    const char *ptr = s;

    while (*ptr)
        ptr++;

    return (ptr - s);
}
