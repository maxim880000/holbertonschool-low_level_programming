#include "main.h"
#include <stdlib.h>
/**
* array_range - creates an array of integers.
* @min: intgeer
* @max: integer
*
* Return: return pointer
*/
int *array_range(int min, int max)
{
	unsigned int *ptr;
	unsigned int size;
	int i;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	ptr = malloc(size);
		if (ptr == NULL)
			return (NULL);

	for (i = 0; i < size; i++)
	ptr[i] = min + i;

	return (ptr);
}
