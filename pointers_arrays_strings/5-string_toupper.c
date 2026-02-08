#include "main.h"

/* Transforme tous les caractères minuscules d’une chaîne en majuscules */

/**
 * string_toupper - convertit tous les caractères minuscules en majuscules
 * @str: pointeur vers la chaîne à modifier
 *
 * Return: pointeur vers la chaîne modifiée
 */
char *string_toupper(char *str)
{
	int i = 0;

	/* Parcourt chaque caractère de la chaîne */
	while (str[i] != '\0')
	{
		/* Si le caractère est une lettre minuscule, on le convertit en majuscule */
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');

		i++;
	}

	/* Retourne la chaîne modifiée */
	return (str);
}
