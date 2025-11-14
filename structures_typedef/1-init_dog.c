#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/**
* init_dog - initialize a variable of type struct dog
* @d: pointer
* @name: char
* @age: interger
* @owner: char
*
* Return: return pointer
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL) /* si pointeur NULL */
		return; /* rien faire */

	d->name = name; /* met dans d->name */
	d->age = age; /* On assigne l’âge donné */
	d->owner = owner; /* sauvegarde le propriétaire dans la structure. */
}
