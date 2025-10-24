#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @n: The number to extract the last digit from.
 *
 * Return: The value of the last digit.
 */
int print_last_digit(int n)
{
	int last;

	last = n % 10;      /* Récupère le dernier chiffre */
	if (last < 0)        /* Si le chiffre est négatif */
		last = -last;    /* le rend positif */

	_putchar(last + '0'); /* Affiche le chiffre */
	return (last);        /* Retourne le chiffre */
}
