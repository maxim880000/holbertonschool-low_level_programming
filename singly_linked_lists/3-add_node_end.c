#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to be duplicated and added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int i = 0;
	list_t *ptr, *temp;

	ptr = malloc(sizeof(list_t));
	if (ptr == NULL)
		return (NULL);

	/* mettre la chaine str dans dans le noeud */
	ptr->str = strdup(str);
	if (ptr->str == NULL)
	{
		free(ptr);
		return (NULL);
	}
	/* calcule la longueur len */
	while (ptr->str[i] != '\0')
		i++;
	ptr->len = i; /* stocker la longueur */
	ptr->next = NULL; /* le dernier noeud pointe vers NULL */

	/* Si la liste est vide, le nouveau noeud devient la tête */
	if (*head == NULL)
	{
		*head = ptr;
		return (ptr);
	}

	/* Sinon, parcourir jusqu'à la fin de la liste */
	/* donc au dernier noeud */
	temp = *head;
	while (temp->next != NULL) /* tant qu'il y a un suivant */
		temp = temp->next; /* avancer */

	/* Ajouter le nouveau noeud à la fin */
	temp->next = ptr;

	return (ptr); /* retourner l'adresse du nouveau noeud */
}
