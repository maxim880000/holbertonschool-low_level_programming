#include "main.h"
#include <stdlib.h>

/* Concatène deux chaînes en allouant de la mémoire dynamique */

/**
 * str_concat - crée une nouvelle chaîne contenant s1 suivi de s2
 * @s1: première chaîne
 * @s2: deuxième chaîne
 *
 * Return: pointeur vers la nouvelle chaîne, ou NULL si échec
 */
char *str_concat(char *s1, char *s2)
{
	int leng1, leng2;
	char *result;
	int i;

	/* Si l’un des pointeurs est NULL, on le remplace par une chaîne vide */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculer la longueur de s1 */
	for (leng1 = 0; s1[leng1] != '\0'; leng1++)
		;

	/* Calculer la longueur de s2 */
	for (leng2 = 0; s2[leng2] != '\0'; leng2++)
		;

	/* Allouer la mémoire pour la nouvelle chaîne (+1 pour '\0') */
	result = malloc((leng1 + leng2 + 1) * sizeof(char));
	if (result == NULL) /* Vérifie si malloc a échoué */
		return (NULL);

	/* Copier les caractères de s1 dans result */
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}

	/* Copier les caractères de s2 juste après s1 */
	i = 0;
	while (s2[i])
	{
		result[leng1 + i] = s2[i];
		i++;
	}

	/* Ajouter le caractère de fin de chaîne */
	result[leng1 + leng2] = '\0';

	return (result);
}
