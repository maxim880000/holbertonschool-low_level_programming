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
 * Return: 0 si succès
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;     /* descripteurs et nb d’octets lus/écrits */
	char buf[1024];               /* buffer de 1024 octets */

	if (argc != 3)                                        /* mauvais nombre d’args */
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);                    /* ouvre fichier source */
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* crée/tronque fichier destination avec permissions rw-rw-r-- */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	while ((r = read(fd_from, buf, 1024)) > 0)            /* copie par blocs de 1024 */
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)                        /* erreur ou écriture incomplète */
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (r == -1)                                          /* erreur de lecture */
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	if (close(fd_from) == -1)                             /* fermeture fichier source */
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)                               /* fermeture fichier destination */
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
