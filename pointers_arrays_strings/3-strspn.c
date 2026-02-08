#include "main.h"

/* Calcule la longueur du préfixe initial de s composé uniquement de caractères dans accept */

/**
 * _strspn - retourne le nombre de caractères initiaux dans s qui sont dans accept
 * @s: chaîne à analyser
 * @accept: ensemble de caractères acceptés
 *
 * Return: nombre de caractères consécutifs de s présents dans accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i;
	int j;
	int t = 0;

	/* Parcourt chaque caractère de s */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Vérifie si le caractère s[i] est présent dans accept */
		for (j = 0; accept[j] != '\0'; j++)
		{
			t = 0;
			if (s[i] == accept[j])
			{
				t = 1; /* Caractère trouvé dans accept */
				break;
			}
		}

		/* Si le caractère n'est pas trouvé, on retourne la longueur du préfixe */
		if (t == 0)
			return (i);
	}

	/* Tous les caractères initiaux sont dans accept, retourne i */
	return (i);
}
