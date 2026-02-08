#include <stdio.h>

/* Affiche tous les arguments passés au programme, un par ligne */

/**
 * main - affiche tous les arguments du programme
 * @argc: nombre d’arguments (inclut le nom du programme)
 * @argv: tableau des arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i = 0;

	/* Parcourt chaque argument du tableau argv */
	for (i = 0; i < argc; i++)
	{
		/* Affiche l’argument courant suivi d’un saut de ligne */
		printf("%s\n", argv[i]);
	}

	return (0);
}
