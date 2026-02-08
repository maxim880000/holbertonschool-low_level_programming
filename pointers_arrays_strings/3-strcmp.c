#include "main.h"

/* Compare deux chaînes de caractères */

/**
 * _strcmp - compare deux chaînes
 * @s1: première chaîne à comparer
 * @s2: deuxième chaîne à comparer
 *
 * Return: 0 si les chaînes sont identiques
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	/* Parcourt les deux chaînes tant qu’elles n’ont pas atteint '\0' */
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		/* Si un caractère diffère, retourne la différence ASCII */
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	/* Retourne la différence du caractère de fin */
	return (s1[i] - s2[i]);
}
