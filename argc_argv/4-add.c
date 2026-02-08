#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* pour utiliser isdigit */

/* Vérifie si une chaîne contient uniquement des chiffres */

/**
 * number_yn - retourne 1 si la chaîne contient uniquement des chiffres, 0 sinon
 * @s: chaîne à vérifier
 *
 * Return: 1 si chaîne valide, 0 sinon
 */
int number_yn(char *s)
{
	int i;

	/* Chaîne vide → pas un nombre */
	if (s[0] == '\0')
		return (0);

	/* Parcourt chaque caractère */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Si un caractère n’est pas un chiffre, retourne 0 */
		if (!isdigit(s[i]))
			return (0);
	}

	/* Tous les caractères sont des chiffres → retourne 1 */
	return (1);
}

/* Additionne tous les nombres positifs passés en arguments */

/**
 * main - additionne les nombres passés en arguments
 * @argc: nombre d’arguments
 * @argv: tableau des arguments
 *
 * Return: 0 si succès, 1 si erreur
 */
int main(int argc, char **argv)
{
	int i;
	int sm = 0;

	/* Aucun nombre passé → affiche 0 */
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	/* Parcourt tous les arguments à partir de argv[1] */
	for (i = 1; i < argc; i++)
	{
		/* Si l’argument n’est pas un nombre, affiche Error et quitte */
		if (!number_yn(argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		/* Convertit la chaîne en entier et ajoute au total */
		sm += atoi(argv[i]);
	}

	/* Affiche le total */
	printf("%d\n", sm);

	return (0);
}
