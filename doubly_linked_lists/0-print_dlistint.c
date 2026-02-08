#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - affiche tous les éléments d'une liste doublement chaînée
 * @h: pointeur vers le début de la liste
 *
 * - Parcours depuis la tête jusqu'au dernier nœud.
 * - Affiche chaque valeur (`n`) suivie d'un saut de ligne.
 *
 * Return: nombre de nœuds
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;                 /* compteur de nœuds */
	const dlistint_t *current = h;    /* pointeur pour parcourir la liste */

	if (h == NULL) /* liste vide */
		return (0);

	while (current != NULL) /* tant qu'il reste un nœud */
	{
		printf("%d\n", current->n); /* affiche la valeur du nœud */
		count++;                    /* incrémente le compteur */
		current = current->next;    /* passe au nœud suivant */
	}

	return (count);
}
