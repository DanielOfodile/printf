#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _print_char - Prints a char
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */
int _print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
  * _print_str - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int _print_str(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_putchar(arg[i]);
			i++;
		}

		return (i);
	}

	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');
	return (6);
}

/**
  * _print_int - Prints an integer
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int _print_int(va_list args)
{
	int num = 1, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		_putchar('-');
		m = m * -1;
		n = m;
		num += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		num++;
	}

	_recursion_int(m);
	return (num);
}

/**
  * _recursion_int - Prints a integer
  * @a: integer to print
  *
  * Return: Nothing
  */
void _recursion_int(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
		_recursion_int(t / 10);
	_putchar(t % 10 + '0');
}
