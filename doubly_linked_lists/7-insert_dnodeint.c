#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - insère un nouveau nœud à une position donnée
 * @h: double pointeur vers le début de la liste
 * @idx: position où insérer le nouveau nœud
 * @n: valeur à mettre dans le nouveau nœud
 *
 * - Si idx = 0 → utilise add_dnodeint (début).
 * - Si idx = fin → utilise add_dnodeint_end.
 * - Sinon → insertion au milieu avec ajustement des prev/next.
 * - Retourne NULL si allocation échoue ou index invalide.
 *
 * Return: adresse du nouveau nœud ou NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp = *h; /* pointeur qui parcourt la liste */
	unsigned int count;

	if (idx == 0)
		return (add_dnodeint(h, n));

	/* avancer jusqu'au nœud précédent l'index désiré */
	for (count = 0; temp != NULL && count < idx - 1; count++)
		temp = temp->next;

	if (temp == NULL)
		return (NULL);

	/* si insertion à la fin */
	if (temp->next == NULL && count == idx - 1)
		return (add_dnodeint_end(h, n));

	/* insertion au milieu */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	new_node->next = temp->next; /* pointe vers le nœud suivant */
	new_node->prev = temp;       /* pointe vers le nœud précédent */

	if (new_node->next != NULL)
		new_node->next->prev = new_node; /* mettre à jour le suivant */

	temp->next = new_node; /* mettre à jour le précédent */

	return (new_node);
}
