#include "main.h"
#include <stdio.h>

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 * Return: Pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
    char *cat = dest;

    while (*cat)
    {
        cat++;
    }

    while ((*cat++ = *src++))
        ;

    return dest;
}
