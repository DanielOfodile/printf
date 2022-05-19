#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

/**
  * struct specifiers - Struct specifiers
  * @specifier: The conversion specifier
  * @f: The function pointer
  */
typedef struct specifiers
{
	char *specifier;
	int (*f)(va_list args);
} spc_dt;

int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_str(va_list args);
int _print_fmt(const char *format, va_list args);
int _print_spec(char format, va_list args);
int _print_invalid_spec(char prev_format, char format, int count);
int _print_int(va_list args);
void _recursion_int(int a);
int _print_int_binary(va_list args);

#endif /* _MAIN_H_ */
