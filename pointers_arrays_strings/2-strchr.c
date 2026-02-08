#include "main.h"

/* Recherche la première occurrence d’un caractère dans une chaîne */

/**
 * _strchr - localise un caractère dans une chaîne de caractères
 * @s: pointeur vers la chaîne à parcourir
 * @c: caractère à rechercher
 *
 * Return: pointeur vers la première occurrence de c,
 *         ou NULL si le caractère n’est pas trouvé
 */
char *_strchr(char *s, char c)
{
	int i;

	/* Parcourt la chaîne caractère par caractère */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Si le caractère est trouvé, retourne son adresse */
		if (s[i] == c)
			return (&s[i]);
	}

	/* Si le caractère recherché est '\0', retourne la fin de la chaîne */
	if (c == '\0')
		return (&s[i]);

	/* Si le caractère n'est pas trouvé */
	return ('\0');
}
