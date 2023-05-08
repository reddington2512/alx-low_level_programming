#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read a text file and print to STDOUT.
 * @filename: the text file being read
 * @letters: the number of letters to be read
 * Return: a- the actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t a;
	ssize_t c;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	c = read(fd, buf, letters);
	a = write(STDOUT_FILENO, buf, c);

	free(buf);
	close(fd);
	return (a);
}
