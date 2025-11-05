#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argc;  // on ignore argc pas besoin
	printf("%s\n", argv[0]);  // afficher ce qu'il y a dans la 1ER case
	return 0;
}
