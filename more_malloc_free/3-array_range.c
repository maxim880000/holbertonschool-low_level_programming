#include "main.h"
#include <stdlib.h>

/* Crée un tableau d’entiers contenant tous les nombres de min à max */

/**
 * array_range - crée un tableau d'entiers de min à max inclus
 * @min: valeur minimale
 * @max: valeur maximale
 *
 * Return: pointeur vers le tableau, ou NULL si erreur
 */
int *array_range(int min, int max)
{
	int *ptr;
	int size;
	int i;

	/* Vérifie que min <= max */
	if (min > max)
		return (NULL);

	/* Taille du tableau = nombre d’éléments de min à max inclus */
	size = max - min + 1;

	/* Alloue la mémoire pour le tableau */
	ptr = malloc(size * sizeof(int));
	if (ptr == NULL) /* Vérifie si malloc échoue */
		return (NULL);

	/* Remplit le tableau avec les valeurs de min à max */
	for (i = 0; i < size; i++)
		ptr[i] = min + i;

	/* Retourne le pointeur vers le tableau */
	return (ptr);
}
