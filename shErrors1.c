#include "shell.h"

/**
 *ePuts - func to print string input
 * @str: print string
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: void
 */
void ePuts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		ePutChar(str[i]);
		i++;
	}
}

/**
 * ePutChar - func to write char c to STDERR
 * @c: print character
 * Return: 1 (success) or -1 (error)
 */
int ePutChar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * putFd - func to write the char c to fd
 * @c: print character
 * @fd: write to file descriptor
 * Return: 1 (success) or -1 (error)
 */
int putFd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *putsFd - func to print string input
 * @str: print string
 * @fd: write to file descriptor
 * Return: number chars
 */
int putsFd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += putFd(*str++, fd);
	}
	return (i);
}
