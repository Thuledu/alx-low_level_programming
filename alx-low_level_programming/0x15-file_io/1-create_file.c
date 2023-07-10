#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
/**
 * create_file - function that creates a file.
 * @filename: the name of file to create
 * @text_content: A text to write to a file
 * return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int d, a;
	int length = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	d = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (d == -1)
	{
		return (-1);
	}

	a = write(d, text_content, length);
	if (a == -1)
	{
		close(d);
		return (-1);
	}
	close(d);
	return (1);
}
