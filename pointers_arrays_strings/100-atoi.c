#include "main.h"
/**
 * _atoi - Convertit une chaîne de caractères en entier.
 * @s: La chaîne de caractères à convertir.
 *
 * Return: L'entier converti à partir de la chaîne.
 */
int _atoi(char *s)
{
	int i;
	int sign;
	unsigned int result;
	int digit_found;

	i = 0;
	sign = 1;
	result = 0;
	digit_found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			if (digit_found)
				break;
			sign *= -1;
		}
		else if (s[i] == '+')
		{
			if (digit_found)
				break;
			sign *= 1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit_found = 1;
			result = (result * 10) + (s[i] - '0');
		}
		else
		{
			if (digit_found)
				break;
		}
		i++;
	}
		return(digit_found)
}
