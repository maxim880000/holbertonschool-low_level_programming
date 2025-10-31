#include "main.h"

/**
 * puts2 - Affiche un caractère sur deux d'une chaîne.
 * @str: Le pointeur vers la chaîne à afficher.
 *
 * Description: Commence au premier caractère (index 0) et affiche
 * tout les caractère index pair
 */
void puts2(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
		i++;
	}
	_putchar('\n');
}

