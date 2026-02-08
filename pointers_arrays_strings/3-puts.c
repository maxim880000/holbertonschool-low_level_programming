#include "main.h"

/* Affiche une chaîne de caractères suivie d’un retour à la ligne */

/**
 * _puts - affiche une chaîne de caractères
 * @str: pointeur vers la chaîne à afficher
 *
 * Parcourt la chaîne jusqu'au caractère de fin '\0'
 */
void _puts(char *str)
{
	int i;

	i = 0;

	/* Parcourt chaque caractère de la chaîne */
	while (str[i] != '\0')
	{
		/* Affiche le caractère courant */
		_putchar(str[i]);
		i++;
	}

	/* Ajoute un retour à la ligne à la fin */
	_putchar('\n');
}
