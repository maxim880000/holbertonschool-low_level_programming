#include "main.h"

/* Calcule la longueur d'une chaîne en utilisant la récursion */

/**
 * _strlen_recursion - retourne la longueur d'une chaîne
 * @s: pointeur vers la chaîne
 *
 * Return: longueur de la chaîne
 */
int _strlen_recursion(char *s)
{
	/* Cas de base : fin de la chaîne */
	if (*s == '\0')
		return (0);  // Aucun caractère restant

	/* Retourne 1 + la longueur du reste de la chaîne */
	return (1 + _strlen_recursion(s + 1));
}
