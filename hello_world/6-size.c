#include <stdio.h>

/**
* main - prints the size of various types
*
* Return: Always 0 (Success)
*/
int main(void)
{
	/* Affiche la taille d'un char */
	printf("Size of a char: %zu byte(s)\n", sizeof(char));

	/* Affiche la taille d'un int */
	printf("Size of an int: %zu byte(s)\n", sizeof(int));

	/* Affiche la taille d'un long int */
	printf("Size of a long int: %zu byte(s)\n", sizeof(long int));

	/* Affiche la taille d'un long long int */
	printf("Size of a long long int: %zu byte(s)\n", sizeof(long long int));

	/* Affiche la taille d'un float */
	printf("Size of a float: %zu byte(s)\n", sizeof(float));

	/* Retourne 0 pour indiquer succès */
	return (0);
}
