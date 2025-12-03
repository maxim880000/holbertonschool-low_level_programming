#include "lists.h"

/**
 * sum_dlistint - Calcule la somme de toutes les données (n) d'une liste
 * @head: L'adresse du 1ER nœud de la liste
 *
 * Return: La somme de toutes les valeurs 'n' ou 0 si la liste est vide
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0; /* stocke le total */

	/* Si la liste est vide (head est NULL) */
	if (head == NULL)
		return (0);

	/* commence a head continue tant qu'il y a un nœud ou aller */
	while (head != NULL)
	{
		/* met la valeur du nœud actuel (head->n) dans sum */
		sum += head->n; /* C'est comme si sum = sum + head->n */

		/* avance au suivant head prend l'adresse du suivant */
		head = head->next;
	}
	return (sum);
}
