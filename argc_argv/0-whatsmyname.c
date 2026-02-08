#include <stdio.h>

/* Affiche le nom du programme */

/**
 * main - affiche le nom du programme
 * @argc: nombre d’arguments (non utilisé ici)
 * @argv: tableau des arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	/* On ignore argc car il n’est pas utilisé */
	(void)argc;

	/* Affiche le nom du programme, argv[0] */
	printf("%s\n", argv[0]);

	return (0);
}
