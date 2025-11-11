#include "main.h"
#include <stdlib.h>
/**
* alloc_grid - returns a pointer to a 2 dimensional array of integers.
* @width: integer largeur 
* @height: integer hauteur
* 
* Return: return au pointeur ou null si erreur 
*/

// creation de tableau a double dimention 
int **alloc_grid(int width, int height)
{
	int **grid; //pointeur vers un tableau de pointeurs vers int
	int i, j;

	// verifie que les dimensions ne soit pas egales a 0
	if (width <= 0 || height <= 0)
		retrun (NULL);

	// alloue de la memoire au tableau principal
	grid = malloc(height * sizeof(int *));
		if (grid == NULL)
			return (NULL);

	// remplit les case avce un ligne 
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]); // libere les lignes creer 
			free(grid); // libere let ableau principale 

			return (NULL);
		}
	}
	return (grid);
}