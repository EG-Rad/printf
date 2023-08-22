#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_int - Handles the %d and %i conversion specifiers.
 * @args: The va_list containing the argument.
 * @printed_chars: A pointer to the printed_chars count.
 */
void handle_int(va_list args, int *printed_chars)
{
	int num = va_arg(args, int);

	if (num < 0)
	{
		write(1, "-", 1);
		(*printed_chars)++;
		num = -num;
	}
	int temp = num;
	int num_digits = 0;

	do {
		temp /= 10;
		num_digits++;
	} while (temp != 0);
	temp = num;
	char digit;

	while (num_digits > 0)
	{
		int divisor = 1;

		for (int i = 1; i < num_digits; i++)
		{
			divisor *= 10;
		}
		digit = (temp / divisor) + '0';
		write(1, &digit, 1);
		(*printed_chars)++;
		temp %= divisor;
		num_digits--;
	}
}

