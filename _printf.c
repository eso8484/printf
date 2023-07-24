#include "main.h"

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);

/**
  * _putchar - Prints character
  * @c: The character to be printed
  * Return: Character
  */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
* _printf - Prints the characters and strings
* @format: The constant of format specifiers
* Return: The number of thing printed(counter)
*/
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
return (counter);
}
/**
* print_char - For printing just a single character
* @args: The arguments taken
* Return: A character
*/
int print_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}
/**
* print_string - Prints the long strong
* @args: The range of character it takes
* Return: The string or -1 when unsuccessful
*/
int print_string(va_list args)
{
char *str = va_arg(args, char*);
if (str == NULL)
{
return (-1);
}
return (write(1, str, strlen(str)));
}
