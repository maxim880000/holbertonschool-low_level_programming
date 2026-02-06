#include "main.h"

/**
 * _memcpy - copie n octets d'une zone mémoire source vers une zone mémoire destination
 * @dest: pointeur vers la zone mémoire de destination
 * @src: pointeur vers la zone mémoire source
 * @n: nombre d'octets à copier
 *
 * Return: pointeur vers dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	/* Copie chaque octet de src vers dest */
	for (i = 0; i < n; i++)
		dest[i] = src[i];

	/* Retourne le pointeur vers la mémoire destination */
	return (dest);
}
