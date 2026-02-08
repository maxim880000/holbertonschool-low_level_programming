#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - affiche des nombres séparés par un séparateur
 * @separator: séparateur entre les nombres
 * @n: nombre de paramètres
 *
 * - Utilise va_list pour parcourir les arguments variadiques.
 *
 * Return: rien
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i = 0;
	va_list boite; /* curseur pour les arguments variadiques */
	int stock;     /* stocke chaque nombre */

	if (n == 0)    /* aucun argument → juste un saut de ligne */
	{
		printf("\n");
		return;
	}

	va_start(boite, n); /* initialise le curseur à n */

	for (i = 0; i < n; i++)
	{
		stock = va_arg(boite, int); /* récupère le prochain int */

		if (i > 0 && separator != NULL) /* séparateur entre les nombres */
			printf("%s", separator);

		printf("%d", stock); /* affiche le nombre */
	}

	va_end(boite); /* termine l'utilisation de la liste */
	printf("\n");  /* saut de ligne final */
}
