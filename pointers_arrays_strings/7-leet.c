#include "main.h"

/* Encode une chaîne en "1337" en remplaçant certaines lettres par des chiffres */

/**
 * leet - transforme une chaîne en style "leet"
 * @str: pointeur vers la chaîne à encoder
 *
 * Return: pointeur vers la chaîne encodée
 */
char *leet(char *str)
{
	int a, b;
	/* Lettres à remplacer */
	char letters[] = "aAeEoOtTlL";
	/* Chiffres correspondants */
	char codes[] = "4433007711";

	/* Parcourt chaque caractère de la chaîne */
	for (a = 0; str[a] != '\0'; a++)
	{
		/* Vérifie si le caractère courant correspond à une lettre à remplacer */
		for (b = 0; letters[b] != '\0'; b++)
		{
			if (str[a] == letters[b])
			{
				/* Remplace la lettre par le chiffre correspondant */
				str[a] = codes[b];
				break; /* Passe au caractère suivant de str */
			}
		}
	}

	/* Retourne la chaîne encodée */
	return (str);
}
