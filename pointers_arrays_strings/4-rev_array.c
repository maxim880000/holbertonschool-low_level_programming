#include "main.h"

/* Inverse le contenu d’un tableau d’entiers */

/**
 * reverse_array - inverse les éléments d’un tableau
 * @a: pointeur vers le premier élément du tableau
 * @n: nombre d’éléments dans le tableau
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i, temp;

	/* Parcourt la moitié du tableau */
	for (i = 0; i < n / 2; i++)
	{
		/* Échange l’élément i avec son symétrique à la fin */
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}
