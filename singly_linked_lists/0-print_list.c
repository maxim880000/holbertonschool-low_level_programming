#include <stdio.h>
#include "lists.h"
/**
 * print_list - prints all the elements of a list_t list.
 * @list_t: 
 * 
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;
	const list_t *ptr = h;

	/* tant que ptr pointe sur un noeud valide */
	while (ptr != NULL)
	{
		/* si la string du noeud est vide */
		if (ptr-> str == NULL)
			printf ("[0] (nil)\n");

		else 
			/* affiche la longeur des string et la string */
			printf ("[%u] %s\n", ptr->len, ptr->str );
		
		count++; /* ajoute +1 a chque noead vu */
		/* ptr avance au nœud suivant */
		ptr = ptr->next;
		

	}
	return (count);
}