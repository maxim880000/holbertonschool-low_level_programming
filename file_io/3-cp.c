#include "main.h" /* Inclut le fichier d'en-tête principal pour les prototypes et les macros */

#define BUFFER_SIZE 1024 /* Définit la taille du buffer de lecture/écriture à 1024 octets */

/**
 * error_exit - Affiche un message d'erreur sur stderr et termine le programme.
 * @code: Le code de sortie à utiliser (97, 98, 99, ou 100).
 * @msg: Le message d'erreur formaté à afficher.
 * @arg: L'argument (nom de fichier ou descripteur) à insérer dans le message.
 *
 * Return: Ne retourne jamais car elle appelle exit().
 */
void error_exit(int code, const char *msg, const char *arg)
{
	/* Affiche le message d'erreur formaté sur la sortie d'erreur standard (STDERR_FILENO) */
	dprintf(STDERR_FILENO, msg, arg);
	/* Termine le programme immédiatement avec le code d'erreur spécifié */
	exit(code);
}

/**
 * main - Copie le contenu d'un fichier source vers un fichier destination.
 * @argc: Le nombre d'arguments passés au programme.
 * @argv: Le tableau des arguments (argv[1] = source, argv[2] = destination).
 *
 * Return: 0 si succès, sinon quitte avec un code d'erreur (97-100).
 */
int main(int argc, char *argv[])
{
	int desc_from; /* Descripteur pour le fichier source */
	int desc_to; /* Descripteur pour le fichier destination */
	ssize_t bytes_read; /* Nombre d'octets lus depuis le fichier source */
	ssize_t bytes_written; /* Nombre d'octets écrits dans le fichier destination */
	char buffer[BUFFER_SIZE]; /* Buffer temporaire pour stocker les données lues */

	/* Vérifie si le nombre d'arguments est incorrect (doit être 3 : programme + 2 fichiers) */
	if (argc != 3)
	{
		/* Affiche le message d'usage sur stderr et quitte avec le code 97 */
		error_exit(97, "Usage: cp file_from file_to\n", "");
	}

	/* Ouvre le fichier source (argv[1]) en mode lecture seule */
	desc_from = open(argv[1], O_RDONLY);
	/* Vérifie si l'ouverture du fichier source a échoué (retourne -1) */
	if (desc_from == -1)
	{
		/* Affiche l'erreur "Can't read" sur stderr et quitte avec le code 98 */
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	/* Ouvre/Crée le fichier destination (argv[2]) avec les permissions rw-rw-r-- (0664) */
	desc_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	/* O_WRONLY: écriture, O_CREAT: créer, O_TRUNC: vider */

	/* Vérifie si l'ouverture/création du fichier destination a échoué */
	if (desc_to == -1)
	{
		/* Ferme le fichier source déjà ouvert pour éviter une fuite de descripteur */
		close(desc_from);
		/* Affiche l'erreur "Can't write" sur stderr et quitte avec le code 99 */
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	/* Boucle principale de copie : lit jusqu'à la fin du fichier source */
	/* Lit au maximum BUFFER_SIZE octets du fichier source (desc_from) dans le buffer */
	while ((bytes_read = read(desc_from, buffer, BUFFER_SIZE)) > 0)
	{
		/* Écrit les octets_lus dans le fichier destination (desc_to) */
		bytes_written = write(desc_to, buffer, bytes_read);
		/* Vérifie si l'appel à write a échoué (retourne -1) */
		if (bytes_written == -1)
		{
			/* Ferme les deux descripteurs ouverts */
			close(desc_from);
			close(desc_to);
			/* Affiche l'erreur "Can't write" sur stderr et quitte avec le code 99 */
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	/* Après la boucle, vérifie si la sortie est due à une erreur de lecture (read retourne -1) */
	if (bytes_read == -1)
	{
		/* Ferme les deux descripteurs ouverts */
		close(desc_from);
		close(desc_to);
		/* Affiche l'erreur "Can't read" sur stderr et quitte avec le code 98 */
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	/* Tente de fermer le descripteur du fichier source */
	if (close(desc_from) == -1)
	{
		/* Si close() échoue, affiche l'erreur "Can't close fd" sur stderr et quitte avec le code 100 */
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", desc_from);
		exit(100);
	}

	/* Tente de fermer le descripteur du fichier destination */
	if (close(desc_to) == -1)
	{
		/* Si close() échoue, affiche l'erreur "Can't close fd" sur stderr et quitte avec le code 100 */
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", desc_to);
		exit(100);
	}

	/* Le programme a réussi à copier le fichier sans erreur, retourne 0 */
	return (0);
}
