#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - crée un nouveau chien
 * @name: nom du chien
 * @age: âge du chie
 * @owner: propriétair du chien
 *
 * Return: pointeur vers dog_t ou NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;        /* pointeur structure dog */
	char *n, *p;     /* copies nom et owner */
	int i;           /* compteur (index) boucle */

	d = malloc(sizeof(dog_t));   /* alloue structure */
	if (d == NULL)               /* vérif allocation */
		return (NULL);           /* retourne NULL si echec */

	/* copie nom manuellement */
	for (i = 0; name[i]; i++)   /* calcule longueur nom */
		;
	n = malloc(i + 1);           /* alloue mémoire nom */
	if (n == NULL)               /* vérif malloc */
	{
		free(d);                 /* lib structure */
		return (NULL);           /* retourne NULL si echec */
	}
	for (i = 0; name[i]; i++)   /* copie chaque caractere */
		n[i] = name[i];
	n[i] = '\0';                 /* fin de chaîne */

	/* copie owner manuellement */
	for (i = 0; owner[i]; i++)  /* calcule longueur owner */
		;
	p = malloc(i + 1);           /* alloue mémoire owner */
	if (p == NULL)               /* vérif malloc */
	{
		free(n);                 /* lib nom */
		free(d);                 /* lib structure */
		return (NULL);           /* retourne NULL si echec */
	}
	for (i = 0; owner[i]; i++)  /* copie chaque caractere */
		p[i] = owner[i];
	p[i] = '\0';                 /* fin de chaîne */

	d->name = n;       /* met nom dans structure */
	d->age = age;      /* met age '''' */
	d->owner = p;      /* met owner '''' */

	return (d);
}
