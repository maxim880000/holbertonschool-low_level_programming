#include "main.h"

/* Affiche une chaîne de caractères à l’envers, suivie d’un retour à la ligne */

/**
 * print_rev - affiche une chaîne à l'envers
 * @s: pointeur vers la chaîne à afficher
 */
void print_rev(char *s)
{
	int i = 0;

	/* Trouve la longueur de la chaîne */
	while (s[i] != '\0')
		i++;

	/* Parcourt la chaîne à l'envers et affiche chaque caractère */
	for (i--; i >= 0; i--)
		_putchar(s[i]);

	/* Ajoute un retour à la ligne à la fin */
	_putchar('\n');
}
