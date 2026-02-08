#include "main.h"
#include <stdio.h>

/* Calcule x élevé à la puissance y en utilisant la récursion */

/**
 * _pow_recursion - retourne x^y
 * @x: base
 * @y: exposant
 *
 * Return: résultat de x^y, -1 si y < 0
 */
int _pow_recursion(int x, int y)
{
    /* Cas d’erreur : exposant négatif non géré */
    if (y < 0)
        return (-1);

    /* Cas de base : n'importe quelle base à la puissance 0 = 1 */
    if (y == 0)
        return (1);

    /* Appel récursif : x^y = x * x^(y-1) */
    return x * _pow_recursion(x, y - 1);
}
