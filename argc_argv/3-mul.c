#include <stdio.h>
#include <stdlib.h>

/* Multiplie deux nombres passés en arguments */

/**
 * main - multiplie deux entiers passés en arguments
 * @argc: nombre d’arguments
 * @argv: tableau des arguments
 *
 * Return: 0 si succès, 1 si erreur (nombre d’arguments incorrect)
 */
int main(int argc, char **argv)
{
	int a, b, result;

	/* Vérifie qu’il y a exactement deux arguments */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	/* Conversion ASCII → int des arguments */
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	/* Calcule le produit */
	result = a * b;

	/* Affiche le résultat */
	printf("%d\n", result);

	return (0);
}
