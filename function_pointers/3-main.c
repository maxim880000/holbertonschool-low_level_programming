#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - petite calculatrice qui fait + - * / %
 * @argc: nb d'arguments on a donné au programme
 * @argv: les arguments
 *
 * Return: 0 si tout est bon
 */
int main(int argc, char *argv[])
{
	int a; /* premier nombre */
	int b; /* deuxième nombre */
	char *op; /* opérateur : +,-, *,/,% */
	int (*fonction)(int, int); /* pointeur vers la fonction qui va calculer */

	/* 1ER TEST : est-ce qu'on a bien 4 arguments ? */
	/* Si on a moins ou plus → c'est faux */
	if (argc != 4)
	{
		printf("Error\n"); /* on affiche "Error" */
		exit(98); /* on ARRÊTE TOUT avec exit 98 */
	}
	/* On récupère les 3 trucs importants */
	a = atoi(argv[1]); /* transforme "10" en nombre 10 */
	op = argv[2]; /* op = "+" ou "-" ou "*" et. */
	b = atoi(argv[3]); /* transforme "5" en nombre 5 */

	/* 2E TEST : est-ce que l'opérateur est bon ? */
	/* On demande à get_op_func de nous donner la bonne fonction */
	fonction = get_op_func(op);

	if (fonction == NULL) /* si elle retourne NULL = opérateur inconnu */
	{
		printf("Error\n");
		exit(99); /* erreur 99 = mauvais opérateur */
	}

	/* 3E TEST : est-ce qu’on essaie de diviser par zéro ? */
	/* C'est interdit en maths → donc interdit ici aussi */
	if ((op[0] == '/' || op[0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100); /* erreur 100 = division par zéro */
	}
	/* Si on arrive et tout est bon */
	/* On fait le calcul et on affiche le résultat */
	printf("%d\n", fonction(a, b));

	return (0); /* tout s’est bien passé */
}
