#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - affiche tous les arguments selon le format
 * @format: types des arguments (c = char, i = int, f = float, s = string)
 */
void print_all(const char * const format, ...)
{
	va_list boite;          /* boîte pour les arguments variadiques */
	int i = 0;              /* position dans la chaîne format */
	int check = 1;          /* 1 = premier élément → pas de virgule */
	char *str;              /* pour récupérer les strings */

	va_start(boite, format);    /* ouvre la boîte */

	if (format == NULL)         /* si format est NULL */
	{
		printf("\n");           /* affiche juste un retour à la ligne */
		va_end(boite);
		return;
	}

	while (format[i] != '\0')   /* tant qu'il y a des caractères dans format */
	{
		switch (format[i])
		{
		case 'c':               /* caractère */
			if (check == 0)     /* si on a déjà affiché quelque chose */
				printf(", ");
			printf("%c", va_arg(boite, int));
			check = 0;          /* on a affiché un truc */
			break;

		case 'i':               /* entier */
			if (check == 0)
				printf(", ");
			printf("%d", va_arg(boite, int));
			check = 0;
			break;

		case 'f':               /* float */
			if (check == 0)
				printf(", ");
			printf("%f", va_arg(boite, double));
			check = 0;
			break;

		case 's':               /* string */
			if (check == 0)
				printf(", ");
			str = va_arg(boite, char *);
			if (str == NULL)    /* si la string est NULL */
				printf("(nil)");
			if (str != NULL)    /* si la string existe */
				printf("%s", str);
			check = 0;
			break;
			/* autres caractères → ignorés automatiquement */
		}
		i++;
	}

	va_end(boite);              /* ferme la boîte */
	printf("\n");               /* saut de ligne final */
}
