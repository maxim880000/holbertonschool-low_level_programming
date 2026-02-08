#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - affiche n'importe quel type selon format
 * @format: liste des types : c=char, i=int, f=float, s=string
 *
 * Points clés :
 * - va_list pour parcourir les arguments variadiques
 *
 * Return: rien
 */
void print_all(const char * const format, ...)
{
	va_list boite;   /* boîte pour récupérer les arguments */
	int i = 0;       /* index dans format */
	int check = 1;   /* flag pour la virgule */
	char *stock;     /* pour stocker une string */

	va_start(boite, format); /* ouvre la boîte après format */

	if (format == NULL) /* si aucun format, rien à afficher */
	{
		printf("\n");
		va_end(boite);
		return;
	}

	while (format[i] != '\0') /* tant qu'on n'est pas à la fin */
	{
		if (check == 0) /* pas le premier élément → virgule */
			printf(", ");
		check = 0; /* désormais ce n'est plus le premier */

		switch (format[i]) /* type à afficher */
		{
			case 'c': /* char */
				printf("%c", va_arg(boite, int));
				break;

			case 'i': /* int */
				printf("%d", va_arg(boite, int));
				break;

			case 'f': /* float */
				printf("%f", va_arg(boite, double));
				break;

			case 's': /* string */
				stock = va_arg(boite, char *);
				printf("%s", stock ? stock : "(nil)");
				break;
		}
		i++;
	}

	va_end(boite); /* ferme la boîte */
	printf("\n");
}
