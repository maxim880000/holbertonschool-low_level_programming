#include "main.h"

/* Concatène au maximum n caractères de src à la fin de dest */

/**
 * _strncat - concatène deux chaînes de caractères
 * @dest: chaîne de destination
 * @src: chaîne source
 * @n: nombre maximum de caractères à copier depuis src
 *
 * Return: pointeur vers la chaîne résultante dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int a = 0;
	int b = 0;

	/* Trouve la fin de la chaîne de destination */
	while (dest[a] != '\0')
	{
		a++;
	}

	/* Copie au maximum n caractères de src à la suite de dest */
	while (b < n && src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}

	/* Termine la chaîne résultante par le caractère nul */
	dest[a] = '\0';

	/* Retourne la chaîne concaténée */
	return (dest);
}
