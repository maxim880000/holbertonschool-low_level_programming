#include "main.h"
/**
* _strspn - gets the length of a prefix substring.
* @s: pointer
* @accept: pointer
*
* Return: a int i
*/

unsigned int _strspn(char *s, char *accept)
{
	int i;
	int j;
	int t = 0;

	for (i = 0; s[i] != '\0'; i++)
	{

		for (j = 0; accept[j] != '\0'; j++)
		{
			t = 0;
			if (s[i] == accept[j])
			{
				t = 1;
				break;
			}
		}

		if (t == 0)
			return (i);
	}

	return (i);
}
