#include "main.h"
#include <stdio.h>

/**
 * _strncpy - Copies a specified number of characters from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 * Return: Pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int index;

    for (index = 0; index < n && src[index]; index++)
        dest[index] = src[index];

    for (; index < n; index++)
        dest[index] = '\0';

    return dest;
}
