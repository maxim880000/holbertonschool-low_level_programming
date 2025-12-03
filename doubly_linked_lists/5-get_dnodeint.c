#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: pointe vers head de la list (on commence la)
 * @index: La position (numéro) du nœud que nous cherchons
 *
 * Return: The address of the found node, or NULL if the node does not exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0; /* Un compteur */

	/* stop si 'head' (notre curseur) devient NULL (fin de liste) */
	while (head != NULL)
	{
		/* le numéro de(count) = au numéro demandé (index) */
		if (count == index)
		{
			return (head); /* oui on return ladresse du noeud actuel */
		}
		/* On passe au nœud suivant head pointe le nœud d'après. */
		head = head->next;
		count++;
	}
	/* Si la boucle est finie, fini la liste sans trouver l'index. */
	return (NULL); /* null car le noeud existe pas dans cette position */
}
