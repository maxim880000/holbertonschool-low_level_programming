#include <stdio.h>
#include <stdlib.h>
/**
 * main - multiplies 2 numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 if success, 1 if error
 */

int main(int argc, char **argv)
{
	int a, b, result;
	/* verrifie si y a 2 arg */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	/* ASCII to Integer convert */
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	result = a * b;
	printf("%d\n", result);

	return (0);
}
