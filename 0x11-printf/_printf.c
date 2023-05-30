#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Generates an output according to a format
 * @format: A char string
 *
 * Return: Total number of chars printed but
 * exclude the null byte used to end the output to strings,
 * otherwise -1 (error)
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);
	int count = 0;
	const char *str;

	va_list args;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++; /* Move past '%' */
			switch (*format)
			{
				case 'c':
					write(1, &(va_arg(args, int)), 1);
					count++;
					break;
				case 's':
					str = va_arg(args, const char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						write(1, str, 1);
						str++;
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, "%", 1);
					count++;
					write(1, format, 1);
					count++;
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
