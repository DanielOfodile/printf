#include "main.h"
#include <stdlib.h>

/**
  * _print_fmt - Prints a format
  * @format: The format to print
  * @args: A list of variadic arguments
  *
  * Return: The length of the format displayed.
  */
int _print_fmt(const char *format, va_list args)
{
	int num = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			i++;

			while (format[i] == ' ')
				i++;

			if (format[i] == '%')
				num += _putchar(format[i]);

			if (_validate_char(format[i]) == 0)
			{
				num = _print_invalid_spec(format[i - 1], format[i], num);
			}
			else
			{
				num += _print_spec(format[i], args);
			}
		}
		else
		{
			num += _putchar(format[i]);
		}

		i++;
	}

	return (num);
}

/**
  * _print_spec - Prints a valid specifier
  * @format: The specifier to print
  * @args: A list of variadic arguments
  *
  * Return: The length of the specifier displayed.
  */
int _print_spec(char format, va_list args)
{
	int i  = 0, displayed = 0;
	spc_dt _types[] = {
		{"c", _print_char},
		{"s", _print_str},
		{"d", _print_int},
		{"i", _print_int},
		{"b", _print_int_binary},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		if (*_types[i].specifier == format)
			displayed = _types[i].f(args);

		i++;
	}

	return (displayed);
}

/**
  * _print_invalid_spec - Prints an invalid specifier
  * @prev_format: The previous specifier of actual specifier
  * @format: The specifier to print
  * @num: The current count before prints invalid specifiers
  *
  * Return: The current count after prints invalid specifiers
  */
int _print_invalid_spec(char prev_format, char format, int num)
{
	num += _putchar('%');

	if (prev_format == ' ')
	{
		num += _putchar(' ');
		num += _putchar(format);
	}
	else
	{
		num += _putchar(format);
	}

	return (num);
}

/**
  * _validate_char - validate the type.
  * @_type: character to be compared.
  *
  * Return: 1 if char is equal to a type
  */
int _validate_char(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int i = 0;

	while (_types[i])
	{
		if (_types[i] == _type)
			return (1);
		i++;
	}
	return (0);
}
