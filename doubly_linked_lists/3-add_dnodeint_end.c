#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end -aAdds a new node at the end of a dlistint_t list.
 * @head: bouble pointeur vers les head
 * @n: entier pour new code
 *
 * Return: The address of the new element else NULL
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *temp; /* ptr pour parcourir la liste */

	/* alloue memoire, check new_node est vide */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n; /* initialise new_node = n */
	new_node->next = NULL; /* new_node c le dernier donc next null */

	/* La liste est vide */
	if (*head == NULL)
	{
		/* Si la liste est vide, je deviens le premier ET le dernier. */
		new_node->prev = NULL; /* Ma main gauche est coupée. */
		*head = new_node; /* head pointe sur new_node */
		return (new_node);
	}
	temp = *head; /* temp commence au debut de la list */
	/* Tant qu'on est pas a la fin (donc rien devant) */
	while (temp->next != NULL)
	{
		temp = temp->next; /* avance au noeud suivant */
	}
	/* quand on s'arrete temp = dernier noeud (next est null)*/
	temp->next = new_node; /* l'ancien dernier devient new_node */

	new_node->prev = temp; /* new_node pointe vers l'ancien dernier (temp) */

	return (new_node); /* return l'adresse */
}
