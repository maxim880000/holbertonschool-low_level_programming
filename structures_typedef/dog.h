#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure représentant un chien
 * @name: nom du chien
 * @age: âge du chien
 * @owner: nom du propriétaire
 *
 * Description: Cette structure contient les infos
 * d’un chien,son nom, son âge et son propriétaire.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif
