#include "main.h"
#include <stdio.h>

/**
 * _strcpy - Copies a string from src to dest.
 * @dest: The destination buffer.
 * @src: The source string.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
    char *dest_ptr = dest;

    while ((*dest_ptr++ = *src++))
        ;

    return dest;
}
