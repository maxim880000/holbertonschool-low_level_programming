#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - affiche des strings avec un séparateur
 * @separator: texte entre les strings (ex: ", ") → peut être NULL
 * @n: nombre de strings à afficher
 *
 * Return: nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i = 0;
	va_list boite;
	char *stock; /* ici on met chaque string qu’on récupère */

	va_start(boite, n); /* on ouvre la boîte après n */

	for (i = 0; i < n; i++)
	{
		stock = va_arg(boite, char *);
		/* on récupère la prochaine string met dans stock */

		/* Si la string est NULL → on affiche (nil) */
		if (stock == NULL)
			printf("(nil)");
		else
			printf("%s", stock);

		/* On met le séparateur si n n’est pas au dernier élément */
		/* et que separator n’est pas NULL */
		if (i < n - 1 && separator != NULL)
			printf("%s", separator);
	}

	va_end(boite); /* on ferme la boîte */
	printf("\n");
}
