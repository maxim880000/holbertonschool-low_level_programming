#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory allocated for a dog_t struct
 * @d: pointer to dog_t
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return; /* on fait rien */

	free(d->name); /* libérer name */
	free(d->owner);
	free(d);
}
