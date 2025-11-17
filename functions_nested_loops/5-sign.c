#include "main.h"

/**
 * print_sign - verify all the line
 * @n: The number to check.
 *
 * Return: Always 0.
 */
int print_sign(int n)
{
/* Check if number is positive */
if (n > 0)
{
_putchar('+');
return (1);
}
/* Check if number is zero */
else if (n == 0)
{
_putchar('0');
return (0);
}
/* Otherwise, number is negative */
else
{
_putchar('-');
return (-1);
}
}
