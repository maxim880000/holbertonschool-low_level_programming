#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/* Print spaces */
		for (j = size - i; j > 0; j--)
			_putchar(' ');

		/* Print # */
		for (k = 0; k < i; k++)
			_putchar('#');

		_putchar('\n');
	}
}
