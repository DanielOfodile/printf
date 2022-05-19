#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - personalised printf function.
 * @format: string to be printed.
 *
 * Return: number of chars that print
 */
int _printf(const char *format, ...)
{
	va_list args;
	int displayed = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	displayed = _print_fmt(format, args);
	va_end(args);
	return (displayed);
}
