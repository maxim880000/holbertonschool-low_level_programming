#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - libère une liste doublement chaînée
 * @head: pointeur vers la tête de la liste
 *
 * - Parcourt la liste en sauvegardant le suivant avant de free.
 * - Libère chaque nœud.
 * - Après libération, head devient NULL.
 *
 * Return: rien
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;
	dlistint_t *next_node; /* sauvegarder le suivant */

	current_node = head;
	while (current_node != NULL)
	{
		next_node = current_node->next; /* mémoriser suivant */
		free(current_node);             /* libérer nœud courant */
		current_node = next_node;       /* avancer */
	}
}
