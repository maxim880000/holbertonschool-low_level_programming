#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: Le double pointeur vers le debut de la liste
 * @idx: La position où insérer le nouveau nœud
 * @n: La valeur à mettre dans le nouveau nœud.
 *
 * Return: Le nouveau nœud inséré, ou NULL en cas d'échec
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp = *h; /* Notre pointeur commence au début de la liste. */
	unsigned int count;

	/* Si la position demandée est la première */
	if (idx == 0)
		 /* on appelle notre fonction pour ajouter au début */
		return (add_dnodeint(h, n));

	/* tant que 'temp' existe, tant que nous n'avons pas atteint idx - 1 */
	for (count = 0; temp != NULL && count < idx - 1; count++)
		temp = temp->next; /* On avance temp au nœud suivant. */

	/* Si 'temp' est NULL, c'est que l'index était trop grand */
	if (temp == NULL)
		return (NULL);
	/* si le nœud trouvé (temp) est le dernier */
	/* (son next est NULL),donc c'était bien l'index idx-1 */
	if (temp->next == NULL && count == idx - 1)
		return (add_dnodeint_end(h, n)); /* utilise la fonction d'ajout à la fin */

	/* Insertion au MILIEU (Après le nœud 'temp'). */
	/* On crée le nouveau nœud. */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* On insère new_node entre temp et son suivant. */

	/* new_node.next reçoit le nœud qui était avant l'insertion. */
	new_node->next = temp->next;
	/* new_node.prev reçoit le nœud précédent (temp). */
	new_node->prev = temp;

	/* Mise à jour du nœud qui suit new_node (réciprocité) */
	/* Si le nœud suivant exist on lui dit de pointer arrière vers new_node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;

	/* Mise à jour du nœud qui précède (temp) */
	/* Le nœud précédent (temp)doit changer(next) pour pointer sur new_node */
	temp->next = new_node;

	return (new_node);
}
