#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *s;

	va_start(ap, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%c", va_arg(ap, int));
					break;
				case 'i':
					printf("%d", va_arg(ap, int));
					break;
				case 'f':
					printf("%f", va_arg(ap, double));
					break;
				case 's':
					s = va_arg(ap, char *);
					printf("%s", s ? s : "(nil)");
					break;
			}
			if (format[i + 1] && (format[i] == 'c' || format[i] == 'i' ||
					      format[i] == 'f' || format[i] == 's'))
				printf(", ");
			i++;
		}
	}
	printf("\n");
	va_end(ap);
}
