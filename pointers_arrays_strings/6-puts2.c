#include "main.h"

/* Affiche un caractère sur deux d'une chaîne */

/**
 * puts2 - affiche les caractères d'index pair d'une chaîne
 * @str: pointeur vers la chaîne à afficher
 *
 * Description: commence au premier caractère (index 0) et affiche
 * tous les caractères situés à un index pair
 */
void puts2(char *str)
{
	int i;

	i = 0;

	/* Parcourt chaque caractère de la chaîne */
	while (str[i] != '\0')
	{
		/* Si l'index est pair, on affiche le caractère */
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
		i++;
	}

	/* Retour à la ligne à la fin */
	_putchar('\n');
}
