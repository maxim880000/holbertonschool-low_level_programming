#include "main.h"

/**
 * append_text_to_file - Ajoute du texte à la fin d'un fichier
 * @filename: Nom du fichier
 * @text_content: Texte à ajouter
 *
 * Points clés :
 * - Ouvre le fichier en mode ajout (O_APPEND).
 * - Vérifie l'existence du fichier si text_content est NULL.
 * - Écrit le texte fourni à la fin.
 * - Retourne 1 si succès, -1 si erreur (open/write).
 *
 * Return: 1 si succès, -1 si échec
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int desc;      /* Descripteur de fichier */
	int len = 0;   /* Longueur du texte */
	ssize_t bytes; /* Octets écrits */

	/* Vérifie le nom du fichier */
	if (filename == NULL)
		return (-1);

	/* Vérifie si text_content est NULL */
	if (text_content == NULL)
	{
		/* Juste vérifier que le fichier existe et est accessible en écriture */
		desc = open(filename, O_WRONLY | O_APPEND);
		if (desc == -1)
			return (-1);
		close(desc);
		return (1);
	}

	/* Ouvre le fichier en écriture, mode ajout */
	desc = open(filename, O_WRONLY | O_APPEND);
	if (desc == -1)
		return (-1);

	/* Calculer la longueur du texte à écrire */
	while (text_content[len])
		len++;

	/* Écrire le texte à la fin du fichier */
	bytes = write(desc, text_content, len);

	/* Fermer le fichier */
	close(desc);

	/* Vérifier que l'écriture a réussi */
	if (bytes == -1)
		return (-1);

	return (1); /* Succès */
}
