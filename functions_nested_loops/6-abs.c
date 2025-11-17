#include "main.h"

/**
 * _abs - Computes the absolute value of an integer.
 * @n: The integer to compute the absolute value of.
 *
 * Return: value of n.
 */
int _abs(int n)
{
/* If n is negative, return its positive equivalent */
if (n < 0)
return (-n);
/* Otherwise, return the number n */
else
return (n);
}
