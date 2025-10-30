#include "main.h"

/**
 * print_square - Imprime un carré de dièses, suivi d'une nouvelle ligne.
 * @size: La taille (côté) du carré.
 *
 * Description: La fonction utilise des boucles imbriquées pour imprimer
 * un carré de 'size' lignes et 'size' colonnes.
 * Si 'size' est 0 ou négatif, la fonction imprime seulement
 * un retour à la ligne.
 */
void print_square(int size)
{
	int ligne; /* Compteur pour les lignes (vertical) */
	int col;   /* Compteur pour les colonnes (horizontal) */

	/* 1. Gérer le cas spécial où size est 0 ou négatif */
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		/* 2. Boucle Extérieure : s'occupe des lignes */
		for (ligne = 0; ligne < size; ligne++)
		{
			/* 3. Boucle Intérieure : s'occupe des colonnes */
			/* Pour chaque ligne, on imprime 'size' dièses */
			for (col = 0; col < size; col++)
			{
				_putchar('#');
			}

			/* 4. Fin de la ligne */
			/* Une fois tous les dièses de la ligne imprimés, */
			/* on passe à la ligne suivante. */
			_putchar('\n');
		}
	}
}
