#include "main.h"
#include <stdio.h>


/**
 * _strstr - Locates the first occurrence of a substring in a string.
 * @haystack: Pointer to the string.
 * @needle: Pointer to the substring to search for.
 *
 * Return: Pointer to the first occurrence of @needle in @haystack,
 *         or NULL if @needle is not found.
 */
char *_strstr(char *haystack, char *needle)
{
    char *beginning;

    while (*haystack != '\0')
    {
        beginning = haystack;
        char *pattern = needle;

        while (*pattern == *haystack && *pattern != '\0' && *haystack != '\0')
        {
            haystack++;
            pattern++;
        }

        if (*pattern == '\0')
            return beginning;

        haystack = beginning + 1;
    }

    return NULL;
}
