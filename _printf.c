#include "main.h"
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int counter, print = 0, i = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while(format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			counter++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			print = takeallprints(format, &i, list, buffer);
			if (print == -1)
				return (-1);
			counter = print + counter;
		}
		i++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (counter);
}
