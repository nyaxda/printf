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
	while (*s != '\0')
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

/**
 * print_p - prints a pointer address
 * @args: pointer address to print
 * Return: number of characters printed
*/
int print_p(va_list args)
{
	unsigned long int p = va_arg(args, unsigned long int);
	unsigned long int temp = p;
	int size = 0;
	char *s;
	int i;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return 5;
	}

	while (temp != 0)
	{
		temp /= 16;
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
		s[i] = "0123456789abcdef"[p % 16];
		p /= 16;
	}

	i = write(1, "0x", 2);
	i += write(1, s, size);
	free(s);

	return i;
}

/**
 * print_r - prints reversed string
 * @args: string to print
 * Return: number of characters printed
*/
int print_r(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (s[len] != '\0')
	{
		len++;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		write(1, &s[i], 1);
	}

	return len;
}
