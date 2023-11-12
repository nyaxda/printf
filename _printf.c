#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

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
		int result = process_format(&format, args);

		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		print += result;
		format++;
	}
	va_end(args);
	return (print);
}
