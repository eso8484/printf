#include "main.h"
/**
  * _printf - Prints the characters and strings
  * @format - the constant of format specifiers
  * Return - Thenumber of thing printed
  */

typedef struct _print
{
    char op;
    int (*fptr)(va_list);
} get_op;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
    int counter = 0;
    va_list list;
    va_start(list, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%')
            {
                _putchar('%');
            }
            else
            {
                get_op oper[] = {
                    {'c', print_char},
                    {'s', print_string},
                    {'\0', NULL}
                };

                int i = 0;
                while (oper[i].op != '\0')
                {
                    if (oper[i].op == *format)
                    {
                        int result = oper[i].fptr(list);
                        if (result < 0)
                            return (-1);
                        counter++;
                        break;
                    }
                    i++;
                }
            }
        }
        else
        {
            _putchar(*format);
        }
        format++;
    }

    va_end(list);
    return (counter;)
}

int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}

int print_string(va_list args)
{
    char *str = va_arg(args, char*);
    if (str == NULL)
    {
        return (-1);
    }
    return (write(1, str, strlen(str)));
}
