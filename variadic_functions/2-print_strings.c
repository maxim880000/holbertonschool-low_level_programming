#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - affiche des strings avec un séparateur
 * @separator: texte entre les strings (ex: ", ") → peut être NULL
 * @n: nombre de strings à afficher
 *
 * - Utilise va_list pour parcourir les arguments variadiques.
 *
 * Return: rien
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i = 0;
	va_list boite;
	char *stock; /* stocke chaque string récupérée */

	va_start(boite, n); /* initialise la boîte après n */

	for (i = 0; i < n; i++)
	{
		stock = va_arg(boite, char *); /* récupère la prochaine string */

		if (stock == NULL)               /* string NULL → affiche (nil) */
			printf("(nil)");
		else
			printf("%s", stock);        /* affiche la string */

		if (i < n - 1 && separator != NULL) /* séparateur entre les strings */
			printf("%s", separator);
	}

	va_end(boite); /* termine l'utilisation de la boîte */
	printf("\n");  /* saut de ligne final */
}
