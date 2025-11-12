#include <stdlib.h>
#include "main.h"
/**
* malloc_checked - allocates memory using malloc
* @b: unsigned integer
*
* Return: to a pointer
*/
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	/* verifie si malloc a echouer */
	if (ptr == NULL)
		exit(98);

	return (ptr);
}
