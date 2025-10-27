#include "main.h"

/**
 * print_numbers -  prints the numbers, from 0 to 9, followed by a new line.
 * @i: numbers, from 0 to 9, followed by a new line.
 *
 * retrun:
 */

void print_numbers(void)
{
	int i = 0

	while (i < 9)
	{
		_putchar("%d", i);
		i = i + 1;
	}

	return (0);
}
