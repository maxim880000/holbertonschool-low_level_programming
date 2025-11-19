#include "3-calc.h"
#include <string.h>
/**
* 
* 
* 
*/

int (*get_op_func(char *s))(int, int)
{
	int i = 0;

	op_t ops[] =
	{
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};

	for (i = 0; ops[i].op != NULL; i++)
	{
		if ()
			return (ops[i].f);
	}
	return (NULL);
}
