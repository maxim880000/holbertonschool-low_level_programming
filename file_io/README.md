# 📁 File I/O - Entrées/Sorties fichiers

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/System-Linux-orange?style=for-the-badge&logo=linux" alt="Linux"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Les descripteurs de fichiers](#-les-descripteurs-de-fichiers)
4. [Les appels système](#-les-appels-système)
5. [Flags et permissions](#-flags-et-permissions)
6. [Fichiers du projet](#-fichiers-du-projet)
7. [Détail des fichiers](#-détail-des-fichiers)
8. [Programme cp](#-programme-cp)
9. [Gestion des erreurs](#-gestion-des-erreurs)
10. [Compilation et exécution](#-compilation-et-exécution)
11. [Ressources](#-ressources)

---

## 📝 Description

Ce projet explore les **entrées/sorties fichiers** (File I/O) au niveau système en C. Contrairement aux fonctions de haut niveau (`fopen`, `fread`, `fprintf`), ce projet utilise les **appels système POSIX** directs : `open`, `read`, `write`, et `close`.

Ces fonctions bas niveau offrent un contrôle total sur les opérations fichiers et sont utilisées dans les programmes système, les drivers et les outils Unix.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre les **file descriptors** (descripteurs de fichiers)
- ✅ Utiliser `open`, `read`, `write`, `close`
- ✅ Manipuler les **flags** d'ouverture (`O_RDONLY`, `O_WRONLY`, etc.)
- ✅ Définir les **permissions** avec le mode octal
- ✅ Gérer les **erreurs** des appels système
- ✅ Créer un programme de **copie de fichiers** complet

---

## 🔢 Les descripteurs de fichiers

### Qu'est-ce qu'un file descriptor ?

Un **file descriptor** (fd) est un entier non négatif qui identifie un fichier ouvert dans un processus. C'est une "poignée" (handle) vers une ressource.

```c
int fd = open("file.txt", O_RDONLY);
/* fd = 3 (par exemple) */
```

### Les 3 descripteurs standard

| fd | Nom | Macro | Description |
|----|-----|-------|-------------|
| 0 | stdin | `STDIN_FILENO` | Entrée standard (clavier) |
| 1 | stdout | `STDOUT_FILENO` | Sortie standard (écran) |
| 2 | stderr | `STDERR_FILENO` | Sortie d'erreur (écran) |

### Table des descripteurs de fichiers

```
Processus
┌────────────────────────────────────┐
│  Table des file descriptors        │
│  ┌─────┬──────────────────────┐   │
│  │  0  │ → stdin              │   │
│  │  1  │ → stdout             │   │
│  │  2  │ → stderr             │   │
│  │  3  │ → /home/user/file.txt│   │ ← open() retourne 3
│  │  4  │ → (disponible)       │   │
│  └─────┴──────────────────────┘   │
└────────────────────────────────────┘
```

---

## 🔧 Les appels système

### open() - Ouvrir un fichier

```c
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int fd = open(const char *pathname, int flags);
int fd = open(const char *pathname, int flags, mode_t mode);

/* Exemples */
int fd1 = open("file.txt", O_RDONLY);              /* Lecture seule */
int fd2 = open("new.txt", O_WRONLY | O_CREAT, 0644); /* Écriture, créer si n'existe pas */
int fd3 = open("log.txt", O_WRONLY | O_APPEND);    /* Ajouter à la fin */
```

**Retour** : file descriptor (≥ 0) ou -1 en cas d'erreur.

---

### read() - Lire depuis un fichier

```c
#include <unistd.h>

ssize_t bytes_read = read(int fd, void *buf, size_t count);

/* Exemple */
char buffer[1024];
ssize_t n = read(fd, buffer, 1024);
if (n == -1)
    perror("read");  /* Erreur */
else if (n == 0)
    /* Fin de fichier (EOF) */
else
    /* n octets lus dans buffer */
```

**Retour** :
- `> 0` : Nombre d'octets lus
- `0` : Fin de fichier (EOF)
- `-1` : Erreur

**Visualisation** :
```
Fichier: "Hello World!"
         ↑
      position

read(fd, buf, 5):
buffer = "Hello"
         position → après "Hello"

read(fd, buf, 10):
buffer = " World!"
         position → EOF
```

---

### write() - Écrire dans un fichier

```c
#include <unistd.h>

ssize_t bytes_written = write(int fd, const void *buf, size_t count);

/* Exemples */
char *msg = "Hello, World!\n";
write(STDOUT_FILENO, msg, 14);     /* Affiche sur stdout */
write(fd, msg, 14);                /* Écrit dans un fichier */
```

**Retour** :
- `> 0` : Nombre d'octets écrits
- `-1` : Erreur

⚠️ **Important** : Toujours vérifier que `bytes_written == count` !

---

### close() - Fermer un fichier

```c
#include <unistd.h>

int result = close(int fd);

if (close(fd) == -1)
    perror("close");
```

**Retour** : 0 si succès, -1 si erreur.

⚠️ **Important** : Toujours fermer les fichiers ouverts pour éviter les fuites de ressources !

---

## 🚩 Flags et permissions

### Flags d'ouverture (fcntl.h)

| Flag | Description |
|------|-------------|
| `O_RDONLY` | Lecture seule |
| `O_WRONLY` | Écriture seule |
| `O_RDWR` | Lecture et écriture |
| `O_CREAT` | Créer le fichier s'il n'existe pas |
| `O_TRUNC` | Tronquer le fichier (vider) s'il existe |
| `O_APPEND` | Écrire à la fin du fichier |
| `O_EXCL` | Avec O_CREAT, échoue si le fichier existe |

**Combinaison avec `|`** :
```c
/* Créer ou écraser un fichier pour écriture */
open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

/* Ajouter à un fichier existant */
open("log.txt", O_WRONLY | O_APPEND);
```

### Permissions (mode octal)

```
Format: 0xyz où x=owner, y=group, z=others

Valeurs:
  4 = read (r)
  2 = write (w)
  1 = execute (x)

Exemples:
  0644 = rw-r--r--  (fichier standard)
  0755 = rwxr-xr-x  (exécutable)
  0600 = rw-------  (privé)
```

**Calcul** :
```
rw-r--r-- = (4+2) (4) (4) = 0644
rwxr-xr-x = (4+2+1) (4+1) (4+1) = 0755
```

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `main.h` | Prototypes et includes | - |
| `0-read_textfile.c` | Lit et affiche un fichier texte | `ssize_t read_textfile(const char *filename, size_t letters)` |
| `1-create_file.c` | Crée un fichier avec contenu | `int create_file(const char *filename, char *text_content)` |
| `2-append_text_to_file.c` | Ajoute du texte à un fichier | `int append_text_to_file(const char *filename, char *text_content)` |
| `3-cp.c` | Programme de copie de fichiers | `int main(int argc, char *argv[])` |

---

## 📄 Détail des fichiers

### main.h

```c
#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

#endif
```

---

### 0-read_textfile.c

```c
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters read and printed, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t rd, wr;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buffer);
        return (0);
    }

    rd = read(fd, buffer, letters);
    if (rd == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    wr = write(STDOUT_FILENO, buffer, rd);
    if (wr == -1 || wr != rd)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);
    return (wr);
}
```

**Flux d'exécution** :
```
read_textfile("hello.txt", 100)

1. malloc(100)           → buffer alloué
2. open("hello.txt")     → fd = 3
3. read(3, buffer, 100)  → rd = 50 (fichier de 50 bytes)
4. write(1, buffer, 50)  → affiche sur stdout
5. free(buffer)          → libère mémoire
6. close(3)              → ferme fichier
7. return 50
```

---

### 1-create_file.c

```c
#include "main.h"
#include <string.h>

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: string to write to the file (can be NULL)
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t len, wr;

    if (filename == NULL)
        return (-1);

    /* Créer avec permissions rw------- */
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        len = strlen(text_content);
        wr = write(fd, text_content, len);
        if (wr == -1 || wr != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
```

---

### 2-append_text_to_file.c

```c
#include "main.h"
#include <string.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: string to add (can be NULL = nothing added)
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t len, wr;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        len = strlen(text_content);
        wr = write(fd, text_content, len);
        if (wr == -1 || wr != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
```

**Note** : Le flag `O_APPEND` positionne automatiquement le curseur à la fin avant chaque écriture.

---

## 📋 Programme cp

### 3-cp.c - Copie de fichiers

```c
#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exits with error code on failure
 *
 * Exit codes:
 *   97: incorrect number of arguments
 *   98: cannot read from source file
 *   99: cannot write to destination file
 *   100: cannot close a file descriptor
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, r, w;
    char buf[1024];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    /* Ouvrir le fichier source */
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    /* Créer/écraser le fichier destination */
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

    /* Copier par blocs de 1024 bytes */
    while ((r = read(fd_from, buf, 1024)) > 0)
    {
        w = write(fd_to, buf, r);
        if (w == -1 || w != r)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    if (r == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    /* Fermer les fichiers */
    if (close(fd_from) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }
    if (close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}
```

### Visualisation de la copie

```
./cp source.txt dest.txt

source.txt (3000 bytes)
┌─────────────────────────────────────────────┐
│ [1024 bytes] [1024 bytes] [952 bytes]       │
└─────────────────────────────────────────────┘

Itération 1: read() → 1024 bytes → write() → dest.txt
Itération 2: read() → 1024 bytes → write() → dest.txt
Itération 3: read() → 952 bytes  → write() → dest.txt
Itération 4: read() → 0 (EOF)    → sortie de boucle

dest.txt (3000 bytes) ✓
```

---

## ⚠️ Gestion des erreurs

### Pattern de gestion d'erreur

```c
/* Toujours vérifier chaque appel système */
fd = open(filename, O_RDONLY);
if (fd == -1)
{
    perror("open");      /* Affiche: open: No such file or directory */
    return (-1);
}

/* dprintf pour écrire sur stderr avec format */
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
```

### Variables errno

```c
#include <errno.h>

if (open("file.txt", O_RDONLY) == -1)
{
    if (errno == ENOENT)
        printf("File not found\n");
    else if (errno == EACCES)
        printf("Permission denied\n");
}
```

---

## 🔧 Compilation et exécution

```bash
# Compiler les fonctions
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-read_textfile.c -o read
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-create_file.c -o create
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-append_text_to_file.c -o append

# Compiler cp
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-cp.c -o cp

# Tester
./read
./create
./append

# Utiliser cp
./cp file_from file_to

# Vérifier la copie
diff file_from file_to
echo $?  # 0 si identiques
```

---

## 📊 Comparaison stdio vs system calls

| Fonction stdio | Appel système | Description |
|----------------|---------------|-------------|
| `fopen()` | `open()` | Ouvrir un fichier |
| `fread()` | `read()` | Lire |
| `fwrite()` | `write()` | Écrire |
| `fclose()` | `close()` | Fermer |
| `fseek()` | `lseek()` | Déplacer le curseur |

**Quand utiliser quoi ?**
- **stdio** : Fichiers texte, formatage, buffering automatique
- **System calls** : Contrôle précis, fichiers binaires, programmation système

---

## 📚 Ressources

- [Man page open(2)](https://man7.org/linux/man-pages/man2/open.2.html)
- [Man page read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [Man page write(2)](https://man7.org/linux/man-pages/man2/write.2.html)
- [File Descriptors - Linux Programming Interface](https://man7.org/tlpi/)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« En Unix, tout est fichier - même les périphériques. »</i>
</p>
