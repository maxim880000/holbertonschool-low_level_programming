#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - calcule la somme de tous les paramètres
 * @n: nombre de paramètres
 *
 * - Utilise va_list pour parcourir les arguments variadiques.
 *
 * Return: somme de tous les paramètres
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;      /* compteur pour la boucle */
	va_list boite;       /* "curseur" pour arguments variadiques */
	int sum = 0;         /* initialisation de la somme */

	if (n == 0)          /* aucun argument → somme = 0 */
		return (0);

	va_start(boite, n);  /* initialise le curseur à n */

	for (i = 0; i < n; i++)   /* boucle sur tous les arguments */
	{
		sum += va_arg(boite, int); /* récupère le prochain int et ajoute */
	}

	va_end(boite);        /* termine l'utilisation de la liste */

	return (sum);         /* retourne la somme */
}
