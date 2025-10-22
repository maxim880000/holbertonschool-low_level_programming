#include <stdio.h>

/**
 * main - Prints alphabet in lowercase and uppercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* Alphabet minuscule */
	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	/* Alphabet majuscule */
	for (letter = 'A'; letter <= 'Z'; letter++)
		putchar(letter);

	/* Retour à la ligne */
	putchar('\n');

	return (0);
}
