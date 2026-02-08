#include "main.h"
#include <stdlib.h>

/* Alloue un tableau et initialise chaque case à 0, comme calloc */

/**
 * _calloc - alloue de la mémoire pour un tableau et initialise à 0
 * @nmemb: nombre d’éléments du tableau
 * @size: taille de chaque élément en octets
 *
 * Return: pointeur vers la mémoire allouée, ou NULL si erreur
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;
	unsigned int result;

	/* Vérifie que les paramètres sont valides */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Calcul de la taille totale à allouer */
	result = nmemb * size;

	/* Alloue la mémoire */
	ptr = malloc(result);
	if (ptr == NULL)
		return (NULL);

	/* Initialise chaque octet à 0 */
	for (i = 0; i < result; i++)
		ptr[i] = 0;

	/* Retourne le pointeur vers la mémoire allouée */
	return ((void *)ptr);
}
