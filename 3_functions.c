#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_unsigned_integer - prints an unsigned integer
 * @args: unsigned integer to print
 * Return: number of characters printed
 */
int print_unsigned_integer(va_list args)
{
	unsigned int h = va_arg(args, unsigned int), temp = h;
	int i, size = 0, len;
	char *s;

	if (h == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
	{
		return (0);
	}
	if (h == 0)
	{
		write(1, "0", 1);
		free(s);
		return (1);
	}
	i = size;
	s[i] = '\0';
	while (size > 0)
	{
		i--;
		s[i] = (h % 10) + '0';
		h /= 10;
		size--;
	}
	len = strlen(s);
	if (write(1, s, len ) == -1)
	{
		free(s);
		return (0);
	}
	free(s);
	return (len);
}

/**
 * print_octal - prints an octal
 * @args: octal to print
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp = n;
	int size = 0;
	char *s;
	int i;

	if (n == 0)
	{
		write(1, "0", 1);
		return 1;
	}

	while (temp != 0)
	{
		temp /= 8;
		size++;
	}

	s = malloc(size + 1);
	if (s == NULL)
	{
		return 0;
	}

	s[size] = '\0';
	for (i = size - 1; i >= 0; i--)
	{
		s[i] = (n % 8) + '0';
		n /= 8;
	}

	i = write(1, s, size);
	free(s);

	return i;
}
