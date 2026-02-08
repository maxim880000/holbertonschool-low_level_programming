#include <stdio.h>
#include "main.h"

/* Affiche une chaîne de caractères à l’envers en utilisant la récursion */

/**
 * _print_rev_recursion - affiche une chaîne à l'envers
 * @s: pointeur vers la chaîne à afficher
 *
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	/* Cas de base : si on arrive à la fin de la chaîne, on arrête */
	if (s[0] == '\0')
		return;

	/* Appelle récursivement la fonction sur le reste de la chaîne */
	_print_rev_recursion(s + 1);

	/* Après le retour de la récursion, affiche le caractère courant */
	_putchar(s[0]);
}
