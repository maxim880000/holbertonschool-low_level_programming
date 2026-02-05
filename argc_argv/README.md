# 💻 Argc & Argv - Arguments de ligne de commande

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Intermédiaire-orange?style=for-the-badge" alt="Intermédiaire"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Comprendre argc et argv](#-comprendre-argc-et-argv)
4. [Structure en mémoire](#-structure-en-mémoire)
5. [Fichiers du projet](#-fichiers-du-projet)
6. [Détail des fichiers](#-détail-des-fichiers)
7. [La fonction atoi](#-la-fonction-atoi)
8. [Compilation et exécution](#-compilation-et-exécution)
9. [Ressources](#-ressources)

---

## 📝 Description

Ce projet explore comment un programme C peut recevoir des **arguments de ligne de commande**. Ces arguments permettent de passer des informations au programme au moment de son exécution, rendant les programmes plus flexibles et interactifs.

Les arguments sont transmis via deux paramètres de la fonction `main` :
- `argc` : le **nombre** d'arguments
- `argv` : un **tableau** contenant les arguments sous forme de chaînes

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre les paramètres `argc` et `argv` de `main()`
- ✅ Accéder aux arguments de ligne de commande
- ✅ Convertir des arguments (chaînes) en nombres avec `atoi()`
- ✅ Gérer les erreurs liées aux arguments
- ✅ Créer des programmes CLI (Command Line Interface)

---

## 🔍 Comprendre argc et argv

### Les paramètres de main()

```c
int main(int argc, char *argv[])
/* Ou équivalent */
int main(int argc, char **argv)
```

### argc (Argument Count)

- **Type** : `int`
- **Signification** : Nombre total d'arguments (incluant le nom du programme)
- **Minimum** : Toujours au moins 1 (le nom du programme)

### argv (Argument Vector)

- **Type** : `char **` ou `char *[]`
- **Signification** : Tableau de chaînes de caractères
- **argv[0]** : Toujours le nom/chemin du programme
- **argv[1..n]** : Les arguments passés par l'utilisateur
- **argv[argc]** : Toujours `NULL` (sentinelle)

### Exemple concret

```bash
$ ./program hello world 42
```

```
argc = 4

argv[0] = "./program"
argv[1] = "hello"
argv[2] = "world"
argv[3] = "42"
argv[4] = NULL
```

---

## 💾 Structure en mémoire

```
┌─────────────────────────────────────────────────────────────────┐
│                           argv                                  │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  argv (char **)                                                 │
│  ┌────────┬────────┬────────┬────────┬────────┐                │
│  │argv[0] │argv[1] │argv[2] │argv[3] │argv[4] │                │
│  │ ptr    │ ptr    │ ptr    │ ptr    │ NULL   │                │
│  └───┬────┴───┬────┴───┬────┴───┬────┴────────┘                │
│      │        │        │        │                               │
│      ▼        ▼        ▼        ▼                               │
│  "./program"  "hello"  "world"  "42"                           │
│  ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬──┐                                      │
│  │.│/│p│r│o│g│r│a│m│\0│                                        │
│  └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴──┘                                      │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

### Visualisation avec indices

```
       argv
       ┌───────────┐
    0  │    ●──────┼──────► "./program\0"
       ├───────────┤
    1  │    ●──────┼──────► "hello\0"
       ├───────────┤
    2  │    ●──────┼──────► "world\0"
       ├───────────┤
    3  │    ●──────┼──────► "42\0"
       ├───────────┤
    4  │   NULL    │
       └───────────┘
```

---

## 📂 Fichiers du projet

| Fichier | Description |
|---------|-------------|
| `0-whatsmyname.c` | Affiche le nom du programme (`argv[0]`) |
| `1-args.c` | Affiche le nombre d'arguments (sans compter le nom) |
| `2-args.c` | Affiche tous les arguments, un par ligne |
| `3-mul.c` | Multiplie deux nombres passés en arguments |
| `4-add.c` | Additionne tous les nombres positifs passés |

---

## 📄 Détail des fichiers

### 0-whatsmyname.c

```c
#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argc;  /* Ignore argc pour éviter le warning */
    printf("%s\n", argv[0]);
    return (0);
}
```

**Usage** :
```bash
$ ./whatsmyname
./whatsmyname

$ /tmp/whatsmyname
/tmp/whatsmyname
```

**Note** : `argv[0]` contient le chemin utilisé pour lancer le programme.

---

### 1-args.c

```c
#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argv;
    printf("%d\n", argc - 1);  /* -1 pour exclure le nom du programme */
    return (0);
}
```

**Usage** :
```bash
$ ./args
0

$ ./args hello
1

$ ./args hello world
2
```

---

### 2-args.c

```c
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    for (i = 0; i < argc; i++)
        printf("%s\n", argv[i]);

    return (0);
}
```

**Usage** :
```bash
$ ./args hello world 42
./args
hello
world
42
```

---

### 3-mul.c

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a, b;

    if (argc != 3)
    {
        printf("Error\n");
        return (1);
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    printf("%d\n", a * b);
    return (0);
}
```

**Usage** :
```bash
$ ./mul 3 5
15

$ ./mul 10 -2
-20

$ ./mul 5
Error
```

**Points importants** :
- Vérifie que le nombre d'arguments est correct
- Utilise `atoi()` pour convertir les chaînes en entiers
- Retourne `1` en cas d'erreur

---

### 4-add.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int number_yn(char *s)
{
    int i;

    if (s[0] == '\0')
        return (0);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
            return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int sum = 0;

    if (argc == 1)
    {
        printf("0\n");
        return (0);
    }

    for (i = 1; i < argc; i++)
    {
        if (!number_yn(argv[i]))
        {
            printf("Error\n");
            return (1);
        }
        sum += atoi(argv[i]);
    }

    printf("%d\n", sum);
    return (0);
}
```

**Usage** :
```bash
$ ./add 1 2 3
6

$ ./add 100 200 300
600

$ ./add 1 hello 3
Error
```

**Validation** :
- `number_yn()` vérifie que chaque argument est un nombre valide
- `isdigit()` vérifie si un caractère est un chiffre

---

## 🔢 La fonction atoi

### Prototype
```c
#include <stdlib.h>
int atoi(const char *str);
```

### Comportement
- Convertit une chaîne de caractères en entier
- Ignore les espaces au début
- Gère les signes `+` et `-`
- S'arrête au premier caractère non-numérique

### Exemples

| Entrée | Sortie |
|--------|--------|
| `"42"` | `42` |
| `"-42"` | `-42` |
| `"   123"` | `123` |
| `"456abc"` | `456` |
| `"abc"` | `0` |

### ⚠️ Limitations d'atoi

```c
/* atoi ne détecte pas les erreurs ! */
atoi("abc")    /* Retourne 0, pas d'erreur signalée */
atoi("999999999999999")  /* Overflow, comportement indéfini */
```

**Alternative plus sûre** : `strtol()` qui permet de détecter les erreurs.

---

## 🔧 Compilation et exécution

```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-whatsmyname.c -o whatsmyname
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-mul.c -o mul
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-add.c -o add

# Exécuter
./whatsmyname
./mul 3 5
./add 1 2 3 4 5
```

---

## 💡 Bonnes pratiques

### 1. Toujours vérifier argc
```c
if (argc < 2)
{
    printf("Usage: %s <argument>\n", argv[0]);
    return (1);
}
```

### 2. Valider les arguments
```c
/* Vérifier que c'est un nombre */
for (int i = 0; argv[1][i]; i++)
{
    if (!isdigit(argv[1][i]))
    {
        printf("Error: not a number\n");
        return (1);
    }
}
```

### 3. Utiliser argv[0] dans les messages d'erreur
```c
printf("Usage: %s <num1> <num2>\n", argv[0]);
/* Affiche le vrai nom du programme */
```

---

## 📊 Cas d'utilisation courants

| Programme | Arguments | Exemple |
|-----------|-----------|---------|
| Calculatrice | Opérandes | `./calc 5 + 3` |
| Copie de fichier | Source, dest | `./cp file1 file2` |
| Recherche | Pattern | `./grep pattern file` |
| Compilation | Options, fichiers | `./gcc -o prog main.c` |

---

## 📚 Ressources

- [Command Line Arguments - GeeksforGeeks](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
- [atoi() - cppreference](https://en.cppreference.com/w/c/string/byte/atoi)
- [getopt() - Pour les options avancées](https://www.gnu.org/software/libc/manual/html_node/Getopt.html)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« La ligne de commande est la porte d'entrée vers la puissance de l'ordinateur. »</i>
</p>
