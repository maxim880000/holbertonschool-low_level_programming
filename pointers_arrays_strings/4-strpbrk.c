#include "main.h"
#include <stddef.h>

/* Cherche dans une chaîne le premier caractère qui apparaît dans un ensemble donné */

/**
 * _strpbrk - recherche le premier caractère commun entre s et accept
 * @s: chaîne à parcourir
 * @accept: chaîne contenant les caractères à chercher
 *
 * Return: pointeur vers le premier caractère trouvé dans s,
 *         ou NULL si aucun n’est trouvé
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	/* Parcourt chaque caractère de s */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Parcourt chaque caractère de accept */
		for (j = 0; accept[j] != '\0'; j++)
		{
			/* Si un caractère de s correspond à accept, retourne son adresse */
			if (s[i] == accept[j])
				return (&s[i]);
		}
	}

	/* Aucun caractère commun trouvé */
	return (NULL);
}
