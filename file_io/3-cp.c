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
 * close_fd - closes file descriptor safely
 * @fd: file descriptor
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
 * open_files - opens both files and validates readability
 * @file_from: source filename
 * @file_to: destination filename
 * @fd_from: pointer to source descriptor
 * @fd_to: pointer to destination descriptor
 */
void open_files(const char *file_from, const char *file_to,
		int *fd_from, int *fd_to)
{
	char test_buf[1];
	ssize_t r;

	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	/* test read before opening file_to */
	r = read(*fd_from, test_buf, 0);
	if (r == -1)
	{
		close_fd(*fd_from);
		error_exit(98, "Error: Can't read from file %s\n", file_from);
	}

	*fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		close_fd(*fd_from);
		error_exit(99, "Error: Can't write to %s\n", file_to);
	}
}

/**
 * copy_file - performs the actual copy operation
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(int fd_from, int fd_to,
	       const char *file_from, const char *file_to)
{
	ssize_t r, w;
	char buf[1024];

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			error_exit(99, "Error: Can't write to %s\n", file_to);
		}
	}
	if (r == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", file_from);
	}
}

/**
 * main - entry point: validates args and runs copy process
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(argv[1], argv[2], &fd_from, &fd_to);
	copy_file(fd_from, fd_to, argv[1], argv[2]);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
