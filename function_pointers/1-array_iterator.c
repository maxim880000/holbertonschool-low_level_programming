#include "function_pointers.h"

/**
* array_iterator - executes a function parameter every element in array
* @array: pointer
* @size: taille de size
*
* Return: nothing
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	/* Si array ou action est NULL → on sort direct */
	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		/* on donne le nombre du tableau à la fonction qu’on a reçue */
		action(array[i]);
	}
}
