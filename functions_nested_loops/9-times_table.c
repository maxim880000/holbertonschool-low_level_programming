#include "main.h"

/**
 * times_table - Affiche la table de multiplication de 9, en commençant par 0.
 *
 * Return: void
 */
void times_table(void)
{
	int i, j, product;

	/* Boucle sur les lignes de 0 à 9 */
	for (i = 0; i <= 9; i++)
	{
		/* Boucle sur les colonnes de 0 à 9 */
		for (j = 0; j <= 9; j++)
		{
			/* Calcule le produit de i et j */
			product = i * j;

			/* Premier chiffre de chaque ligne est toujours 0 */
			if (j == 0)
				_putchar('0');
			else
			{
				/* Séparateur entre les valeurs */
				_putchar(',');
				_putchar(' ');

				/* Ajoute un espace pour les nombres à un chiffre */
				if (product < 10)
					_putchar(' ');
				else
					/* Affiche le chiffre des dizaines */
					_putchar((product / 10) + '0');

				/* Affiche le chiffre des unités */
				_putchar((product % 10) + '0');
			}
		}
		/* Passe à la ligne suivante après chaque ligne */
		_putchar('\n');
	}
}
