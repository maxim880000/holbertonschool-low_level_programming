#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int x, y, space;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	/* Boucle sur chaque ligne de la pyramide */
	for (x = 1; x <= size; x++)
	{
		/* Affiche les espaces avant les # pour aligner à droite */
		for (space = size - x; space > 0; space--)
			_putchar(' ');

		/* Affiche les # pour la ligne courante */
		for (y = 0; y < x; y++)
			_putchar('#');

		/* Passe à la ligne suivante */
		_putchar('\n');
	}
}
