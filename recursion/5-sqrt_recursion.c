#include "main.h"
#include <stdio.h>
/**
* _sqrt_recursion - returns the natural square root of a number.
* _sqrt_helper - helper fonction
* @n: integer
* @i: integer pour parcourir
*
* Return: la racine
*/
int _sqrt_helper(int n, int i);

int _sqrt_recursion(int n)
{
	return(_sqrt_helper(n, 0));
}
int _sqrt_helper(int n, int i)
{
		if (n < 0)
			return (-1);

		if (i * i == n)
			return (i);

		if (i * i != n)
			return (-1);

		return (_sqrt_helper(n, i + 1));
}
