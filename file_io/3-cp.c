#include "main.h"

/**
 * error_exit - prints error message and exits
 * @code: exit code
 * @msg: message format
 * @arg: string argument (file name or fd)
 */
void error_exit(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * copy_file - copies the content of one file to another
 * @file_from: name of the source file
 * @file_to: name of the destination file
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, r, w;
	char buf[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", file_to);
	}

	while (1)
	{
		r = read(fd_from, buf, 1024);
		if (r == -1)
		{
			close(fd_from);
			close(fd_to);
			error_exit(98, "Error: Can't read from file %s\n", file_from);
		}
		if (r == 0)
			break;

		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", file_to);
		}
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}

/**
 * main - entry point, handles arguments and calls copy_file
 * @argc: argument count
 * @argv: argument vector
 *
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

