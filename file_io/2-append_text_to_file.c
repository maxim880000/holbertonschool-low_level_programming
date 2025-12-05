#include "main.h"

/**
 * append_text_to_file - Ajoute du texte à la fin d'un fichier
 * @filename: Nom du fichier
 * @text_content: Texte à ajouter
 *
 * Return: 1 si succès, -1 si échec
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int desc;      /* Descripteur de fichier */
	int len = 0;   /* Longueur du texte */
	ssize_t bytes; /* Octets écrits */

	/* Si pas de nom de fichier */
	if (filename == NULL)
		return (-1);

	/* Si pas de texte à écrire */
	if (text_content == NULL)
	{
		/* Vérifie juste que le fichier existe */
		desc = open(filename, O_WRONLY | O_APPEND);
		if (desc == -1)
			return (-1);
		close(desc);
		return (1);
	}

	/* Ouvre le fichier en mode ajout */
	desc = open(filename, O_WRONLY | O_APPEND);
	if (desc == -1)
		return (-1);

	/* Calcule la longueur du texte */
	while (text_content[len])
		len++;

	/* Écrit le texte dans le fichier */
	bytes = write(desc, text_content, len);

	/* Ferme le fichier */
	close(desc);

	/* Vérifie si l'écriture a réussi */
	if (bytes == -1)
		return (-1);

	return (1);
}
