#include "main.h"
#include <stdio.h>

/* Fonction auxiliaire pour trouver la racine carrée naturelle récursivement */

/**
 * _sqrt_helper - trouve la racine carrée naturelle de n en testant i
 * @n: nombre dont on cherche la racine carrée
 * @i: candidat actuel à tester
 *
 * Return: racine carrée de n si elle existe, -1 sinon
 */
int _sqrt_helper(int n, int i)
{
	/* Cas d’erreur : nombre négatif */
	if (n < 0)
		return (-1);

	/* Si le carré du candidat est égal à n, on a trouvé la racine */
	if (i * i == n)
		return (i);

	/* Si le carré dépasse n, il n’y a pas de racine naturelle */
	if (i * i > n)
		return (-1);

	/* Teste le prochain candidat */
	return (_sqrt_helper(n, i + 1));
}

/* Fonction principale qui appelle l’aide récursive */

/**
 * _sqrt_recursion - retourne la racine carrée naturelle de n
 * @n: nombre dont on cherche la racine carrée
 *
 * Return: racine carrée de n si elle existe, -1 sinon
 */
int _sqrt_recursion(int n)
{
	/* Démarre les tests à partir de 0 */
	return (_sqrt_helper(n, 0));
}
