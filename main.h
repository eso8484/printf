#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int* buff_ind);
int _printf(const char *format, ...);
int _putchar(char c);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[], int flags, int width, int precision, int size);


#endif
