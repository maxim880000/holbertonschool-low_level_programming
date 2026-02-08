#include <unistd.h>

/* Écrit un caractère sur la sortie standard */

/**
 * _putchar - affiche un caractère sur stdout
 * @c: caractère à afficher
 *
 * Return: 1 en cas de succès,
 *         -1 en cas d'erreur (errno est défini)
 */
int _putchar(char c)
{
	/* write écrit 1 octet (&c) sur la sortie standard (1 = stdout) */
	return (write(1, &c, 1));
}
