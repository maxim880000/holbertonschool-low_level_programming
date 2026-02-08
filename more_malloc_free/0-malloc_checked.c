#include <stdlib.h>
#include "main.h"

/* Alloue de la mémoire avec malloc et quitte si échec */

/**
 * malloc_checked - alloue de la mémoire et vérifie le succès
 * @b: nombre d’octets à allouer
 *
 * Return: pointeur vers la mémoire allouée, quitte avec 98 si échec
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	/* Alloue la mémoire */
	ptr = malloc(b);

	/* Si malloc échoue, quitte le programme avec code 98 */
	if (ptr == NULL)
		exit(98);

	/* Retourne le pointeur vers la mémoire allouée */
	return (ptr);
}
