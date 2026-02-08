#include "lists.h"

/**
 * sum_dlistint - calcule la somme de toutes les valeurs 'n' d'une liste
 * @head: adresse du premier nœud de la liste
 *
 * - Parcourt la liste depuis la tête
 * - Ajoute chaque nœud->n à la somme
 * - Retourne 0 si la liste est vide
 *
 * Return: somme de tous les n ou 0 si liste vide
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0; /* total des valeurs */

	while (head != NULL)
	{
		sum += head->n; /* ajoute la valeur du nœud courant */
		head = head->next; /* avance au nœud suivant */
	}
	return (sum);
}
