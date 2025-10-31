#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to the first character of the string.
 *
 * Return: The number of characters in the string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
