#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Print a character
 * @c: The character to print
 * @count: Pointer to the count of characters printed
 */
void print_char(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * print_str - Print a string
 * @str: The string to print
 * @count: Pointer to the count of characters printed
 */
void print_str(const char *str, int *count)
{
	*count += printf("%s", str);
}

/**
 * print_int - Print an integer
 * @n: The integer to print
 * @count: Pointer to the count of characters printed
 */
void print_int(int n, int *count)
{
	*count += printf("%d", n);
}

/**
 * _printf - Custom printf function that handles %c, %s, %d, %i
 * @format: The format string
 * @...: Additional arguments based on format string
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					print_char(va_arg(args, int), &count);
					break;
				case 's':
					print_str(va_arg(args, char *), &count);
					break;
				case 'd':
				case 'i':
					print_int(va_arg(args, int), &count);
					break;
				case '%':
					print_char('%', &count);
					break;
				default:
					print_char('%', &count);
					print_char(*format, &count);
					break;
			}
		}
		else
		{
			print_char(*format, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}

