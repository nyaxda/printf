#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_char_hex - prints a character in uppercase hexadecimal
 * 
 * @c: character to print
 * 
 * Return: number of characters printed
 */
void print_char_as_hex(unsigned char c)
{
    char *hex_digits = "0123456789ABCDEF";
    write(1, &hex_digits[c / 16], 1);
    write(1, &hex_digits[c % 16], 1);
}

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
			print_char_as_hex((unsigned char)*s);
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
