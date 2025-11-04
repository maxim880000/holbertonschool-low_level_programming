#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element
 * @size: size of the square
 *
 * Return: nothing
 */
void print_diagsums(int *a, int size)
{
	int i, b = 0, c = 0;

	for (i = 0; i < size; i++)
	{
		b += *(a + i * size + i);
		c += *(a + i * size + (size - 1 - i));
	}
	printf("%d, %d\n", b, c);
}
