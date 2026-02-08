#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - supprime le nœud à une position donnée
 * @head: double pointeur vers la tête de la liste
 * @index: position du nœud à supprimer (0 = tête)
 *
 * - Si index = 0 → suppression de la tête, mise à jour de head.
 * - Sinon → trouve le nœud, ajuste prev et next des voisins.
 * - Retourne -1 si liste vide ou index invalide, 1 sinon.
 *
 * Return: 1 si succès, -1 si échec
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* suppression de la tête */
	if (index == 0)
	{
		*head = current->next;       /* le nouveau premier nœud */
		if (*head != NULL)
			(*head)->prev = NULL;   /* pas de prédécesseur */
		free(current);               /* libère l'ancienne tête */
		return (1);
	}

	/* trouver le nœud à supprimer */
	while (current != NULL && count < index)
	{
		current = current->next;
		count++;
	}

	if (current == NULL) /* index trop grand */
		return (-1);

	/* réajuster les voisins */
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current); /* libération mémoire */
	return (1);
}
