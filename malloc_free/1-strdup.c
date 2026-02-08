#include <stdlib.h>
#include "main.h"

/* Duplique une chaîne de caractères en allouant de la mémoire dynamique */

/**
 * _strdup - crée une copie d'une chaîne de caractères
 * @str: chaîne à copier
 *
 * Return: pointeur vers la nouvelle chaîne, ou NULL si échec/allocation
 */
char *_strdup(char *str)
{
	int leng;
	char *sstr;
	int i;

	/* Si la chaîne d’entrée est NULL, retourne NULL */
	if (str == 0)
		return (NULL);

	/* Calculer la longueur de la chaîne */
	for (leng = 0; str[leng] != '\0'; leng++)
		;

	/* Allouer de la mémoire pour la copie (+1 pour le '\0') */
	sstr = malloc((leng + 1) * sizeof(char));
	if (sstr == NULL)
		return (NULL);

	/* Copier chaque caractère dans la nouvelle chaîne */
	for (i = 0; i < leng; i++)
		sstr[i] = str[i];

	/* Ajouter le caractère de fin de chaîne */
	sstr[leng] = '\0';

	return (sstr);
}
