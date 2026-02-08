#include "main.h"
#include <stdlib.h>

/* Crée un tableau 2D (grid) alloué dynamiquement et initialise tout à 0 */

/**
 * alloc_grid - retourne un pointeur vers un tableau à deux dimensions
 * @width: largeur du tableau (nombre de colonnes)
 * @height: hauteur du tableau (nombre de lignes)
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

		/* Si malloc échoue, libère toute la mémoire déjà allouée */
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		/* Initialise chaque case à 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	/* Retourne le pointeur vers le tableau 2D */
	return (grid);
}
