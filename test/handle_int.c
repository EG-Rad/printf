#include "main.h"

/**
 * handle_int - Handles the %d and %i conversion specifiers
 * @args: The argument list
 * @count: Pointer to the count of characters printed
 */
void handle_int(va_list args, int *count)
{
	int d = va_arg(args, int);

	print_int(d);

	if (d < 0)
		d = -d;
	while (d > 0)
	{
		d /= 10;
		(*count)++;
	}
}
