#include "main.h"

/**
 * print_square - Imprime un carré de dièses.
 * @size: La taille (côté) du carré.
 *
 * Description: Utilise des boucles imbriquées pour imprimer un carré
 * de 'size' lignes et 'size' colonnes. Si 'size' est 0 ou négatif,
 * imprime seulement un retour à la ligne.
 */
void print_square(int size)
{
	int ligne;
	int col;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (ligne = 0; ligne < size; ligne++)
		{
			for (col = 0; col < size; col++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
