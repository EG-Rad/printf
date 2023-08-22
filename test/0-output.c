#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function with limited format specifiers.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    const char *p = format;

    va_start(args, format);

    while (*p)
    {
        if (*p == '%')
        {
            p++;

            if (*p == 'c')  
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*p == 's') 
            {
                char *s = va_arg(args, char *);
                while (*s)
                {
                    write(1, s, 1);
                    s++;
                    printed_chars++;
                }
            }
            else if (*p == '%')  
            {
                write(1, p, 1);
                printed_chars++;
            }
        }
        else
        {
            write(1, p, 1);
            printed_chars++;
        }

        p++;
    }

    va_end(args);

    return (printed_chars);
}
