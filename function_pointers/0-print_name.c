#include "function_pointers.h"
#include <stddef.h>

/**
* print_name - prints a name
* @name: name of the person
* @f: pointer to function which will print the name
*
* Return: nothing
*/

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	/* f: variable qui contient l'adresse d'une fonction */
	/* f(name) → va à cette adresse, exécute la fonction et lui passe name */
	f(name);
}
