#include "main.h"
#include <stdio.h>
/**
* is_prime_number - returns 1 if the input integer is a prime number
* @n: integer
* @i: integer 2
*
* Return: retunr 0
*/

int is_prime_number(int n)
{
    if (n < 2)                  // 0, 1 et négatifs → pas premiers
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)         // si un nombre divise n → pas premier
            return 0;
    }
    return 1;                   // sinon → c'est premier !
}
