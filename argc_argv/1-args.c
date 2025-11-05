#include <stdio.h>
/**
* main - prints the number of arguments passed into it.
* @argc: integer
* @argv: pointer
*
* Return: return a 0
*/

int main(int argc, char **argv)
{
	(void)argv;
	/* on a pas besoin de argv */
	printf("%d\n", argc - 1);
	/* print nb arguments sans compter le nom du program[0] */
	return (0);
}
