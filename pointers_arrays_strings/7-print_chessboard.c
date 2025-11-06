#include <stdio.h>
#include "main.h"
/**
 * print_chessboard - prints an 8x8 chessboard
 * @a: pointer to a 2D array (8x8) of chars
 */

void print_chessboard(char (*a)[8])
{
	int x, y;

	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 8; y++)
		{
			_putchar(a[x][y]);
		}
		_putchar('\n');
	}
}
