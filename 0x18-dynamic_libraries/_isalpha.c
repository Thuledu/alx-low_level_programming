#include "main.h"
#include <stdio.h>


/**
 * _isalpha - function to check if c is a letter, lowercase or uppercase
 * @c: the character to be checked
 * Return: 1 if letter, 0 otherwise
 */
int _isalpha(int c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
