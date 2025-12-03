#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint -  frees a dlistint_t list
 * @head: A pointer to the head of the dlistint_t list
 *
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;
	dlistint_t *next_node; /* Pointeur pour sauvegarder le suivant */

	/* Le processus s'arrête lorsque 'head' devient NULL (fin de liste) */
	current_node = head;
	while (current_node != NULL)
	{
		/* On doit d'abord Mémoriser l'adresse du nœud suivant */
		/* Sinon, on perd l'accès au reste de la liste */
		next_node = current_node->next;

		/* On libère la mémoire occupée par le nœud sur lequel nous sommes. */
		free(current_node);

		/* On passe au nœud suivant que nous avions sauvegardé. */
		current_node = next_node;
	}
}
