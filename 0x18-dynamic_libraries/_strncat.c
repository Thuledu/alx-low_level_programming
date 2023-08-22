#include "main.h"
#include <stdio.h>

/**
 * _strncat - Concatenates two strings up to a specified length.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of characters to concatenate.
 * Return: Pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
    char *concat = dest;

    while (*concat)
    {
        concat++;
    }

    while (*src && n--)
        *concat++ = *src++;

    *concat = '\0';

    return dest;
}

