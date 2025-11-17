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

	if (array == NULL || cmp == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
