#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/**
 * add_node - ajoute un nouveau nœud au début d'une liste list_t
 * @head: double pointeur vers le premier nœud de la liste
 * @str: chaîne à stocker dans le nouveau nœud
 *
 * - Copie la chaîne avec strdup.
 * - Nouveau nœud = tête.
 *
 * Return: pointeur vers le nouveau nœud, ou NULL si échec
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *ptr;        /* pointeur vers le nouveau nœud */
	unsigned int i;     /* compteur pour la longueur de la chaîne */

	ptr = malloc(sizeof(list_t));  /* alloue mémoire pour le nouveau nœud */
	if (ptr == NULL)
		return (NULL);            /* retourne NULL si échec */

	ptr->str = strdup(str);       /* copie la chaîne dans le nœud */

	/* calcule la longueur de la chaîne */
	i = 0;
	while (str[i] != '\0')
		i++;
	ptr->len = i;                 /* stocke la longueur dans len */

	ptr->next = *head;            /* le nouveau nœud pointe vers l'ancien premier */
	*head = ptr;                  /* le nouveau nœud devient la tête */

	return (ptr);                 /* retourne le nouveau nœud */
}
