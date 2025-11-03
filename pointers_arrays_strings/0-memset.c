#include "main.h"
/**
* _memset - fills memory with a constant byte.
* @s: char caractere.
* @b: char2.
* @n: unsigned int n.
* Return: pointer to the memory s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
