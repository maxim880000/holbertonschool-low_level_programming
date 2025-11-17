#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: starting number
 *
 * Description: This function prints all natural numbers from n
 * to 98, separated by a comma and a space, followed by a new line.
 * Numbers are printed in order, whether ascending or descending.
 */
void print_to_98(int n)
{
    /* If n is less than or equal to 98, count up */
    if (n <= 98)
    {
        for (; n <= 98; n++)
        {
            /* When reaching 98, print final number with newline */
            if (n == 98)
                printf("%d\n", n);
            else
                /* Print number followed by a comma and space */
                printf("%d, ", n);
        }
    }
    else
    {
        /* If n is greater than 98, count down */
        for (; n >= 98; n--)
        {
            if (n == 98)
                printf("%d\n", n);
            else
                printf("%d, ", n);
        }
    }
}
