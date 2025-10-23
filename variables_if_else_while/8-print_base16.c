#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char letter;

	/* afficher les chiffres de 0 à 9 */
	for (n = 0; n < 10; n++)
	{
		putchar(n + '0');
	}

	/* afficher les lettres de a à f */
	for (letter = 'a'; letter <= 'f'; letter++)
	{
		putchar(letter);
	}

	putchar('\n');
	return (0);
}
