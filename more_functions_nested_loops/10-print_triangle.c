#include "main.h"
/**
* print_triangle - print a triangle 
* @size: 'rke
*
* Return : return 0
*/

void print_triangle(int size)
{
    int line;
    int espace;
    int diese;

    if (size <= 0)
    {
        _putchar('\n');
        return;
    }

    for (line = 1; line <= size; line++)
    {
        for (espace = 0; espace < (size - line); espace++)
        {
            _putchar(' ');
        }
        for (diese = 0; diese < line; diese++)
        {
            _putchar('#');
        }
        _putchar('\n');
    }
}