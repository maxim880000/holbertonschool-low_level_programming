#include "main.h"
#include <stdio.h>
/**
* is_prime_number - returns 1 if the input integer is a prime number, otherwise return 0.
* @n: integer 
*
* Return: retunr 0
*/


int is_prime_number(int n);
{
	int i = 0;

	if (n < 2)
		return (0);
	
	if (i * i > n )
		return (1);

	if (n % i == 0)
		return (is_prime_number(n, i + 1));

}
