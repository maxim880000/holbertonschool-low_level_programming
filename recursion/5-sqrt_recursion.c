#include "main.h"
#include <stdio.h>
/**
* _sqrt_helper - recursively finds the natural square root of n
* @n: the number to find the square root of
* @i: the current candidate being tested
*
* Return: the square root of n if it exists, -1 otherwise
*/

int _sqrt_helper(int n, int i)
{
		if (n < 0)
			return (-1);

		if (i * i == n)
			return (i);

		if (i * i > n)
			return (-1);

		return (_sqrt_helper(n, i + 1));
}

/**
* _sqrt_recursion - returns the natural square root of a number
* @n: the number to find the square
*
* Return: the square root of n if it exists, -1 otherwise
*/

int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 0));
}
