#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
 *  read_textfile - function that reads a text file and prints
 *  it to the POSIX standard output.
 *  @filename: the name of file to read
 *  @letters: the max number of letters to read and print
 *  return: the actual number of letters it could read and print
 *  or 0 (Error)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t br, bw;
	char *buffer;
	int d;

	if (!filename)
	{
		return (0);
	}

	d = open(filename, O_RDONLY);
	if (d == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
	{
		return (0);
	}

	br = read(d, buffer, letters);
	if (br == -1)
	{
		free(buffer);
		close(d);
		return (0);
	}

	bw = write(STDOUT_FILENO, buffer, br);
	if (bw == -1 || bw != br)
	{
		free(buffer);
		close(d);
		return (0);
	}
	free(buffer);
	close(d);
	return (bw);
}
