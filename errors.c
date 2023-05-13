#include "shell.h"

/**
 * e_puts - prints an input string.
 * @str: the string to be printed.
 *
 * Return: No.
 */
void e_puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		e_putchar(str[i]);
		i++;
	}
}

/**
 * e_putchar - writes the character c to standar error.
 * @c: The character to printed.
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int e_putchar(char c)
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
 * _putfd - writes the character c.
 * @c: The character to be printed.
 * @fd: The file descriptor to write.
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putfd(char c, int fd)
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
 * _putsfd - prints an input string.
 * @str: the string to be printed.
 * @fd: the file descriptor.
 *
 * Return: the number of chars.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
