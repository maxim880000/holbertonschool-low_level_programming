#include "main.h"
#include <stdio.h>

/* Affiche la somme des deux diagonales d’une matrice carrée */

/**
 * print_diagsums - calcule et affiche la somme des diagonales
 * @a: pointeur vers le premier élément de la matrice
 * @size: taille de la matrice carrée (n x n)
 *
 * Return: rien
 */
void print_diagsums(int *a, int size)
{
	int i, b = 0, c = 0;

	/* Parcourt chaque ligne de la matrice */
	for (i = 0; i < size; i++)
	{
		/* Somme de la diagonale principale */
		b += *(a + i * size + i);

		/* Somme de la diagonale secondaire */
		c += *(a + i * size + (size - 1 - i));
	}

	/* Affiche les deux sommes séparées par une virgule */
	printf("%d, %d\n", b, c);
}
