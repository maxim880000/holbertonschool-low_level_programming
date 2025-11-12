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
	int *ptr;
	int size;
	int i;

	if (min > max) /* verifer les valeurs */
		return (NULL);

	size = max - min + 1; /* definir size */

	ptr = malloc(size * sizeof(int)); /* allouer de la memoire */
		if (ptr == NULL) /* check malloc */
			return (NULL);

	for (i = 0; i < size; i++)
	ptr[i] = min + i;

	return (ptr);
}
