#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_exit - prints error message and exits
 * @code: exit code
 * @msg: message format
 * @arg: string argument (file name)
 */
void error_exit(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd - safely closes a file descriptor
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies content from one file to another
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t r_bytes, w_bytes;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		error_exit(99, "Error: Can't write to %s\n", file_to);
	}

	while ((r_bytes = read(fd_from, buffer, 1024)) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			error_exit(99, "Error: Can't write to %s\n", file_to);
		}
	}

	if (r_bytes == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", file_from);
	}

	close_fd(fd_from);
	close_fd(fd_to);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);
	return (0);
}
