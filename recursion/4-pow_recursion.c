#include "main.h"
#include <stdio.h>
/**
* _pow_recursion - returns the value of x raised to the power of y.
* @y: parametres
* @x: parametres.
*
* Return: (x * _pow_recursion(x, y - 1));
*/

int _pow_recursion(int x, int y)
{
    if (y < 0)          // puissance négative → pas possible ici
        return (-1);

    if (y == 0)         // n'importe quoi à la puissance 0 = 1
        return (1);

    // on rappelle la fonction avec y-1
    return x * _pow_recursion(x, y - 1);
}
