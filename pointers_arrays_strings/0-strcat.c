#include "main.h"
/**
* _strcat - fonction pour coller deux partie
* @dest: Le pointeur vers la chaîne de destination.
* @src: Le pointeur vers la chaîne source.
*
* Return: Un pointeur vers la chaîne résultante 'dest'.
*/

char *_strcat(char *dest, char *src)
{
	int l_dest = 0;
	int l_src = 0;

	while (dest[l_dest] != '\0')
	{
		l_dest++;
	}

	while (src[l_src] != '\0')
	{
		dest[l_dest] = src[l_src];
		l_dest++;
		l_src++;
	}

	dest[l_dest] = '\0';

	return (dest);
}
