#include "main.h"
#include <stdio.h>
/**
* _puts_recursion - prints a string, followed by a new line.
* @s: pointer
*
* Return:
*/

void _puts_recursion(char *s)
{
	if (s[0] == '\0')
	{
		_putchar('\n');
		return;
	}

	if (s[0] != '\0')
	{
		_putchar(s[0]);
		_puts_recursion(s + 1);
	}
}
