#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
* print_numbers - prints numbers, followed by a new line.
* @separator: constant char
* @n: constant integer +
*
* Return: nothing
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i = 0;
	va_list boite; /* boite qui contient ... */
	int stock; /* stock chaque nb ici */

	if (n == 0)
	{
		printf("\n");
		return;
	}

	va_start(boite, n); /* on initialise le cursor a n */

	for (i = 0; i < n; i++)
	{
		/* on sort le prochain nombre de la boîte et on le met dans stock */
		stock = va_arg(boite, int);

		/* on met le separator si */
		if (i > 0 && separator != NULL)
			printf("%s", separator);

		printf("%d", stock);
	}
	va_end(boite); /* on ferme la boite */
	printf("\n"); /* saut de ligne */
}
