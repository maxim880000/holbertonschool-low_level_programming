#include <stdlib.h>
#include "dog.h"

/* Libère la mémoire allouée pour une structure dog_t */

/**
 * free_dog - libère un dog_t créé dynamiquement
 * @d: pointeur vers la structure dog_t à libérer
 *
 * Description: Libère le nom, le propriétaire et enfin la structure elle-même.
 */
void free_dog(dog_t *d)
{
	/* Si le pointeur est NULL, rien à faire */
	if (d == NULL)
		return;

	/* Libère les chaînes allouées dynamiquement */
	free(d->name);
	free(d->owner);

	/* Libère la structure */
	free(d);
}
