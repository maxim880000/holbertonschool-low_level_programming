#include "lists.h"

/**
 * dlistint_len - retourne le nombre d'éléments dans une liste doublement chaînée
 * @h: pointeur vers la tête de la liste
 *
 * - Parcours depuis la tête jusqu'au dernier nœud.
 * - Compte chaque nœud.
 *
 * Return: nombre de nœuds
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;                 /* compteur de nœuds */
	const dlistint_t *current = h;    /* pointeur pour parcourir la liste */

	while (current != NULL)           /* tant qu'il reste un nœud */
	{
		count++;                     /* incrémente le compteur */
		current = current->next;     /* avance au nœud suivant */
	}

	return (count);
}
