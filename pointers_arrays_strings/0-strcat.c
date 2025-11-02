#include "main.h"
/**
* _strcat - fonction pour coller deux partie
*
* Return : return(dest)
*/

char *_strcat(char *dest, char *src)
{
	int l_dest = 0;
	int l_src = 0;

	while (dest[l_dest] != '\0')
	{
		l_dest++;
	}

	while (src[l_src] != '\0')
	{
		dest[l_dest] = src[l_src];
		l_dest++;
		l_src++;
	}

	dest[l_dest] = '\0';

	return (dest);
}
