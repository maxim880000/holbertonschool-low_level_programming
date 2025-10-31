#include "main.h"
/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: pointer to the string
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	for (i--; i >= 0; i--)
		_putchar(s[i]);

	_putchar('\n');
}
