#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - supprime le nœud à une position donnée index.
 * @head: Double pointeur sur la TÊTE de la liste (pour pouvoir la modifier).
 * @index: L'index du nœud à supprimer (commence à 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int count = 0;

	/* VÉRIFICATION LISTE VIDE ou POINTEUR NUL */
	if (head == NULL || *head == NULL)
		return (-1);

	/*  supprime la tête (Index 0) */
	if (index == 0)
	{
		/* le nouveau premier nœud devient le suivant. */
		*head = current->next;

		if (*head != NULL)
			/* Le nouveau premier nœud n'a plus de prédécesseur (prev = NULL) */
			(*head)->prev = NULL;
		free(current); /* Libérer l'ancienne tête */
		return (1);
	}

	/* Trouver le nœud à supprimer. */
	while (current != NULL && count < index)
	{
		current = current->next;
		count++;
	}
		/* Index trop grand. */
	if (current == NULL)
		return (-1);
	
	/* nœud PRÉCÉDENT Le nœud avant pointe vers le nœud après. */
	current->prev->next = current->next;

	/* nœud suivantt si le nœud supprimé n'est pas la fin */
	if (current->next != NULL)
		current->next->prev = current->prev;

	/* Libération de la mémoire. */
	free(current);
	return (1);
}