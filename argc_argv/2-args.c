#include <stdio.h>
/**
 * main - print all arguments it receives.
 * @argc: integer
 * @argv: pointer
 *
 * Return: return 0
 */

int main(int argc, char **argv)
{
	int i = 0;
	/*  continue tant que i < argc */
	for (i = 0; i < argc; i++)
	{
		/* print chaque argument sur une ligne */
		printf("%s\n", argv[i]);
	}
		return (0);
}
