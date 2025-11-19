#include "variadic_functions.h"
#include <stdarg.h>
/**
* sum_them_all - returns the sum of all its parameters.
* @n: integer constant et +
*
* Return: 0 if n == 0 else sum
*/

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i; /* compteur pour la boucle */
	va_list boite; /* "curseur" pour argmt variadique */
	int sum = 0; /* on initialise la somme à 0 */

	if (n == 0) /* verifie la première conditionn*/
		return (0);

	va_start(boite, n); /* on initialise le cursor a n */

	for (i = 0; i < n; i++) /* boucle n fois */
	{
		sum += va_arg(boite, int); /* récupère le prochain int et on l'ajoute */
	}
	va_end(boite); /* marque la fin de l'use de boite */

	return (sum);
}
