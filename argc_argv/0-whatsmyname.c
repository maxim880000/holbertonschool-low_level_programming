#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	/* On ignore argc car il n'est pas utilisé */
	(void)argc;
	/* Affiche le nom du programme (argv[0]) */
	printf("%s\n", argv[0]);
	return (0);
}
