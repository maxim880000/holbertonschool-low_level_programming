#include "main.h"

/**
 * rev_string - Inverse une chaîne de caractères "sur place" (in-place).
 * @s: Le pointeur vers la chaîne à inverser.
 *
 * Description: Utilise la méthode des "deux pointeurs".
 */
void rev_string(char *s)
{
	int start = 0;
	int end = 0;
	char temp;

	while (s[end] != '\0')
	{
		end++;
	}
	end--;

	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}

