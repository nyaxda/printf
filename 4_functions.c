#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_custom_string - prints a string except for non-printable characters
 *
 * Description: prints a string except for non-printable characters.
 * The non-printable characters are printed as \x followed by their ASCII code
 *
 * @S: string to print
 *
 * Return: number of characters printed
 */
int print_custom_string(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (*s != '\0' && *s != '\n')
	{
		if (*s < 32 || *s >= 127)
		{
			write (1, "\\x", 2);
			print_uppercase_hexadecimal(*s);
			len += 4;

		}
		else
		{
			write(1, s, 1);
			len++;
		}
		s++;
	}
	return (len);
}
