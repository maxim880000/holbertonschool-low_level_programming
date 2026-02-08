#include "main.h"
#include <stdio.h>

/* Calcule la factorielle d’un nombre en utilisant la récursion */

/**
 * factorial - retourne la factorielle d’un entier
 * @n: entier dont on veut la factorielle
 *
 * Return: -1 si n < 0, sinon la factorielle
 */
int factorial(int n)
{
    /* Cas d’erreur : nombre négatif */
    if (n < 0)
        return (-1);

    /* Cas de base : 0! = 1! = 1 */
    if (n == 0 || n == 1)
        return (1);

    /* Appel récursif : n! = n * (n-1)! */
    return n * factorial(n - 1);
}
