#include "main.h"

/* Affiche la deuxième moitié d'une chaîne de caractères */

/**
 * puts_half - affiche la deuxième moitié d'une chaîne
 * @str: pointeur vers la chaîne à afficher
 *
 * Si la longueur est impaire, affiche les derniers n caractères
 * où n = (longueur + 1) / 2
 */
void puts_half(char *str)
{
	int len = 0;
	int start_index;
	int i;

	/* Calcule la longueur de la chaîne */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Détermine l'index de départ selon la longueur paire ou impaire */
	if (len % 2 == 0)
	{
		start_index = len / 2;
	}
	else
	{
		start_index = (len / 2) + 1;
	}

	/* Affiche chaque caractère à partir de l'index de départ */
	for (i = start_index; i < len; i++)
	{
		_putchar(str[i]);
	}

	/* Retour à la ligne à la fin */
	_putchar('\n');
}
