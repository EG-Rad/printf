#include "main.h"
#include <unistd.h>

/**
 * print_int - Prints an integer
 * @n: The integer to print
 */
void print_int(int n)
{
	int divisor = 1;
	int temp = n;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		temp = n;
	}

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
