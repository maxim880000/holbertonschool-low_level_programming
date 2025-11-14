#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - crée un nouveau chien
 * @name: nom du chien
 * @age: âge du chien
 * @owner: propriétaire du chien
 *
 * Return: pointeur vers dogt ou NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;        /* pointeur structure dog */
	char *n, *p;     /* copies nom owner */

	d = malloc(sizeof(dog_t));   /* alloue struct dog */
	if (d == NULL)               /* vérif malloc */
		return (NULL);

	n = malloc(strlen(name) + 1);   /* alloue mémoire nom */
	if (n == NULL)                  /* vérif malloc */
	{
		free(d);                    /* lib struct si erreur */
		return (NULL);
	}
	strcpy(n, name);                 /* copie nom */

	p = malloc(strlen(owner) + 1);  /* alloue mémoire owner */
	if (p == NULL)                   /* vérif malloc */
	{
		free(n);                     /* lib nom si erreur */
		free(d);                     /* lib struct si erreur */
		return (NULL);
	}
	strcpy(p, owner);                /* copie owner */

	d->name = n;       /* met champ name */
	d->age = age;      /* met champ age */
	d->owner = p;      /* met champ owner */

	return (d);        /* retourne pointeu */
}
