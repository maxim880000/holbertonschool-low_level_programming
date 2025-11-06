#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* pour avoir isdigit */

/*
* number_yn - vérifie si une chaîne contient uniquement des chiffres
* @s: la chaîne à vérifier
*
* Return: 1 si c’est un nombre sinon 0
*/

 /* verfife si la chaine contient que des chiffres */
int number_yn(char *s)
{
	int i;

	/* si la chaine est vide faux */
	if (s[0] == '\0')
		return (0);

		/* on parcours chque caractère du tableau */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* si ce n'est pas un chiffre alors faux r(0) */
		if (!isdigit(s[i]))
			return (0);
	}
		/* autrement si c un chiffre vrai r(1) */
		return (1);
}

/*
* main - additionne tous les nb + argument
* @argc: nb total d’arguments
* @argv: tableau avec  les arguments
*
* Return: 0 si succès, 1 si erreur
*/

int main(int argc, char **argv)
{
	int i;
	int sm = 0;

	/* si il y a pas de nombre r(0) car argc == 1 = argv [0]*/
	if (argc == 1)
	{
		printf("0\n");
		return (O);
	}

	/* on veut parcourir tout depuis argv[1] car [0] = nom, i<nb arg */
	for (i = 1; i < argc; i++)
	{
		/* conditions la chaine ne contient pas que des chiffre alors: */
		if (!number_yn(argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		/* on convertit la chaine en entier et on met dans sm  */
		sm += atoi(argv[i]);
	}

	printf("%d\n", sm);

	return (0);
}
