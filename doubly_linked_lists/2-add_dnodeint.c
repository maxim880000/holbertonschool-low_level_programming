#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - ajoute un nouveau nœud au début d'une liste doublement chaînée
 * @head: double pointeur vers la tête de la liste
 * @n: valeur entière à stocker dans le nouveau nœud
 *
 * - Nouveau nœud devient la tête.
 * - prev du nouveau nœud = NULL.
 * - Si liste non vide, ancien head->prev = nouveau nœud.
 *
 * Return: adresse du nouveau nœud, ou NULL si échec malloc
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t)); /* allocation du nouveau nœud */
	if (new_node == NULL)                              /* échec malloc */
		return (NULL);

	new_node->n = n;       /* stocker la valeur */
	new_node->prev = NULL; /* pas de nœud avant */
	new_node->next = *head;/* ancien head devient le suivant */

	if (*head != NULL)          /* si liste non vide */
		(*head)->prev = new_node; /* relier l'ancien head au nouveau */

	*head = new_node;          /* mise à jour de la tête */

	return (new_node);          /* retourner le nouveau nœud */
}
