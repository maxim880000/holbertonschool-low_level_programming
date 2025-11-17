#include "main.h"
#include <stdio.h>
/**
* print_name - function that prints a name
* @name: pointer name
* @f: pointer
*
*/

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name); /* f: variable (adresse d'1 fonction)*/
	/* va à & dans f, exécute la fct° dedant, donner name comme argmt*/
}
