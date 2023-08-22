#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
void print_int(int n);
void handle_char(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_percent(int *count);


#endif /* MAIN_H */
