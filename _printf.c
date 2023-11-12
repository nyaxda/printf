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
 * print_integer - prints an integer
 * @args: integer to print
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
	int h = va_arg(args, int), i = 0, temp = h, size = 0, len;
	int is_negative = h < 0 ? 1 : 0, extra_space = (h < 0) ? 1 : 0;
	char *s, to_write[2] = {'%', *format};

	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	s = malloc((size + extra_space + 1) * sizeof(char));
	if (s == NULL)
	{
		return (0);
	}
	if (is_negative)
		h = -h;
	else if (h == 0)
	{
		write(1, "0", 1);
		free(s);
		return (1);
	}
	i = size + extra_space;
	s[i] = '\0';
	while (size > 0)
	{
		s[--i] = h % 10 + '0';
		h /= 10;
		size--;
	}
	if (is_negative)
		s[--i] = '-';
	len = strlen(s);
	if (write(1, s, len) == -1)
	{
		free(s);
		return (0);
	}
	free(s);
	return (len);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int print = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%' || *(format - 1) == '%')
		{
			if (write(1, format, 1) == -1)
			{
				va_end(args);
				return (-1);
			}
			print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				print += print_character(args);
			else if (*format == 's')
				print += print_string(args);
			else if (*format == '%')
				print += print_percent(args);
			else if (*format == 'd' || *format == 'i')
				print += print_integer(args);
			else
			{
				write(1, to_write, 2);
				print += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (print);
}
