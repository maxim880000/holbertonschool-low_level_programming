#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
#include <stdio.h>
/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: Pointer to the head of the doubly linked list.
 *
 * Return:The number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;   /* compteur de nœuds */
	dlistint_t *current = h; /* pointeur qui parcourt la liste */

	if (h == NULL)
		return (NULL);

	while (current != NULL)
	{
		printf("%d\n", current->n);
		count++; /* compte +1 */
		current = current->next; /* on avance */
	}
	return (count);
}
