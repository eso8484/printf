#include "main.h"
/**
 * _printf - To implement the standard library printf function
 * @format: format string
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
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
		format++;
	}
	va_end(args);
	return (counter);
}
