#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 * @s: pointer to the string
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')                // Cas de base : fin de la chaîne
		return (0);                // Longueur = 0

	return (1 + _strlen_recursion(s + 1));
}
