#include "lists.h"
#include <stdlib.h>
/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: Double pointer to the head of the list (pointer to pointer).
 * @n: Integer value to store in the new node.s
 *
 * Return: Address of the new node, or NULL if malloc failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	/* Allouer la mémoire pour le nouveau nœud */
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	/* Si malloc échoue → on retourne NULL immédiatement */
	if (new_node == NULL)
		return (NULL);

	new_node->n = n; /* ke rempli le new_node avec n */
	new_node->prev = NULL; /* pas de noeud avant donc pointe vers rien */
	new_node->next = *head; /* *head: ancien 1ER, c mon suivant */

	/* si la liste n'est pas vide */
	if (*head != NULL)
		(*head)->prev = new_node; /* on change head aura l'adresse de new_node */

	*head = new_node; /* change de tete */

	return (new_node); /* adresse du nouveau */
}
