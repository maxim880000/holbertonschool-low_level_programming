#include <stdlib.h>
#include "dog.h"

/* Crée un nouveau chien avec des copies du nom et du propriétaire */

/**
 * new_dog - crée un nouveau dog_t et initialise ses champs
 * @name: nom du chien
 * @age: âge du chien
 * @owner: propriétaire du chien
 *
 * Return: pointeur vers dog_t ou NULL si erreur
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;        /* pointeur vers la structure dog */
	char *n, *p;     /* copies du nom et du propriétaire */
	int i;           /* compteur pour les boucles */

	/* Alloue la mémoire pour la structure dog */
	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	/* Copie le nom */
	for (i = 0; name[i]; i++)   /* calcule la longueur de name */
		;
	n = malloc(i + 1);           /* alloue mémoire pour le nom */
	if (n == NULL)               /* vérifie malloc */
	{
		free(d);                 /* libère structure si échec */
		return (NULL);
	}
	for (i = 0; name[i]; i++)   /* copie caractère par caractère */
		n[i] = name[i];
	n[i] = '\0';                 /* termine la chaîne */

	/* Copie le propriétaire */
	for (i = 0; owner[i]; i++)  /* calcule la longueur de owner */
		;
	p = malloc(i + 1);           /* alloue mémoire pour owner */
	if (p == NULL)               /* vérifie malloc */
	{
		free(n);                 /* libère nom */
		free(d);                 /* libère structure */
		return (NULL);
	}
	for (i = 0; owner[i]; i++)  /* copie caractère par caractère */
		p[i] = owner[i];
	p[i] = '\0';                 /* termine la chaîne */

	/* Initialise les champs de la structure */
	d->name = n;
	d->age = age;
	d->owner = p;

	return (d);
}
