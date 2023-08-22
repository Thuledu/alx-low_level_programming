#include "main.h"
#include <stdio.h>

/**
 * _memset - Fills a block of memory with a specified value.
 * @s: Pointer to the memory block.
 * @b: Value to be set.
 * @n: Number of bytes to be set.
 * Return: Pointer to the memory block.
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned char *memory = s;
    unsigned long long wide_value;
    unsigned long long *wide_ptr;
    size_t wide_index, wide_count;

    // Set the value byte-wise if n is small
    if (n < sizeof(unsigned long long))
    {
        unsigned char value = b;
        for (size_t i = 0; i < n; i++)
            memory[i] = value;
    }
    else
    {
        // Set the value in a wider data type
        wide_value = (unsigned char)b;
        wide_value |= wide_value << 8;
        wide_value |= wide_value << 16;
        wide_value |= wide_value << 32;

        // Set memory in wide chunks
        wide_ptr = (unsigned long long *)memory;
        wide_count = n / sizeof(unsigned long long);
        for (wide_index = 0; wide_index < wide_count; wide_index++)
		wide_ptr[wide_index] = wide_value;

        // Set the remaining bytes byte-wise
        memory += wide_index * sizeof(unsigned long long);
        n -= wide_index * sizeof(unsigned long long);
        for (size_t i = 0; i < n; i++)
            memory[i] = b;
    }

    return s;
}
