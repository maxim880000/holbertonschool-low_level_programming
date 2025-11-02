#include "main.h"
/**
 * _atoi - Convertit une chaîne de caractères en entier.
 * @s: La chaîne de caractères à convertir.
 *
 * Return: L'entier converti.
 */
int _atoi(char *s)
{
	int i;
	int sign;
	unsigned int result;
	int number_found;

	i = 0;
	sign = 1;
	result = 0;
	number_found = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			number_found = 1;
			result = (result * 10) + (s[i] - '0');
		}
		else if (number_found == 1)
		{
			break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] == '+')
		{
			/* On ne fait rien au signe, on continue */
			sign *= 1;
		}

		i++;
	}

	return (result * sign);
}
