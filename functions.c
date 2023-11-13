#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_character - prints a character
 * @args: character to print
 * Return: number of characters printed
 */
int print_character(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: string to print
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		len++;
		s++;
	}
	return (len);
}

/**
 * print_percent - prints a percent sign
 * @args: percent sign to print
 * Return: number of characters printed
*/
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
/**
 * additional_process_format - checks if format is valid
 *
 * @format: format string
 * @args: list of arguments
 * @print: number of characters printed
 * Return: number of characters printed
*/
int additional_process_format(const char **format, va_list args, int print)
{
	if (**format == 'S')
		print += print_custom_string(args);
	else if (**format == 'p')
		print += print_p(args);
	else if (**format == 'r')
		print += print_r(args);
	else
		{
			write(1, "%", 1);
			write(1, *format, 1);
			print += 2;
		}
	return (print);
}
/**
 * process_format - checks if format is valid
 *
 * @format: format string
 * @args: list of arguments
 * Return: number of characters printed
*/
int process_format(const char **format, va_list args)
{
	int print = 0;

	if (**format != '%' || *(*format - 1) == '%')
	{
		if (write(1, *format, 1) == -1)
		{
			va_end(args);
			return (-1);
		}
		print++;
	}
	else
	{
		(*format)++;
		if (**format == '\0')
			return (print);
		if (**format == 'c')
			print += print_character(args);
		else if (**format == 's')
			print += print_string(args);
		else if (**format == '%')
			print += print_percent(args);
		else if (**format == 'd' || **format == 'i')
			print += print_integer(args);
		else if (**format == 'b')
			print += print_bin(args);
		else if (**format == 'u')
			print += print_unsigned_integer(args);
		else if (**format == 'o')
			print += print_octal(args);
		else if (**format == 'x')
			print += print_lowercase_hexadecimal(args);
		else if (**format == 'X')
			print += print_uppercase_hexadecimal(args);
		else
		{
			print = additional_process_format(format, args, print);
		}
	}
	return (print);
}
