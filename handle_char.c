#include "main.h"
#include <unistd.h>

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
