#include "function_pointers.h"

/**
* print_name - prints a name
* @name: name of the person
* @f: pointer to function which will print the name
*/
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		/* f: variable qui contient l'adresse d'une fonction */
		/* f(name) → va à cette adresse, exécute la fonction et lui passe name */
		f(name);
	}
}
