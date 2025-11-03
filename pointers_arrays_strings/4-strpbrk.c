#include "main.h"
/**
* strpbrk - searches a string for any of a set of bytes.
* @s: string that we need to check
* @accept: almost the same than s
*
* Return: return
*/

char *_strpbrk(char *s, char *accept)
{
	int i;
	int j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (&s[i]);
		}
	}
	return (NULL);
}
