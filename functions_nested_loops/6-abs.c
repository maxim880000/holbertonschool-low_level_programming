#include "main.h"

/**
 * _abs - Calcule la valeur absolue d’un entier
 * @n: L'entier dont on veut calculer la valeur absolue.
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
