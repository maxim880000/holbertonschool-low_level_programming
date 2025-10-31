#include "main.h"

/**
 * _strcpy - Copie une chaîne de caractères (y compris le '\0').
 * @dest: Le pointeur vers le tampon de destination.
 * @src: Le pointeur vers la chaîne source à copier.
 *
 * Return: Le pointeur vers 'dest'
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
