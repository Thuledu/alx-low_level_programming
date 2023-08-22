#include "main.h"
#include <stdio.h>

/**
 * _strspn - Calculates the length of the initial segment of a string
 *            consisting of only characters from another string.
 * @s: Pointer to the string.
 * @accept: Pointer to the string containing the accepted characters.
 * Return: Number of characters in the initial segment of @s that consists
 *         only of characters from @accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int num = 0;
    int i, j;
    char char_set[256] = {0};  // Array to store character set flags

    // Mark all characters in accept string as valid
    for (j = 0; accept[j] != '\0'; j++)
        char_set[(unsigned char)accept[j]] = 1;

    i = 0;
    while (s[i] != '\0' && char_set[(unsigned char)s[i]])
    {
        num++;
        i++;
    }

    return num;
}
