#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - affiche n'importe quoi selon le format
 * @format: liste des types : c=char, i=int, f=float, s=string
 * 
 * Return: nothing 
 */
void print_all(const char * const format, ...)
{
	va_list boite;             /* boîte  pour récupérer les argmt */
	unsigned int i = 0;     /* position dans la chaîne format */
	char *stock;                /* pour stocker une string */

	va_start(boite, format);   /* on ouvre la boîte à argmt */

	if (format)             /* si format existe (pas NULL) */
	{
		while (format[i])   /* tant qu'on n'est pas à la fin de format */
		{
			switch (format[i])          /* on regarde quel type on doit afficher */
			{
				case 'c':                           /* si la lettre est 'c' → on affiche un char */
					printf("%c", va_arg(boite, int));  /* on affiche le char */
					break;					/* break = on sort du switch, on arrête ici */

				case 'i':                           /* entier */
					printf("%d", va_arg(boite, int));  /* on affiche l'entier */
					break;

				case 'f':                           /* float */
					printf("%f", va_arg(boite, double)); /* on affiche le float */
					break;

				case 's':                           /* string */
					stock = va_arg(boite, char *);         /* on récupère la string met dans stock */
					printf("%s", stock ? stock : "(nil)");  /* si NULL → (nil), sinon la string */
					break;
					/* autres ignorées */
			}

			/* on met une virgule SEULEMENT si y'a encore un truc après */
			/* ET que le caractère actuel était bon (c, i, f ou s) */
			if (format[i + 1] && (format[i] == 'c' || format[i] == 'i' ||
					      format[i] == 'f' || format[i] == 's'))
				printf(", ");

			i++;    /* on passe au caractère suivant */
		}
	}

	printf("\n");       /* saut de ligne à la fin */
	va_end(boite);         /* on ferme la boîte */
}
