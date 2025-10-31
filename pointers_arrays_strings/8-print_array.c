#include "main.h"
#include <stdio.h> /* On inclut stdio car on a le droit d'utiliser printf */

/**
 * print_array - Affiche 'n' éléments d'un tableau d'entiers.
 * @a: Le pointeur vers le début du tableau.
 * @n: Le nombre d'éléments à afficher.
 *
 * suivis d'un saut de ligne.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		if (i < (n - 1))
		{
			printf(", ");
		}
	}

	printf("\n");
}
