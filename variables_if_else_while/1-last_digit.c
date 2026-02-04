#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* génère un nombre aléatoire, récupère son dernier chiffre
et indique si ce chiffre est >5, =0, ou <6 et non nul */

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	int n, last_digit;

	/* Initialise le générateur de nombres aléatoires
	pour que rand() donne des résultats différents à chaque exécution */
	srand(time(0));

	/* rand() génère un nombre aléatoire entre 0 et RAND_MAX
	On soustrait RAND_MAX/2 pour centrer le nombre autour de 0 */
	n = rand() - RAND_MAX / 2;

	/* Récupère le dernier chiffre du nombre */
	last_digit = n % 10;

	/* Affiche le nombre et son dernier chiffre */
	printf("Last digit of %d is %d ", n, last_digit);

	/* Vérifie si le dernier chiffre est >5, =0, ou autre */
	if (last_digit > 5)
	{
		printf("and is greater than 5\n");
	}
	else if (last_digit == 0)
	{
		printf("and is 0\n");
	}
	else
	{
		printf("and is less than 6 and not 0\n");
	}

	/* Retourne 0 pour indiquer succès */
	return (0);
}
