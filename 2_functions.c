#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int print_bin (va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
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
		i += print_bin(n / 2);
		c = (n % 2) + '0';
		write(1, &c, 1);
		return (i + 1);
	}
}
