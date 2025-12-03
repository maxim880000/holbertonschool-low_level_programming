#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * add_node_end - frees a list_t list.
 * @head: pointer to the first node
 *
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
/* tant que la liste n'est pas vide */
	{
		temp = head->next; /* IMPORTANT: sauvegarder le suivant AVANT de free */
		free(head->str);   /* liberer la chaine (allouee par strdup) */
		free(head);        /* liberer le noeud lui-meme */
		head = temp;       /* avancer au noeud suivant */
	}
}
