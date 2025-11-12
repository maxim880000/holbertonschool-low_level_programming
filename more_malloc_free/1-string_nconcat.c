#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings.
 * @s1: pointer char 1
 * @s2: pointer char 2
 * @n: integer
 *
 * Return: return a pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int leng1 = 0;
	unsigned int leng2 = 0;
	unsigned int i;
	unsigned int j;
	char *ptr;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[leng1] != '\0')
		leng1++;

	while (s2[leng2] != '\0')
		leng2++;

	if (n >= leng2)
	n = leng2;

	/* alouer de la memoire */
	ptr = malloc((leng1 + n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);

	/* copier s1 dans ptr */
	for (i = 0; i < leng1; i++)
		ptr[i] = s1[i];

	
	for (j = 0; j < n; j++)
		ptr[i + j] = s2[j];
	/* add le caradtere '\0' */
	ptr[i + j] = '\0';

	return (ptr);
}
