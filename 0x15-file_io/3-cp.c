#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *create_buffer(char *file);
void file_close(int d);
/**
 * create_buff - Allocate buffer 1024 bytes
 * @file: buffer file name
 * return: pointer to new buffer
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * (1024));

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Could not write to %s\n", file);
		exit(99);
	}
	return (buff);
}

/**
 * file_close - it closes the descriptors of the file
 * @d: closed file descriptors
 */
void file_close(int d)
{
	int fc;

	fc = close(d);

	if (fc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Could not close file %d\n", d);
		exit(100);
	}
}
/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments in program
 * @argv: array of pointers
 * return: 0 (Success)
 *
 * Description of exit codes:
 * If file_to or file_from can't be closed - exit code 100.
 * If file_to can't be created or written to - exit code 99.
 * If file_from doesn't exist or can't be read - exit code 98.
 * If the argument count is incorrect - exit code 97.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, a, b;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	a = read(file_from, buff, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		b = write(file_to, buff, a);
		if (file_to == -1 || b == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		a = read(file_from, buff, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (a > 0);

	free(buff);
	file_close(file_from);
	file_close(file_to);

	return (0);
}
