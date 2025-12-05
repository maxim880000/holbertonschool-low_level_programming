#include "main.h"

/* Taille du buffer (zone mémoire) pour lire par blocs de 1024 octets */
#define BUFFER_SIZE 1024

/**
 * error - Affiche un message d'erreur et quitte le programme
 * @code: code de sortie (97, 98, 99, ou 100)
 * @msg: Message d'erreur à afficher
 * @arg: Argument à insérer dans le message
 */
void error(int code, const char *msg, const char *arg)
{
	/* Affiche le message d'erreur sur la sortie d'erreur standard */
	dprintf(STDERR_FILENO, msg, arg);
	/* Quitte le programme avec le code d'erreur */
	exit(code);
}

/**
 * main - Copie le contenu d'un fichier vers un autre fichier
 * @argc: Nombre d'arguments passés au programme
 * @argv: Tableau contenant les arguments (argv[1]=source, argv[2]=dest)
 *
 * Return: 0 si succès, sinon exit avec code d'erreur
 */
int main(int argc, char *argv[])
{
	/* Descripteur pour le fichier source */
	int desc_from;
	/* Descripteur pour le fichier destination */
	int desc_to;
	/* Nombre d'octets lus depuis le fichier source */
	ssize_t bytes_read;
	/* Nombre d'octets écrits dans le fichier destination */
	ssize_t bytes_written;
	/* Buffer temporaire pour stocker les données lues */
	char buffer[BUFFER_SIZE];

	/* Vérifie qu'on a exactement 3 arguments (programme + 2 fichiers) */
	if (argc != 3)
		/* Si mauvais nombre d'arguments, affiche usage et quitte avec 97 */
		error(97, "Usage: cp file_from file_to\n", "");

	/* Ouvre le fichier source en mode lecture seule */
	desc_from = open(argv[1], O_RDONLY);
	/* Si l'ouverture échoue (fichier inexistant ou pas de permissions) */
	if (desc_from == -1)
		/* Affiche erreur et quitte avec code 98 */
		error(98, "Error: Can't read from file %s\n", argv[1]);

	/* Ouvre/crée le fichier destination avec permissions rw-rw-r-- (0664) */
	/* O_WRONLY = écriture seule, O_CREAT = créer si n'existe pas */
	/* O_TRUNC = vider le fichier s'il existe déjà */
	desc_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	/* Si la création/ouverture échoue */
	if (desc_to == -1)
	{
		/* Ferme d'abord le fichier source qui était ouvert */
		close(desc_from);
		/* Affiche erreur et quitte avec code 99 */
		error(99, "Error: Can't write to %s\n", argv[2]);
	}

	/* Boucle tant qu'il y a des données à lire */
	/* read() lit jusqu'à BUFFER_SIZE octets et retourne le nombre lu */
	while ((bytes_read = read(desc_from, buffer, BUFFER_SIZE)) > 0)
	{
		/* Écrit dans le fichier destination ce qui a été lu */
		bytes_written = write(desc_to, buffer, bytes_read);
		/* Si l'écriture échoue (disque plein, permissions, etc.) */
		if (bytes_written == -1)
		{
			/* Ferme les deux fichiers */
			close(desc_from);
			close(desc_to);
			/* Affiche erreur et quitte avec code 99 */
			error(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	/* Si read() a retourné -1, c'est une erreur de lecture */
	if (bytes_read == -1)
	{
		/* Ferme les deux fichiers */
		close(desc_from);
		close(desc_to);
		/* Affiche erreur et quitte avec code 98 */
		error(98, "Error: Can't read from file %s\n", argv[1]);
	}

	/* Ferme le fichier source */
	if (close(desc_from) == -1)
	{
		/* Si close() échoue, affiche le fd et quitte avec code 100 */
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", desc_from);
		exit(100);
	}

	/* Ferme le fichier destination */
	if (close(desc_to) == -1)
	{
		/* Si close() échoue, affiche le fd et quitte avec code 100 */
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", desc_to);
		exit(100);
	}

	/* Tout s'est bien passé, retourne 0 */
	return (0);
}