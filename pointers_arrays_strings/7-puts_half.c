#include "main.h"

/**
 * puts_half - Affiche la deuxième moitié d'une chaîne de caractères.
 * @str: Le pointeur vers la chaîne.
 *
 * Si impaire, affiche les n derniers
 * où n = (longueur + 1) / 2.
 */
void puts_half(char *str)
{
	int len = 0;
	int start_index;
	int i;

	while (str[len] != '\0')
	{
		len++;
	}

	if (len % 2 == 0)
	{
		start_index = len / 2;
	}
	else
	{
		start_index = (len / 2) + 1;
	}

	for (i = start_index; i < len; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
