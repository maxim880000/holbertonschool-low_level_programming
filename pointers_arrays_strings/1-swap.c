#include "main.h"

/* Échange les valeurs de deux entiers */

/**
 * swap_int - échange les valeurs de deux entiers
 * @a: pointeur vers le premier entier
 * @b: pointeur vers le second entier
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int temp;

	/* Stocke la valeur pointée par a dans une variable temporaire */
	temp = *a;

	/* Copie la valeur pointée par b dans a */
	*a = *b;

	/* Met l'ancienne valeur de a dans b */
	*b = temp;
}
