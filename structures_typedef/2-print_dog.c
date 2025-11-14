#include <stdio.h>
#include "dog.h"

/**
 * print_dog - affiche les informations d'une structure dog
 * @d: pointeur vers la structure dog
 *
 * Description: Affiche le nom, l'âge et le propriétaire.
 * Si un champ est NULL, affiche (nil). Si d est NULL, rien n'est affiché.
 */
void print_dog(struct dog *d)
{
	if (d == NULL) /* si dog NULL */
		return; /* fait rien */

	if (d->name != NULL) /* nom existe ? */
		printf("Name: %s\n", d->name);   /* afficher nom */
	else
		printf("Name: (nil)\n");  /* nom manquant */

	printf("Age: %f\n", d->age);  /* afficher âge */

	if (d->owner != NULL) /* owner existe ? */
		printf("Owner: %s\n", d->owner); /* afficher owner */
	else
		printf("Owner: (nil)\n");  /* owner absent */
}
