#include <stdio.h>
#include "main.h"

/* Affiche un échiquier 8x8 */

/**
 * print_chessboard - affiche un tableau 8x8 de caractères
 * @a: pointeur vers un tableau 2D 8x8 de caractères
 */
void print_chessboard(char (*a)[8])
{
	int x, y;

	/* Parcourt chaque ligne de l’échiquier */
	for (x = 0; x < 8; x++)
	{
		/* Parcourt chaque colonne de la ligne courante */
		for (y = 0; y < 8; y++)
		{
			/* Affiche le caractère courant */
			_putchar(a[x][y]);
		}

		/* Retour à la ligne après chaque ligne de l’échiquier */
		_putchar('\n');
	}
}
