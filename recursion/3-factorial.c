#include "main.h"
#include <stdio.h>
/**
* factorial - returns the factorial of a given number.
* @n: integer
*
* Return: -1 if n is lower than 0
*/

int factorial(int n)
{
    if (n < 0)          // nombre négatif → impossible
        return (-1);

    if (n == 0 || n == 1)   // 0 et 1 ont toujours 1 comme factorielle
        return (1);

    // sinon on multiplie n par la factorielle de (n-1)
    // la fonction s'appelle elle-même jusqu'à arriver à 1
    return n * factorial(n - 1);
}
