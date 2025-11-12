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

	if (nmemb == 0 || size == 0)
		return (NULL);

	result = nmemb * size;

	ptr = malloc(result * sizeof(int));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < result; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}
