#include <stdlib.h>
#include "main.h"
/**
* _strdup - description courte de ce que fait la fonction
* @str: description du paramètre
*
* Return: description de ce que la fonction retourne
*/

char *_strdup(char *str)
{
	int leng;
	char *sstr;
	int i;

	/* conditions si la chaine est null pour pas avoir d'erreur */
	if (str == 0)
		return (NULL);

	/* calculer la longueur */
	for (leng = 0; str[leng] != '\0'; leng++)
		;

	/* alloue de la memoire +1 car malloc prend pas \0 */
	sstr = malloc((leng + 1) * sizeof(char));
	if (sstr == NULL)
		return (NULL);

	/* transferer les chaine de char avec i*/
	for (i = 0; i < leng; i++)
		sstr[i] = str[i];

	sstr[leng] = '\0';

	return (sstr);
}
