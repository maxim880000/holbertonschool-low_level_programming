#include "main.h"

/* Met en majuscule la première lettre de chaque mot dans une chaîne */

/**
 * cap_string - met en majuscule toutes les premières lettres de mots
 * @str: pointeur vers la chaîne à modifier
 *
 * Return: pointeur vers la chaîne modifiée
 */
char *cap_string(char *str)
{
	int i = 0;

	/* Met la première lettre de la chaîne en majuscule si nécessaire */
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - ('a' - 'A');

	i = 1;
	/* Parcourt toute la chaîne */
	while (str[i] != '\0')
	{
		/* Si le caractère précédent est un séparateur et que le caractère courant est une minuscule */
		if ((str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n' ||
		     str[i - 1] == ',' || str[i - 1] == ';' || str[i - 1] == '.' ||
		     str[i - 1] == '!' || str[i - 1] == '?' || str[i - 1] == '"' ||
		     str[i - 1] == '(' || str[i - 1] == ')' || str[i - 1] == '{' ||
		     str[i - 1] == '}') && (str[i] >= 'a' && str[i] <= 'z'))
		{
			/* Convertit en majuscule */
			str[i] = str[i] - ('a' - 'A');
		}
		i++;
	}

	/* Retourne la chaîne modifiée */
	return (str);
}
