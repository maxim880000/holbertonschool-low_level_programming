#include "main.h"
#include <stdlib.h>
/**
* _calloc - allocates memory for an array, using malloc.
* @nmemb: integer
* @size: integer 2
*
* Return: return a pointer
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;
	unsigned int result;
	/* vérifier paramètres */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* calcul taille totale */
	result = nmemb * size;

	/* alouer de la memoire*/
	ptr = malloc(result);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < result; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}
