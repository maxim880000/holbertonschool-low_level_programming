#include <stdio.h>
#include "dog.h"

/* Affiche les informations d'une structure dog */

/**
 * print_dog - affiche le nom, l'âge et le propriétaire d'un chien
 * @d: pointeur vers la structure dog
 *
 * Description: Si un champ est NULL, affiche (nil). Si d est NULL, rien n'est affiché.
 */
void print_dog(struct dog *d)
{
	/* Si le pointeur est NULL, on ne fait rien */
	if (d == NULL)
		return;

	/* Affiche le nom ou (nil) si absent */
	if (d->name != NULL)
		printf("Name: %s\n", d->name);
	else
		printf("Name: (nil)\n");

	/* Affiche l'âge */
	printf("Age: %f\n", d->age);

	/* Affiche le propriétaire ou (nil) si absent */
	if (d->owner != NULL)
		printf("Owner: %s\n", d->owner);
	else
		printf("Owner: (nil)\n");
}
