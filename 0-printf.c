#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - This function produces its output according to a format
 * @format: A parameter
 *
 * Return: Always 0. (Success)
 */

int _printf(const char *format, ...)
{
int i, j;
i = 0;
va_list ap;
char *str = NULL;

va_start(ap, format);

while (format[i] != '\0')
{

if (format[i] != '%')
{
_putchar(format[i]);
i++;
}
else
{
if (format[i + 1] == 'c')
{
i++;
_putchar(va_arg(ap, int));
i++;
}

else if (format[i + 1] == 's')
{
i++;
str = va_arg(ap, char *);
j = 0;
while (str[j] != '\0')
{
_putchar(str[j]);
j++;
}
}
}

}

va_end(ap);

return (0);
}
