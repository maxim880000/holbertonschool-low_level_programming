#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node_end - ajoute un nouveau nœud à la fin d'une liste list_t
 * @head: double pointeur vers la tête de la liste
 * @str: chaîne à dupliquer et ajouter au nouveau nœud
 *
 * - Copie la chaîne avec strdup.
 * Return: pointeur vers le nouveau nœud, ou NULL si échec
 */
list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int i = 0;
	list_t *ptr, *temp;

	ptr = malloc(sizeof(list_t));  /* alloue mémoire pour le nouveau nœud */
	if (ptr == NULL)
		return (NULL);            /* retourne NULL si échec */

	ptr->str = strdup(str);       /* copie la chaîne dans le nœud */
	if (ptr->str == NULL)         /* vérifie si strdup a échoué */
	{
		free(ptr);                /* libère mémoire du nœud */
		return (NULL);
	}

	/* calcule la longueur de la chaîne et stocke dans len */
	while (ptr->str[i] != '\0')
		i++;
	ptr->len = i;

	ptr->next = NULL;             /* le dernier nœud pointe vers NULL */

	/* Si la liste est vide, le nouveau nœud devient la tête */
	if (*head == NULL)
	{
		*head = ptr;
		return (ptr);
	}

	/* Sinon, parcours jusqu'au dernier nœud */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = ptr;             /* ajoute le nouveau nœud à la fin */

	return (ptr);                 /* retourne le nouveau nœud */
}
