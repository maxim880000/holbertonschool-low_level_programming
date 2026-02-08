#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - ajoute un nouveau nœud à la fin d'une liste doublement chaînée
 * @head: double pointeur vers la tête de la liste
 * @n: entier à stocker dans le nouveau nœud
 *
 * Points clés :
 * - Nouveau nœud devient le dernier.
 * - Si liste vide, nouveau nœud = tête et dernier.
 * - prev du nouveau nœud pointe vers l'ancien dernier.
 *
 * Return: adresse du nouveau nœud, ou NULL si échec malloc
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *temp; /* pointeur pour parcourir la liste */

	new_node = malloc(sizeof(dlistint_t)); /* allouer le nouveau nœud */
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;      /* stocker la valeur */
	new_node->next = NULL; /* dernier nœud → next = NULL */

	if (*head == NULL) /* liste vide */
	{
		new_node->prev = NULL; /* pas de précédent */
		*head = new_node;      /* tête = nouveau nœud */
		return (new_node);
	}

	temp = *head; /* commencer au début */
	while (temp->next != NULL) /* parcourir jusqu'au dernier nœud */
		temp = temp->next;

	temp->next = new_node; /* ancien dernier → next = nouveau nœud */
	new_node->prev = temp; /* nouveau nœud → prev = ancien dernier */

	return (new_node); /* retourner le nouveau nœud */
}
