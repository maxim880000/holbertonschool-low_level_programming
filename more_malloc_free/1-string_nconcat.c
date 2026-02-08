#include "main.h"
#include <stdlib.h>

/* Concatène s1 avec les n premiers caractères de s2 dans une nouvelle chaîne */

/**
 * string_nconcat - crée une nouvelle chaîne contenant s1 + n caractères de s2
 * @s1: première chaîne
 * @s2: deuxième chaîne
 * @n: nombre maximum de caractères à prendre de s2
 *
 * Return: pointeur vers la nouvelle chaîne ou NULL si échec
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int leng1 = 0;
	unsigned int leng2 = 0;
	unsigned int i;
	unsigned int j;
	char *ptr;

	/* Si un des pointeurs est NULL, le remplacer par une chaîne vide */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculer la longueur de s1 */
	while (s1[leng1] != '\0')
		leng1++;

	/* Calculer la longueur de s2 */
	while (s2[leng2] != '\0')
		leng2++;

	/* Si n dépasse la longueur de s2, on prend toute s2 */
	if (n >= leng2)
		n = leng2;

	/* Allouer la mémoire pour la nouvelle chaîne (+1 pour '\0') */
	ptr = malloc((leng1 + n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);

	/* Copier s1 dans ptr */
	for (i = 0; i < leng1; i++)
		ptr[i] = s1[i];

	/* Copier les n premiers caractères de s2 après s1 */
	for (j = 0; j < n; j++)
		ptr[i + j] = s2[j];

	/* Ajouter le caractère de fin de chaîne */
	ptr[i + j] = '\0';

	return (ptr);
}
