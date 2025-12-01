#include "main.h"
#include <stdio.h>
/**
* _puts_recursion - prints a string, followed by a new line.
* @s: pointer
*
* Return:
*/

void _puts_recursion(char *s)
{
	if (s[0] == '\0')
	{
		_putchar('\n');  // Affiche un saut de ligne
		return;  // Arrête la récursion
	}

	if (s[0] != '\0')
	{
		_putchar(s[0]); // Affiche le caractère courant
		_puts_recursion(s + 1); // Appelle la fonction avec le caractère suivant
	}
}
