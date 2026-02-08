#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/* Initialise une structure dog avec les valeurs fournies */

/**
 * init_dog - initialise une variable de type struct dog
 * @d: pointeur vers la structure à initialiser
 * @name: nom du chien
 * @age: âge du chien
 * @owner: propriétaire du chien
 *
 * Return: rien
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	/* Si le pointeur est NULL, on ne fait rien */
	if (d == NULL)
		return;

	/* Assigne les valeurs à la structure */
	d->name = name;     /* Nom */
	d->age = age;       /* Âge */
	d->owner = owner;   /* Propriétaire */
}
