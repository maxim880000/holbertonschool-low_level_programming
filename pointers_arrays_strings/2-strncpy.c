#include "main.h"

/* Copie au maximum n caractères de src vers dest */

/**
 * _strncpy - copie une chaîne de caractères avec une limite de taille
 * @dest: chaîne de destination
 * @src: chaîne source
 * @n: nombre maximum de caractères à copier
 *
 * Return: pointeur vers dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a = 0, b;

	/* Copie les caractères de src vers dest tant que n n’est pas atteint */
	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}

	/* Remplit le reste de dest avec des '\0' si src est plus courte que n */
	b = a;
	while (b < n)
	{
		dest[b] = '\0';
		b++;
	}

	/* Retourne la chaîne destination */
	return (dest);
}
