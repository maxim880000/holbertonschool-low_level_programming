#include <stdio.h>
#include "lists.h"

/* Affiche tous les éléments d'une liste chaînée de type list_t */

/**
 * print_list - affiche les éléments d'une liste list_t
 * @h: pointeur vers le premier nœud de la liste
 *
 * Return: le nombre de nœuds dans la liste
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;        /* compteur de nœuds */
	const list_t *ptr = h;   /* pointeur pour parcourir la liste */

	/* Tant que ptr n'est pas NULL (fin de la liste) */
	while (ptr != NULL)
	{
		/* Si la chaîne est NULL, afficher [0] (nil) */
		if (ptr->str == NULL)
			printf("[0] (nil)\n");
		else
			/* Affiche la longueur et la chaîne */
			printf("[%u] %s\n", ptr->len, ptr->str);

		count++;          /* incrémente le compteur de nœuds */
		ptr = ptr->next;  /* passe au nœud suivant */
	}

	return (count);       /* retourne le nombre de nœuds */
}
