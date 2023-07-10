#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: Pointer to filename
 * @text_content: the pointer to content to append
 * return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int d, length, a;

	if (filename == NULL)
	{
		return (-1);
	}

	d = open(filename, O_WRONLY | O_APPEND);
	if (d == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (length = 0; text_content[length]; length++);

		a = write(d, text_content, length);

		if (a == -1)
		{
			close(d);
			return (-1);
		}
	}
	close(d);
	return (1);
}
