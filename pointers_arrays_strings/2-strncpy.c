#include "main.h"
/**
* _strncpy - copies a string, at most n bytes
* @dest: destination string
* @src: source string
* @n: maximum number of bytes to copy
*
* Return: pointer to dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int a = 0, b;

	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}

	b = a;
	while (b < n)
	{
		dest[b] = '\0';
		b++;
	}

	return (dest);
}
