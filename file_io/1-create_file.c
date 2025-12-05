#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Crée un fichier et y écrit un contenu textuel.
 * @filename: Le nom du fichier à créer ou à tronquer.
 * @text_content: La chaîne à écrire dans le fichier.
 *
 * Return: 1 en cas de succès, -1 en cas d'échec.
 */
int create_file(const char *filename, char *text_content)
{
	int desc; /* Descripteur de fichier (File Descriptor). */
	int len = 0; /* Longueur du contenu à écrire. */
	ssize_t bytes_written = 0; /* Nombre d'octets réellement écrits */

	/* Vérification du nom de fichier NULL */
	if (filename == NULL)
		return (-1);

	/* Calcul de la longueur si le contenu n'est pas NULL */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}
	/* Ouvrir ou créer le fichier */
	desc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	/* Vérification de l'échec de open/create */
	if (desc == -1)
		return (-1);
	/* Écrire le contenu (si len > 0) */
	if (len > 0)
	{
		bytes_written = write(desc, text_content, len);

		/* Vérif de l'échec d'écriture (-1) ou de l'écriture partielle */
		if (bytes_written == -1 || bytes_written != len)
		{
			close(desc); /* Doit fermer le descripteur ouvert */
			return (-1);
		}
	}
	/* Fermeture du descripteur */
	/* Retourne -1 si la fermeture échoue */
	if (close(desc) == -1)
		return (-1);
	return (1); /* Succès */
}
