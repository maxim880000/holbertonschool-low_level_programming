#include "main.h"
#include <stdio.h>
/**
* is_prime_number - returns 1 if the input integer is a prime number
* @n: integer
* @i: integer 2
*
* Return: retunr 0
*/

int is_prime_number(int n, int i)
{
	if (n < 2)
		return (0);

	if (i * i > n)
		return (1);

	if (n % i == 0)
		return (0);

	return (is_prime_number(n, i + 1));
}
