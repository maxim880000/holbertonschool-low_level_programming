#include "main.h"

/**
 * _puts - Affiche une chaîne de caractères, suivie d'une nouvelle ligne.
 * @str: Le pointeur (la "carte au trésor") vers la chaîne à afficher.
 *
 * trouve le "drapeau rouge" de fin de chaîne ('\0').
 */
void _puts(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
