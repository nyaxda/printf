#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_bin_helper - prints a binary
 * @n: integer to print
 * Return: number of characters printed
 */
int print_bin_helper(unsigned int n)
{
	char c;
	int i = 0;

	if (n <= 1)
	{
		c = n + '0';
		write(1, &c, 1);
		return (1);
	}
	else
	{
		i += print_bin_helper(n / 2);
		c = (n % 2) + '0';
		write(1, &c, 1);
		return (i + 1);
	}
}
/**
 * print_bin - prints a binary
 * @args: binary to print
 * Return: number of characters printed
*/
int print_bin(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_bin_helper(n));
}
