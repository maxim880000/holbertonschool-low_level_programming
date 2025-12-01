#include <stdio.h>
#include "main.h"
/**
 * _print_rev_recursion - prints a string in reverse.
 * @s: pointeur
 *
 * Return:
 */

void _print_rev_recursion(char *s)
{
	if (s[0] == '\0')              // Cas de base : fin de la chaîne
		return;                    // On arrête la récursion

	_print_rev_recursion(s + 1);   // Appel récursif sur le reste de la chaîne
	_putchar(s[0]);                // Affiche le caractère courant (après retour)
}
