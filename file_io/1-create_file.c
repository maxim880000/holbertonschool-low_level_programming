#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - crée un fichier et y écrit un contenu textuel
 * @filename: nom du fichier à créer ou à tronquer
 * @text_content: texte à écrire dans le fichier
 *
 * - Ouvre ou crée le fichier avec droits 600.
 * - Tronque le fichier si il existait.
 * - Écrit le contenu fourni dans le fichier.
 * - Vérifie toutes les erreurs (open, write, close).
 *
 * Return: 1 si succès, -1 en cas d'erreur
 */
int create_file(const char *filename, char *text_content)
{
	int desc;              /* descripteur de fichier */
	int len = 0;           /* longueur du contenu à écrire */
	ssize_t bytes_written; /* nombre d'octets écrits */

	if (filename == NULL)
		return (-1);

	/* Calculer la longueur du texte si non NULL */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	/* Ouvrir ou créer le fichier en écriture, permissions 600 */
	desc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (desc == -1)
		return (-1);

	/* Écrire le contenu dans le fichier */
	if (len > 0)
	{
		bytes_written = write(desc, text_content, len);
		if (bytes_written == -1 || bytes_written != len)
		{
			close(desc);
			return (-1);
		}
	}

	/* Fermer le fichier */
	if (close(desc) == -1)
		return (-1);

	return (1); /* succès */
}
