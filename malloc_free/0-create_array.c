#include <stdlib.h>
#include "main.h"

/* Crée un tableau dynamique de caractères et l’initialise avec un caractère donné */

/**
 * create_array - crée un tableau de taille `size` et le remplit avec `c`
 * @size: taille du tableau
 * @c: caractère pour remplir le tableau
 *
 * Return: NULL si size = 0 ou si l’allocation échoue,
 *         sinon retourne un pointeur vers le tableau
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	/* Taille nulle → retourne NULL */
	if (size == 0)
		return (NULL);

	/* Alloue de la mémoire pour le tableau */
	array = malloc(size * sizeof(char));

	/* Vérifie si malloc a échoué */
	if (array == NULL)
		return (NULL);

	/* Remplit le tableau avec le caractère c */
	for (i = 0; i < size; i++)
		array[i] = c;

	/* Retourne le pointeur vers le tableau */
	return (array);
}
