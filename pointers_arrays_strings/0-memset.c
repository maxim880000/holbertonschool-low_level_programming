#include "main.h"

/**
 * _memset - remplit une zone mémoire avec un caractère donné
 * @s: pointeur vers la zone mémoire à remplir
 * @b: caractère utilisé pour remplir la mémoire
 * @n: nombre d’octets à remplir
 *
 * Return: pointeur vers la zone mémoire s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	/* Parcourt la mémoire et remplit chaque case avec le caractère b */
	for (i = 0; i < n; i++)
		s[i] = b;

	/* Retourne le pointeur vers la mémoire modifiée */
	return (s);
}
