#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - affiche n'importe quoi selon le format
 * @format: liste des types : c=char, i=int, f=float, s=string
 *
 * - Utilise va_list pour parcourir les arguments variadiques.
 *
 * Return: rien
 */
void print_all(const char * const format, ...)
{
	va_list boite;         /* boîte pour récupérer les arguments */
	unsigned int i = 0;    /* position dans la chaîne format */
	char *stock;           /* pour stocker une string */

	va_start(boite, format);   /* ouvre la boîte après format */

	if (format) /* si format existe */
	{
		while (format[i]) /* tant qu'on n'est pas à la fin */
		{
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
					printf("%s", stock ? stock : "(nil)"); /* NULL → (nil) */
					break;
			}

			/* virgule si encore un élément et type valide */
			if (format[i + 1] && (format[i] == 'c' || format[i] == 'i' ||
					      format[i] == 'f' || format[i] == 's'))
				printf(", ");

			i++; /* passer au caractère suivant */
		}
	}

	printf("\n");     /* saut de ligne final */
	va_end(boite);     /* ferme la boîte */
}
