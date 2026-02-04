#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
* main - point d'entrée du programme
*
* Return: toujours 0 (succès)
*/
int main(void)
{
	int n;

	/* srand(time(0)) : initialise le générateur de nombres aléatoires */
	srand(time(0));

	/* rand() génère un nombre aléatoire entre 0 et RAND_MAX
	RAND_MAX est la valeur maximale possible renvoyée par rand()
	RAND_MAX/2 : on décale le nombre pour qu'il puisse être positif ou négatif,
	centré autour de 0 */
	n = rand() - RAND_MAX / 2;

	/* Vérifie si le nombre est positif, nul ou négatif */
	if (n > 0)
		printf("%d is positive\n", n);
	else if (n == 0)
		printf("%d is zero\n", n);
	else
		printf("%d is negative\n", n);

	/* Retourne 0 pour indiquer succès */
	return (0);
}
