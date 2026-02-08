#include "main.h"

/* Copie une chaîne de caractères vers un tampon de destination */

/**
 * _strcpy - copie la chaîne src dans dest, y compris le caractère nul '\0'
 * @dest: pointeur vers la chaîne de destination
 * @src: pointeur vers la chaîne source
 *
 * Return: pointeur vers dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	/* Parcourt chaque caractère de src et le copie dans dest */
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* Termine la chaîne dest par le caractère nul */
	dest[i] = '\0';

	/* Retourne le pointeur vers la chaîne destination */
	return (dest);
}
