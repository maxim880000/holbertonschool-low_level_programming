#include <stdio.h>
#include "lists.h"

/* Compte le nombre d'éléments dans une liste chaînée de type list_t */

/**
 * list_len - retourne le nombre de nœuds dans une liste list_t
 * @h: pointeur vers le premier nœud de la liste
 *
 * Return: nombre de nœuds dans la liste
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;        /* compteur de nœuds */
	const list_t *ptr = h;   /* pointeur pour parcourir la liste */

	/* Tant que le pointeur n'est pas NULL (fin de la liste) */
	while (ptr != NULL)
	{
		count++;          /* incrémente le compteur pour le nœud actuel */
		ptr = ptr->next;  /* passe au nœud suivant */
	}

	return (count);       /* retourne le nombre total de nœuds */
}
