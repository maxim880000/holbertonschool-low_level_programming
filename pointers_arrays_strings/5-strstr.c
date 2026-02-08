#include "main.h"
#include <stddef.h>

/* Recherche une sous-chaîne dans une chaîne principale */

/**
 * _strstr - localise la première occurrence d'une sous-chaîne
 * @haystack: chaîne dans laquelle chercher
 * @needle: sous-chaîne à rechercher
 *
 * Return: pointeur vers le début de la sous-chaîne trouvée,
 *         ou NULL si elle n’est pas trouvée
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	/* Si needle est vide, retourne la chaîne principale */
	if (needle[0] == '\0')
		return (haystack);

	/* Parcourt chaque caractère de haystack */
	for (i = 0; haystack[i] != '\0'; i++)
	{
		/* Compare la sous-chaîne à partir de la position i */
		for (j = 0; needle[j] != '\0'; j++)
		{
			/* Si un caractère ne correspond pas, on arrête la comparaison */
			if (haystack[i + j] != needle[j])
				break;
		}

		/* Si on a parcouru toute needle, on a trouvé la sous-chaîne */
		if (needle[j] == '\0')
			return (&haystack[i]);
	}

	/* Aucun match trouvé */
	return (NULL);
}
