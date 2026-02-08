#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - lit un fichier texte et l'affiche
 * @filename: nom du fichier à lire
 * @letters: nombre de lettres à lire et afficher
 *
 * - Lit jusqu'à 'letters' octets dans un buffer.
 * - Écrit le contenu lu sur la sortie standard.
 * - Vérifie toutes les erreurs et libère la mémoire.
 *
 * Return: nombre de lettres affichées ou 0 en cas d'erreur
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int desc;          /* file descriptor */
	ssize_t rd, wr;    /* bytes read et written */
	char *stack;       /* buffer pour stocker les données */

	if (filename == NULL)
		return (0);

	/* Allouer la mémoire pour stocker les données */
	stack = malloc(sizeof(char) * letters);
	if (stack == NULL)
		return (0);

	/* Ouvrir le fichier en lecture seule */
	desc = open(filename, O_RDONLY);
	if (desc == -1)
	{
		free(stack);
		return (0);
	}

	/* Lire 'letters' octets depuis le fichier */
	rd = read(desc, stack, letters);
	if (rd == -1)
	{
		free(stack);
		close(desc);
		return (0);
	}

	/* Écrire les octets lus sur la sortie standard */
	wr = write(STDOUT_FILENO, stack, rd);
	if (wr == -1 || wr != rd)
	{
		free(stack);
		close(desc);
		return (0);
	}

	free(stack);   /* Libération mémoire */
	close(desc);   /* fermer le fichier */

	return (wr);   /* nombre d'octets affichés */
}
