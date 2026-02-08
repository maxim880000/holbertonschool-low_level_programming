#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_list - libère toute une liste list_t
 * @head: pointeur vers le premier nœud
 *
 * - Libère chaque chaîne str.
 * - Libère chaque nœud.
 * - Parcourt toute la liste jusqu'à NULL.
 *
 * Return: rien
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)           /* tant que la liste n'est pas vide */
	{
		temp = head->next;        /* sauvegarde le suivant avant free */
		free(head->str);          /* libère la chaîne du nœud */
		free(head);               /* libère le nœud lui-même */
		head = temp;              /* avance au nœud suivant */
	}
}
