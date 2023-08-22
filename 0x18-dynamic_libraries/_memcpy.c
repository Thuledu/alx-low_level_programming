#include "main.h"
#include <stdio.h>

/**
 * _memcpy - Copies a specified number of bytes from source to destination.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source buffer.
 * @n: Number of bytes to be copied.
 * Return: Pointer to the destination buffer.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    unsigned char *dest_ptr = (unsigned char *)dest;
    const unsigned char *src_ptr = (const unsigned char *)src;
    unsigned long long *wide_dest_ptr;
    const unsigned long long *wide_src_ptr;
    size_t wide_index, wide_count;

    // Copy byte-wise if n is small
    if (n < sizeof(unsigned long long))
    {
        for (size_t i = 0; i < n; i++)
            dest_ptr[i] = src_ptr[i];
    }
    else
    {
        // Copy in wide chunks
        wide_dest_ptr = (unsigned long long *)dest_ptr;
        wide_src_ptr = (const unsigned long long *)src_ptr;
        wide_count = n / sizeof(unsigned long long);
for (wide_index = 0; wide_index < wide_count; wide_index++)
            wide_dest_ptr[wide_index] = wide_src_ptr[wide_index];

        // Copy the remaining bytes byte-wise
        dest_ptr += wide_index * sizeof(unsigned long long);
        src_ptr += wide_index * sizeof(unsigned long long);
        n -= wide_index * sizeof(unsigned long long);
        for (size_t i = 0; i < n; i++)
            dest_ptr[i] = src_ptr[i];
    }

    return dest;
}
