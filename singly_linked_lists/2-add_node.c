#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: doubl epointeur qui pointe vers le haut de la liste
 * @str: string to add
 *
 * Return: le nouveau noeud or null if it's fail
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *ptr; /* nouveau noeud */
	unsigned int i; /* pour la longueur */
	/* allouer de la memoire pour le new noeud */
	/* si sa echoue on sort */
	ptr = malloc(sizeof(list_t));
	if (ptr == NULL)
		return (NULL);

	/* je fais une copie du string pour mon nœud */
	ptr->str = strdup(str);

	i = 0;
	while (str[i] != '\0')/* tant que je ne suis pas à la fin de la string */
	i++;
	ptr->len = i; /* je mets le total dans len */

	/* le nouveau noeud pointe-> l'ancien 1ER noeud */
	ptr->next = *head;
	*head = ptr; /* nouveau nœud devient le premier de la list*/

	return (ptr); /* je retourne le nouveau nœud */
}
