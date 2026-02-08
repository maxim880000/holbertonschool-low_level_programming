#include "main.h"
#include <stdlib.h>

/* Libère un tableau 2D créé dynamiquement par alloc_grid */

/**
 * free_grid - libère la mémoire d'un tableau 2D
 * @grid: double pointeur vers le tableau
 * @height: hauteur du tableau (nombre de lignes)
 *
 * Return: rien
 */
void free_grid(int **grid, int height)
{
	int i;

	/* Si le tableau est NULL, on ne fait rien */
	if (grid == NULL)
		return;

	/* Libère chaque ligne du tableau */
	for (i = 0; i < height; i++)
		free(grid[i]);

	/* Libère le tableau principal */
	free(grid);
}
