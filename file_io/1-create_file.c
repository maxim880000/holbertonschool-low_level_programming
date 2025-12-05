#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Crée un fichier et y écrit un contenu textuel.
 * @filename: Le nom du fichier à créer ou à tronquer.
 * @text_content: La chaîne NULL-terminated à écrire dans le fichier.
 *
 * Return: 1 en cas de succès, -1 en cas d'échec.
 */
int create_file(const char *filename, char *text_content)
{
	int desc;
	int len = 0;         /* Initialise la longueur à 0 */
	ssize_t w_bytes = 0;

	/* Vérification #1: filename NULL */
	if (filename == NULL)
		return (-1);

	/* Calcul de la longueur si le contenu n'est pas NULL */
	if (text_content != NULL)
	{
		while (text_content[len]) /* Calcul manuel de la longueur (équivalent à _strlen) */
			len++;
	}

	/* O_CREAT: Crée si n'existe pas. O_WRONLY: Écriture seule. O_TRUNC: Tronque si existe. */
	/* 0600: rw------- (Permission requise) */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	/* Vérification #2: Échec dse open/create */
	if (desc == -1)
		return (-1);

	/* Écriture uniquement si il y a du contenu (len > 0) */
	if (len > 0)
	{
		w_bytes = write(desc, text_content, len);

		/* Vérification #3: Échec de write ou écriture partielle */
		if (w_bytes == -1 || w_bytes != len)
		{
			close(desc); /* Tente la fermeture avant de retourner l'erreur */
			return (-1);
		}
	}

	/* Vérification #4: Échec de la fermeture */
	if (close(desc) == -1)
		return (-1);

	return (1);
}
