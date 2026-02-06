#include "main.h"

/**
 * _strcat - concatène (colle) deux chaînes de caractères
 * @dest: pointeur vers la chaîne de destination
 * @src: pointeur vers la chaîne source
 *
 * Return: pointeur vers la chaîne résultante 'dest'
 */
char *_strcat(char *dest, char *src)
{
	int l_dest = 0;
	int l_src = 0;

	/* Trouve la fin de la chaîne de destination */
	while (dest[l_dest] != '\0')
	{
		l_dest++;
	}

	/* Copie chaque caractère de la source à la suite de la destination */
	while (src[l_src] != '\0')
	{
		dest[l_dest] = src[l_src];
		l_dest++;
		l_src++;
	}

	/* Ajoute le caractère nul à la fin pour terminer la chaîne */
	dest[l_dest] = '\0';

	/* Retourne la chaîne concaténée */
	return (dest);
}
