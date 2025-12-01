#include <stdio.h>
#include "lists.h"
/**
 * list_len - returns the number of elements in a linked list_t list.
 * @h: node of the list
 *
 * Return: number of elements in a linked list_t list.
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;
	const list_t *ptr = h;

	/* tant qu’on a un nœud valide */
	while (ptr != NULL)
	{
		count++; /* count the current node */
		ptr = ptr->next; /* advance to the next node */
	}
	return (count);
}
