#include "main.h"
#include <stdio.h>

/* Affiche les n premiers éléments d'un tableau d'entiers */

/**
 * print_array - affiche n éléments d'un tableau
 * @a: pointeur vers le début du tableau
 * @n: nombre d'éléments à afficher
 *
 * Les éléments sont séparés par une virgule et un espace,
 * suivis d'un saut de ligne à la fin
 */
void print_array(int *a, int n)
{
	int i;

	/* Parcourt chaque élément du tableau jusqu'à n */
	for (i = 0; i < n; i++)
	{
		/* Affiche l'élément courant */
		printf("%d", a[i]);

		/* Ajoute une virgule et un espace sauf après le dernier élément */
		if (i < (n - 1))
		{
			printf(", ");
		}
	}

	/* Retour à la ligne à la fin */
	printf("\n");
}
