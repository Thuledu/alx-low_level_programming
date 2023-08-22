#include <unistd.h>
#include "main.h"
/**
 * _putchar: writes char a to stdout.
 * @a: the char that will print.
 * return: 0 (Success)
 */
int _putchar(char a)
{
        return (write(1, &a, 1));
}
