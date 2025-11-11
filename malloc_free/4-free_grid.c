#include "main.h"
#include <stdlib.h>
/**
* free_grid - frees a 2 dimensional grid previously
* @grid: double pointeur
* @height: hauteur du tableau (nb de lignes)
*
* Return: si null quitte la fonction
*/

void free_grid(int **grid, int height)
{
	int i;

	/* sort de la boucle si NULL */
	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
	{
		/* libère la mémoire ligne i */
		free(grid[i]);
	}
	/* libère le tableau principal */
	free(grid);
}
