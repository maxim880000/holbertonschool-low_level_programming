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
    if (d == NULL)
        return;

    if (d->name != NULL)
        printf("Name: %s\n", d->name);
    else
        printf("Name: (nil)\n");

    printf("Age: %f\n", d->age);

    if (d->owner != NULL)
        printf("Owner: %s\n", d->owner);
    else
        printf("Owner: (nil)\n");
}
