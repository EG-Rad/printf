#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <inttypes.h>


/**
 * print_uint - Prints an unsigned integer
 * @n: The unsigned integer to print
 */
void print_uint(unsigned int n)
{
	unsigned int divisor = 1;
	unsigned int temp = n;

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor >= 1)
	{
		temp = n / divisor + '0';
		write(1, &temp, 1);
		n %= divisor;
		divisor /= 10;
	}
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @n: The unsigned integer to print
 */
void print_octal(unsigned int n)
{
	unsigned int divisor = 1;
	unsigned int temp = n;

	while (temp > 7)
	{
		divisor *= 8;
		temp /= 8;
	}

	while (divisor >= 1)
	{
		temp = n / divisor + '0';
		write(1, &temp, 1);
		n %= divisor;
		divisor /= 8;
	}
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format
 * @n: The unsigned integer to print
 * @uppercase: Whether to use uppercase letters for A-F
 */
void print_hex(unsigned int n, int uppercase)
{
	unsigned int divisor = 1;
	unsigned int temp = n;
	char c;

	while (temp > 15)
	{
		divisor *= 16;
		temp /= 16;
	}

	while (divisor >= 1)
	{
		temp = n / divisor;
		if (temp < 10)
			c = temp + '0';
		else if (uppercase)
			c = temp - 10 + 'A';
		else
			c = temp - 10 + 'a';
		write(1, &c, 1);
		n %= divisor;
		divisor /= 16;
	}
}

/**
 * handle_uint - Handles the %u conversion specifier
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 */
void handle_uint(va_list args, int *count)
{
	unsigned int ui = va_arg(args, unsigned int);
	print_uint(ui);
	while (ui > 0)
	{
		ui /= 10;
		(*count)++;
	}
}

/**
 * handle_octal - Handles the %o conversion specifier
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 */
void handle_octal(va_list args, int *count)
{
	unsigned int ui = va_arg(args, unsigned int);
	print_octal(ui);
	while (ui > 0)
	{
		ui /= 8;
		(*count)++;
	}
}

/**
 * handle_hex - Handles the %x and %X conversion specifiers
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 * @uppercase: Whether to use uppercase letters for A-F
 */
void handle_hex(va_list args, int *count, int uppercase)
{
	unsigned int ui = va_arg(args, unsigned int);
	print_hex(ui, uppercase);
	while (ui > 0)
	{
		ui /= 16;
		(*count)++;
	}
}

/**
 * handle_pointer - Handles the %p conversion specifier
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 */

#include <inttypes.h>

/**
 * handle_pointer - Handles the %p conversion specifier
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 */
void handle_pointer(va_list args, int *count)
{
    void *addr = va_arg(args, void *);
    uintptr_t n = (uintptr_t)addr;
    int num_digits = 0;

    write(1, "0x", 2);
    print_hex(n, 0);
    while (n > 0)
    {
        n /= 16;
        num_digits++;
    }
    while (num_digits < (int)(2 * sizeof(void *)))
    {
        write(1, "0", 1);
        num_digits++;
        (*count)++;
    }
    (*count) += 2;
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
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
                case 'd':
                case 'i':
                    handle_int(args, &count);
                    break;
                case 'u':
                    handle_uint(args, &count);
                    break;
                case 'o':
                    handle_octal(args, &count);
                    break;
                case 'x':
                    handle_hex(args, &count, 0);
                    break;
                case 'X':
                    handle_hex(args, &count, 1);
                    break;
                case 'p':
                    handle_pointer(args, &count);
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

