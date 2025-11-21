#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - printf everything
 * @format: char pointer constant(list type argmt)
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list boite;
	int i = 0; /* pour parcourir format */
	int check = 1; /* pour ne pas avoir de virgule au depart */
	char *stock;   /* pour recuperer les strings */

	va_start(boite, format); /* nom et dernier agrmt (open boite) */

	if (format == NULL)
		{
			printf("\n"); /* rien à afficher si pas de format */
			va_end(boite); /* on ferme la boîte */
			return; /* on sort direct */
		}
	while (format[i] != '\0') /* tant qu'on est pas a la fin du string */
	{
		if (check == 0) /* affiche au moin un char avant la , */
			printf(", "); /* apres on met la virgule puis un espace */
		check = 0; /* mtn c plus le premier donc */
		switch (format[i]) /* on regarde quel type d'argument on doit afficher */
		{
		/* Définit chaque possibilité */
		/* Sans break → il continue et fait TOUS les cas suivants ! */
		case 'c': /* caractère */
			printf("%c", va_arg(boite, int));
			break;
		case 'i': /* entier */
			printf("%d", va_arg(boite, int));
			break;
		case 'f': /* float */
			printf("%f", va_arg(boite, double));
			break;
		case 's': /* string */
				stock = va_arg(boite, char *);
				/* si la string est NULL → on affiche (nil) */
				/* si j’ai une string, je la prends ; sinon je prends "(nil)" */
				printf("%s", stock ? stock : "(nil)");
				break;
		}
		i++;
	}
	va_end(boite); /* on ferme la boîte */
	printf("\n");
}
