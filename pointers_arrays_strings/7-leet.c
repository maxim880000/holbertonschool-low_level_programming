#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: pointer to the string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *str)
{
	int a, b;
	char letters[] = "aAeEoOtTlL";
	char codes[] = "4433007711";

	for (a = 0; str[a] != '\0'; a++)
	{
		for (b = 0; letters[b] != '\0'; b++)
		{
			if (str[a] == letters[b])
			{
				str[a] = codes[b];
				break;
			}
		}
	}

	return (str);
}
