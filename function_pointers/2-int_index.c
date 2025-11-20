#include "function_pointers.h"

/**
 * int_index - searches for an integer.
 * @array: pointer vers un tableau
 * @size: nb element
 * @cmp: pointer to compares values
 *
 * Return: -1 if not found else r(i)
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	/* Check if array or cmp is NULL */
	if (array == NULL || cmp == NULL)
		return (-1);
	/* Iterate through array and apply cmp function */
	if (size <= 0)
		return (-1);
	/* Parcours du tableau et application de la fonction cmp */
	for (i = 0; i < size; i++)
	{
		/* cmp pointer vers une fonction */
		/* array[i] element du tableau */
		/* cmp(array[i]) != 0 vrai → on entre dans le if. */
		/* cmp(array[i]) == 0 faux → on continue la boucle. */
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
