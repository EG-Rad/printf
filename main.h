#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
void handle_int(va_list args, int *printed_chars);

#endif /* MAIN_H */
