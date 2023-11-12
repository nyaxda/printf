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
	int h = va_arg(args, int), i = 0, temp = h, size = 0, j, len, is_negative;
	ssize_t bytes;
	char *s;

	while (temp != 0)
	{
		temp /= 10;
		size++;
	}

	s = malloc((size + 2) * sizeof(char));
	if (s == NULL)
	{
		return (0);
	}
	if (h < 0)
	{
		h = -h;
		is_negative = 1;
	}
	else if (h == 0)
	{
		write(1, "0", 1);
		free(s);
		return (1);
	}
	while (size > 0)
	{
		s[i++] = h % 10 + '0';
		h /= 10;
		size--;
	}
	s[i] = '\0';
	len = i;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	if (is_negative)
	{
		for (i = len; i >= 0; i--)
			s[i + 1] = s[i];
		s[0] = '-';
		len++;
	}
	bytes = write(1, s, len);
	if (bytes == -1)
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
	int print = 0, prev = 0;
	va_list args;
	ssize_t bytes;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%' || prev)
		{
			bytes = write(1, format, 1);
			if (bytes == -1)
				{
					va_end(args);
					return (-1);
				}
			print++;
			prev = 0;
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
				write(1, "%", 1);
				write(1, format, 1);
				print += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (print);
}
