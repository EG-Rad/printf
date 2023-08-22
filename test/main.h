#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void print_int(int n);
void handle_char(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_percent(int *count);
void handle_int(va_list args, int *count);

void print_uint(unsigned int n);
void print_octal(unsigned int n);
void print_hex(unsigned int n, int uppercase);
void handle_uint(va_list args, int *count);
void handle_octal(va_list args, int *count);
void handle_hex(va_list args, int *count, int uppercase);
void handle_pointer(va_list args, int *count);

#endif /* MAIN_H */
