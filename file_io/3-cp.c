#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - copie le contenu d’un fichier vers un autre
 * @argc: nombre d’arguments
 * @argv: tableau des arguments
 *
 * - Vérifie le nombre d’arguments (exactement 2 fichiers)
 * - Lit le fichier source par blocs de 1024 octets
 * - Écrit dans le fichier destination avec création/tronquage
 * - Gère les erreurs : lecture, écriture, ouverture et fermeture
 *
 * Return: 0 si succès
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;     /* descripteurs et nb d’octets lus/écrits */
	char buf[1024];               /* buffer de 1024 octets */

	/* Vérifie le nombre d’arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Ouvre le fichier source en lecture seule */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Crée/tronque le fichier destination avec permissions rw-rw-r-- */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	/* Copie par blocs de 1024 octets */
	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)   /* erreur ou écriture incomplète */
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (r == -1)  /* erreur de lecture */
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	/* Ferme le fichier source */
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	/* Ferme le fichier destination */
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
