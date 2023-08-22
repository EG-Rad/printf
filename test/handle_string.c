#include "main.h"
#include <unistd.h>

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
