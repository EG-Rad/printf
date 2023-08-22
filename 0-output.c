#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_char - Handles the %c conversion specifier
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 */

void handle_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * handle_string - Handles the %s conversion specifier
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 */

void handle_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		write(1, s, 1);
		s++;
		(*count)++;
	}
}

/**
 * handle_percent - Handles the %% conversion specifier
 * @count: Pointer to the count of characters printed
 */

void handle_percent(int *count)
{
	write(1, "%", 1);
	(*count)++;
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					handle_char(args, &count);
					break;
				case 's':
					handle_string(args, &count);
					break;
				case '%':
					handle_percent(&count);
					break;
				default:
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

