#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/*
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
	if (d == NULL)
		return (NULL);

	d->name = name;
	d->age = age;
	d->owner = owner;

	return (d);
}
