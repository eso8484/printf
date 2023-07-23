#include "main.h"

/**
* _printf - To implement the standard library printf function
* @format: format string
* @...: The variable arguments
* Return: number of character
*/

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int counter = 0;


	while(*format)
	{
		if (*format == '%')
		
			{
				format++;
				if(*format == '%')
				{
					_putchar('%');
					counter++;
				}
				else if (*format == 'c')
				{
					int _c = va_arg(args, int);
					_putchar(_c);
					counter++;
				}
				else if (*format == 's')
				{
					char *str = va_arg(args, char *);
					while (*str)
					{
						_putchar(*str);
						str++;
						counter++;
					}
				}

			}
		else
		{
			_putchar(*format);
			counter++;
		}
		format++;

	}
	va_end(args);
	return (counter);
}
