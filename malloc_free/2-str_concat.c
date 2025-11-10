#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated string containing s1 + s2
 */

char *str_concat(char *s1, char *s2)
{
int leng1, leng2;
char *result;
int i;

/* si on recoit un pointeur vide on le met en "" */
if (s1 == NULL)
{
	s1 = "";
}
if (s2 == NULL)
{
	s2 = "";
}
	/* boucle vide pour compter les char s1 */
	for (leng1 = 0; s1[leng1] != '\0'; leng1++)
	;

	for (leng2 = 0; s2[leng2] != '\0'; leng2++)
	;
	/* allouer la mémoire pour la nouvelle chaîne */
	result = malloc((leng1 + leng2 + 1) * sizeof(char));
	if (result == NULL) /* vérifier si malloc échour */
		return (NULL);

	/* copier les caractères de s1 dans result */
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	/* copier les caractères de s2 à la suite de s1 */
	i = 0;
	while (s2[i])
	{
		result[leng1 + i] = s2[i];
		i++;
	}
	/* ajouter le caractère nul pour terminer la chaîne */
	result[leng1 + leng2] = '\0';
		return (result);
}
