#include "main.h"
#include <stdio.h>
/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: Pointer to the string.
 * @accept: Pointer to the string containing the characters to search for.
 *
 * Return: Pointer to the first occurrence of any character from @accept
 *         in the string @s, or NULL if no match is found.
 */
char *_strpbrk(char *s, char *accept)
{
    int i, j;
    char char_set[256] = {0};  // Array to store character set flags

    // Mark all characters in accept string as valid
    for (j = 0; accept[j] != '\0'; j++)
        char_set[(unsigned char)accept[j]] = 1;

    i = 0;
    while (s[i] != '\0')
    {
        if (char_set[(unsigned char)s[i]])
            return (s + i);
        i++;
    }

    return NULL;
}
