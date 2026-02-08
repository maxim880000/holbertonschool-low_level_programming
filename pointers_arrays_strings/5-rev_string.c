#include "main.h"

/* Inverse une chaîne de caractères "sur place" */

/**
 * rev_string - inverse une chaîne de caractères
 * @s: pointeur vers la chaîne à inverser
 *
 * Description: utilise la méthode des deux pointeurs pour échanger les caractères
 */
void rev_string(char *s)
{
	int start = 0;
	int end = 0;
	char temp;

	/* Trouve la fin de la chaîne */
	while (s[end] != '\0')
	{
		end++;
	}
	end--; /* Positionne sur le dernier caractère réel */

	/* Échange les caractères du début et de la fin jusqu’au milieu */
	while (start < end)
	{
		temp = s[start];    /* Stocke temporairement le caractère de début */
		s[start] = s[end];  /* Place le caractère de fin au début */
		s[end] = temp;      /* Place le caractère de début à la fin */

		start++; /* Avance le pointeur de début */
		end--;   /* Recule le pointeur de fin */
	}
}
