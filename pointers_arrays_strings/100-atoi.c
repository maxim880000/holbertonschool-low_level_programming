#include "main.h"

/* Convertit une chaîne de caractères en entier (fonction similaire à atoi) */

/**
 * _atoi - convertit une chaîne en entier
 * @s: chaîne de caractères à convertir
 *
 * Return: entier correspondant à la chaîne
 */
int _atoi(char *s)
{
	int i;
	int sign;
	unsigned int result;
	int number_found;

	i = 0;
	sign = 1;          /* signe du nombre (+ ou -) */
	result = 0;        /* résultat final */
	number_found = 0;  /* indique si un chiffre a été trouvé */

	/* Parcourt chaque caractère de la chaîne */
	while (s[i] != '\0')
	{
		/* Si le caractère est un chiffre, on l'ajoute au résultat */
		if (s[i] >= '0' && s[i] <= '9')
		{
			number_found = 1;
			result = (result * 10) + (s[i] - '0');
		}
		/* Si un chiffre a été trouvé et qu'on rencontre autre chose, on arrête */
		else if (number_found == 1)
		{
			break;
		}
		/* Si le caractère est un signe moins, on inverse le signe */
		else if (s[i] == '-')
		{
			sign *= -1;
		}
		/* Si le caractère est un signe plus, on continue sans changer le signe */
		else if (s[i] == '+')
		{
			sign *= 1; /* inutile mais explicite */
		}

		i++;
	}

	/* Retourne le résultat multiplié par le signe */
	return (result * sign);
}
