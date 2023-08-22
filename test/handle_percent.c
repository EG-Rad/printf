#include "main.h"
#include <unistd.h>

/**
 * handle_percent - Handles the %% conversion specifier
 * @count: Pointer to the count of characters printed
 */
void handle_percent(int *count)
{
	write(1, "%", 1);
	(*count)++;
}
