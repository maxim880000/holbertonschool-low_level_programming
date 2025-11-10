#include <stdlib.h>
#include "main.h"
/**
* create_array - creates an array of chars initializes it with a specific char.
* @size: unsigned integer
* @c: char
*
* Return: NULL if size = 0, Returns a pointer to the array, or NULL if it fails
*/

/* creation de tableau dynamique */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	/* verifie la premiere conditions */
	if (size == 0)
		return (NULL);

	/* comment utiliser malloc (alloue de la memoire) */
	array = malloc(size * sizeof(char));
	/* verification si malloc a marcher */
	if (array == NULL)
		return (NULL);

	/* boucle for pour remplir le tableau avce c */
	for (i = 0; i < size; i++)
		array[i] = c;

	/* rendre la boite */
	return (array);
}
