#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0.
 *
 * Return: void
 */
void times_table(void)
{
int i, j, product;


/* Loop through rows from 0 to 9 */
for (i = 0; i <= 9; i++)
{
/* Loop through columns from 0 to 9 */
for (j = 0; j <= 9; j++)
{
/* Compute the product of i and j */
product = i * j;


/* First number in each row is always 0 */
if (j == 0)
_putchar('0');
else
{
/* Print separator between values */
_putchar(',');
_putchar(' ');


/* Add spacing for single-digit numbers */
if (product < 10)
_putchar(' ');
else
/* Print tens digit */
_putchar((product / 10) + '0');


/* Print ones digit */
_putchar((product % 10) + '0');
}
}
/* Move to next line after each row */
_putchar('\n');
}
}
