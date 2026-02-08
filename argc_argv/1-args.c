#include <stdio.h>

/* Affiche le nombre d’arguments passés au programme, sans compter le nom du programme */

/**
 * main - affiche le nombre d’arguments passés
 * @argc: nombre total d’arguments (inclut le nom du programme)
 * @argv: tableau des arguments (non utilisé ici)
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	/* On n’utilise pas argv, donc on le "void" pour éviter un warning */
	(void)argv;

	/* Affiche argc - 1 pour ne pas compter le nom du programme */
	printf("%d\n", argc - 1);

	return (0);
}
