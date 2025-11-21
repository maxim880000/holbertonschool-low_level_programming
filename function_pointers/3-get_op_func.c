#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - selects the right function to perform the operation
 * @s: the operator passed as argument ("+", "-", "*", "/", "%")
 *
 * Return: pointer to the function that matches the operator
 * ou NULL
 */
int (*get_op_func(char *s))(int, int)
{
	int i = 0;

	/* tableau des opérateurs et des fonctions associées */
	op_t ops[] = {
		{"+", op_add},   /* addition */
		{"-", op_sub},   /* soustraction */
		{"*", op_mul},   /* multiplication */
		{"/", op_div},   /* division */
		{"%", op_mod},   /* modulo */
		{NULL, NULL}     /* fin du tableau */
	};

	/* on parcourt le tableau jusqu'à la fin */
	while (ops[i].op != NULL)
	{
		/* si l'opérateur correspond exactement (strcmp retourne 0) */
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);   /* on retourne le pointeur vers la fonction */
		i++;
	}

	/* si on n'a rien trouvé → opérateur inconnu */
	return (NULL);
}
