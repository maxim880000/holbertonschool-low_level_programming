#include "dog.h"
/*
* init_dog - initialize a variable of type struct dog
* @d: pointer 
* @name: char
* @age: interger 
* @owner: char 
*/
void init_dog(struct dog *d, char *name, float age, char *owner);
{
	if (d == NUll)
		return (NULL);

	d -> name = name
	d -> age = age 
	d -> owner =owner

	return (d);
}
