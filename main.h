#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_character(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int process_format(const chat **format, va_list args);

#endif /*_MAIN_H*/