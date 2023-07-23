#include "main.h"

/**
* _printf - To implement the standard library printf function
* @format: format string
* Return: number of character
*/

int _printf(const char *format, ...)
{
	int count = 0;

	while(*format)
	{
		if (*format == '%')
		
			{
				format++;
				if(*format == '%s')
				{
					_putchar
				}

			}
	}


}
