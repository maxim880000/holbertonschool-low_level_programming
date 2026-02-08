#include "lists.h"

/**
 * get_dnodeint_at_index - retourne le nœud à la position index
 * @head: pointeur vers la tête de la liste
 * @index: position du nœud à récupérer (0 = premier nœud)
 *
 * - Parcourt la liste en comptant les nœuds
 * - Retourne l'adresse du nœud quand count == index
 *
 * Return: adresse du nœud ou NULL si inexistant
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0; /* compteur de position */

	while (head != NULL)
	{
		if (count == index) /* si on est au bon index */
			return (head);  /* retourne le nœud */

		head = head->next; /* avancer au suivant */
		count++;
	}

	return (NULL); /* nœud non trouvé */
}
