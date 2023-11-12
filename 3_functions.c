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
    int h = va_arg(args, unsigned int);
    int i = 0, temp = h, size = 0, len;
	char *s;

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
		s[--i] = h % 10 + '0';
		h /= 10;
		size--;
	}
	len = strlen(s);
	if (write(1, s, len) == -1)
	{
		free(s);
		return (0);
	}
	free(s);
	return (len);
}
