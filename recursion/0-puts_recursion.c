#include "main.h"
#include <stdio.h>

/* Affiche une chaîne de caractères en utilisant la récursion */

/**
 * _puts_recursion - affiche une chaîne suivie d'un saut de ligne
 * @s: pointeur vers la chaîne à afficher
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
	/* Condition de sortie : si la chaîne est vide, affiche un saut de ligne */
	if (s[0] == '\0')
	{
		_putchar('\n');  // Affiche le saut de ligne
		return;          // Termine la récursion
	}

	/* Sinon, affiche le caractère courant et appelle récursivement la suite */
	if (s[0] != '\0')
	{
		_putchar(s[0]);         // Affiche le caractère courant
		_puts_recursion(s + 1); // Appelle la fonction pour le caractère suivant
	}
}
