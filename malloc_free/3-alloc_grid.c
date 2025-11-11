#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - retourne un pointeur vers un tableau à deux dimensions
 * @width: largeur du tableau (nb de colonnes)
 * @height: hauteur du tableau (nb de lignes)
 *
 * Return: pointeur vers le tableau, ou NULL si erreur
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	/* Vérifie que la largeur et la hauteur sont valides */
	if (width <= 0 || height <= 0)
		return (NULL);

	/* Alloue de la mémoire pour les lignes (tableau de pointeurs) */
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	/* Alloue la mémoire pour chaque ligne */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));

		/* Si malloc échoue on libère tout */
		if (grid[i] == NULL)
		{
			/* Libère chaque ligne déjà allouée */
			for (j = 0; j < i; j++)
				free(grid[j]);

			/* Libère le tableau principal */
			free(grid);

			return (NULL);
		}

		/* Initialise tout à 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	/* return pointer */
	return (grid);
}
