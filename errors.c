#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char s)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(2, buf, p);
		p = 0;
	}
	if (s != BUF_FLUSH)
		buf[p++] = s;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char s, int fp)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fp, buf, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
		buf[i++] = s;
	return (1);
}

/**
 * _putsfp - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfp(char *str, int fp)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfp(*str++, fp);
	}
	return (i);
}

