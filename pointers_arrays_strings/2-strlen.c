#include "main.h"

/* Calcule la longueur d’une chaîne de caractères */

/**
 * _strlen - retourne la longueur d'une chaîne
 * @s: pointeur vers la chaîne à mesurer
 *
 * Return: nombre de caractères dans la chaîne
 */
int _strlen(char *s)
{
	int i = 0;

	/* Parcourt la chaîne jusqu'au caractère nul */
	while (s[i] != '\0')
	{
		i++;
	}

	/* Retourne le nombre de caractères */
	return (i);
}
