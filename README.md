# 🖥️ Holberton School - Low Level Programming

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/OS-Linux-orange?style=for-the-badge&logo=linux" alt="Linux"/>
  <img src="https://img.shields.io/badge/School-Holberton-red?style=for-the-badge" alt="Holberton"/>
</p>

---

## 📖 Table des matières

1. [Présentation générale](#-présentation-générale)
2. [Pourquoi le low-level programming ?](#-pourquoi-le-low-level-programming-)
3. [Objectifs pédagogiques](#-objectifs-pédagogiques)
4. [Prérequis](#-prérequis)
5. [Structure du repository](#-structure-du-repository)
6. [Analyse détaillée par directory](#-analyse-détaillée-par-directory)
   - [hello_world](#1️⃣-hello_world)
   - [variables_if_else_while](#2️⃣-variables_if_else_while)
   - [functions_nested_loops](#3️⃣-functions_nested_loops)
   - [more_functions_nested_loops](#4️⃣-more_functions_nested_loops)
   - [pointers_arrays_strings](#5️⃣-pointers_arrays_strings)
   - [recursion](#6️⃣-recursion)
   - [argc_argv](#7️⃣-argc_argv)
   - [malloc_free](#8️⃣-malloc_free)
   - [more_malloc_free](#9️⃣-more_malloc_free)
   - [structures_typedef](#🔟-structures_typedef)
   - [function_pointers](#1️⃣1️⃣-function_pointers)
   - [variadic_functions](#1️⃣2️⃣-variadic_functions)
   - [singly_linked_lists](#1️⃣3️⃣-singly_linked_lists)
   - [doubly_linked_lists](#1️⃣4️⃣-doubly_linked_lists)
   - [file_io](#1️⃣5️⃣-file_io)
7. [Compilation et exécution](#-compilation-et-exécution)
8. [Conventions de code](#-conventions-de-code)
9. [Auteur](#-auteur)

---

## 🎯 Présentation générale

Ce repository contient l'ensemble des projets de **programmation bas niveau en langage C** réalisés dans le cadre du cursus **Holberton School**. Il représente un parcours complet d'apprentissage, allant des concepts fondamentaux jusqu'aux structures de données avancées et aux appels systèmes.

Le **langage C**, créé en 1972 par Dennis Ritchie, reste aujourd'hui la pierre angulaire de la programmation système. Ce repository permet de comprendre comment fonctionne un ordinateur au niveau le plus proche du matériel, tout en utilisant un langage de programmation structuré.

### 🔍 Ce que contient ce repository :

- **15+ projets** progressifs couvrant tous les aspects du C
- **100+ fichiers source** documentés et commentés
- Des exercices pratiques sur les **pointeurs**, la **mémoire**, les **structures de données**
- Des implémentations manuelles de fonctions de la **libc**
- Des projets de manipulation de **fichiers** et d'**appels systèmes**

---

## 💡 Pourquoi le low-level programming ?

### Comprendre ce qui se passe "sous le capot"

Lorsque vous utilisez Python, JavaScript ou tout autre langage de haut niveau, de nombreuses opérations sont abstraites : gestion de la mémoire, manipulation des types, accès aux fichiers. Le **C** vous oblige à comprendre et gérer tous ces aspects manuellement.

### Les avantages d'apprendre le C :

| Avantage | Description |
|----------|-------------|
| **Performance** | Le C compile en code machine natif, offrant des performances optimales |
| **Contrôle mémoire** | Gestion manuelle de l'allocation/libération de mémoire |
| **Portabilité** | Le C est disponible sur pratiquement toutes les plateformes |
| **Base solide** | Comprendre le C facilite l'apprentissage de tout autre langage |
| **Systèmes embarqués** | Le C est le langage de prédilection pour l'IoT et l'embarqué |

### Où est utilisé le C aujourd'hui ?

- **Systèmes d'exploitation** : Linux, Windows, macOS
- **Bases de données** : MySQL, PostgreSQL, SQLite
- **Langages de programmation** : Python (CPython), Ruby, PHP
- **Navigateurs web** : Parties critiques de Chrome, Firefox
- **Systèmes embarqués** : Automobile, aérospatial, médical

---

## 🎓 Objectifs pédagogiques

En complétant ce repository, vous maîtriserez :

### Fondamentaux
- ✅ La syntaxe et la sémantique du langage C
- ✅ Le processus de compilation (préprocesseur → compilateur → assembleur → linker)
- ✅ Les types de données primitifs et leurs tailles en mémoire
- ✅ Les structures de contrôle (conditions, boucles)

### Intermédiaire
- ✅ Les **pointeurs** et l'arithmétique des pointeurs
- ✅ Les **tableaux** et leur relation avec les pointeurs
- ✅ La manipulation de **chaînes de caractères**
- ✅ L'**allocation dynamique de mémoire** (`malloc`, `free`, `calloc`)
- ✅ La **récursivité** et ses cas d'utilisation

### Avancé
- ✅ Les **structures** et les **typedef**
- ✅ Les **pointeurs de fonctions**
- ✅ Les **fonctions variadiques**
- ✅ Les **listes chaînées** (simples et doubles)
- ✅ Les **entrées/sorties fichiers** et appels systèmes (`open`, `read`, `write`, `close`)

---

## 📋 Prérequis

### Environnement technique
- **OS** : Linux (Ubuntu 20.04 LTS recommandé)
- **Compilateur** : GCC 9.4+
- **Éditeur** : Vi, Vim, Emacs ou VS Code

### Commandes de compilation standards
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o executable
```

| Flag | Description |
|------|-------------|
| `-Wall` | Active tous les avertissements courants |
| `-Werror` | Traite les warnings comme des erreurs |
| `-Wextra` | Active des avertissements supplémentaires |
| `-pedantic` | Assure la conformité stricte aux standards |
| `-std=gnu89` | Utilise le standard C89 avec extensions GNU |

---

## 📂 Structure du repository

```
holbertonschool-low_level_programming/
│
├── hello_world/                    # Introduction au C
├── variables_if_else_while/        # Variables et structures de contrôle
├── functions_nested_loops/         # Fonctions et boucles imbriquées
├── more_functions_nested_loops/    # Exercices avancés sur les boucles
├── pointers_arrays_strings/        # Pointeurs, tableaux et chaînes
├── recursion/                      # Fonctions récursives
├── argc_argv/                      # Arguments de ligne de commande
├── malloc_free/                    # Allocation dynamique de mémoire
├── more_malloc_free/               # Exercices avancés sur malloc
├── structures_typedef/             # Structures et alias de types
├── function_pointers/              # Pointeurs de fonctions
├── variadic_functions/             # Fonctions à arguments variables
├── singly_linked_lists/            # Listes simplement chaînées
├── doubly_linked_lists/            # Listes doublement chaînées
└── file_io/                        # Entrées/sorties fichiers
```

---

## 📚 Analyse détaillée par directory

---

### 1️⃣ hello_world

#### 📝 Présentation
Premier contact avec le langage C. Ce projet introduit les concepts de base : la compilation, la sortie standard, et les fonctions d'affichage.

#### 🧠 Concepts abordés
- **Chaîne de compilation** : préprocesseur (`gcc -E`), compilation (`gcc -S`), assemblage (`gcc -c`), édition de liens
- **Fonctions d'affichage** : `puts()`, `printf()`, `putchar()`
- **Point d'entrée** : la fonction `main()` et sa signature
- **Types de données** : `int`, `char`, `float`, `long`, et leurs tailles en mémoire

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `4-puts.c` | Utilise `puts()` pour afficher une chaîne avec guillemets |
| `5-printf.c` | Introduction à `printf()` et les spécificateurs de format |
| `6-size.c` | Affiche la taille des types de données avec `sizeof()` |

#### 💻 Exemple de code
```c
#include <stdio.h>

int main(void)
{
    printf("Size of a char: %zu byte(s)\n", sizeof(char));      /* 1 */
    printf("Size of an int: %zu byte(s)\n", sizeof(int));       /* 4 */
    printf("Size of a long int: %zu byte(s)\n", sizeof(long));  /* 8 */
    return (0);
}
```

#### 🔑 Pourquoi c'est important ?
Comprendre la taille des types est **fondamental** pour :
- Optimiser l'utilisation mémoire
- Éviter les dépassements de capacité (overflow)
- Comprendre la portabilité entre architectures

---

### 2️⃣ variables_if_else_while

#### 📝 Présentation
Introduction aux variables, aux structures conditionnelles et aux boucles. Ce projet pose les bases de la logique algorithmique en C.

#### 🧠 Concepts abordés
- **Variables** : déclaration, initialisation, portée
- **Conditions** : `if`, `else if`, `else`
- **Boucles** : `while`, `for`
- **Opérateurs** : arithmétiques, logiques, relationnels
- **Génération aléatoire** : `srand()`, `rand()`

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-positive_or_negative.c` | Détermine si un nombre est positif, négatif ou nul |
| `1-last_digit.c` | Extrait et analyse le dernier chiffre d'un nombre |
| `2-print_alphabet.c` | Affiche l'alphabet en minuscules |
| `9-print_comb.c` | Affiche toutes les combinaisons de chiffres |

#### 💻 Exemple de code
```c
#include <stdio.h>

int main(void)
{
    int n;
    
    srand(time(0));  /* Initialise le générateur aléatoire */
    n = rand() - RAND_MAX / 2;  /* Nombre positif ou négatif */
    
    if (n > 0)
        printf("%d is positive\n", n);
    else if (n == 0)
        printf("%d is zero\n", n);
    else
        printf("%d is negative\n", n);
    
    return (0);
}
```

#### 🔑 Pourquoi c'est important ?
Les structures de contrôle sont le **cœur de tout algorithme**. Sans elles, impossible de :
- Prendre des décisions
- Répéter des actions
- Gérer les cas particuliers

---

### 3️⃣ functions_nested_loops

#### 📝 Présentation
Introduction aux fonctions personnalisées et aux boucles imbriquées. Ce projet enseigne la modularité du code et la réutilisabilité.

#### 🧠 Concepts abordés
- **Fonctions** : déclaration, définition, appel
- **Prototypes** : fichiers header (`.h`)
- **Boucles imbriquées** : complexité O(n²)
- **Caractères ASCII** : manipulation et conversion

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `main.h` | Header contenant tous les prototypes de fonctions |
| `1-alphabet.c` | Affiche l'alphabet avec une fonction dédiée |
| `7-print_last_digit.c` | Extrait et retourne le dernier chiffre |
| `9-times_table.c` | Affiche la table de multiplication de 0 à 9 |

#### 💻 Exemple - Table de multiplication
```c
void times_table(void)
{
    int i, j, product;

    for (i = 0; i <= 9; i++)              /* Lignes */
    {
        for (j = 0; j <= 9; j++)          /* Colonnes */
        {
            product = i * j;
            /* Formatage et affichage */
        }
        _putchar('\n');
    }
}
```

#### 🔑 Pourquoi c'est important ?
Les fonctions permettent :
- La **réutilisation** du code
- La **lisibilité** et la maintenance
- Les **tests unitaires**
- La **collaboration** en équipe

---

### 4️⃣ more_functions_nested_loops

#### 📝 Présentation
Exercices avancés sur les fonctions et les boucles. Introduction aux fonctions de validation et aux patterns d'affichage.

#### 🧠 Concepts abordés
- **Fonctions de validation** : `isupper()`, `isdigit()`
- **Patterns géométriques** : lignes, carrés, triangles
- **Algorithme FizzBuzz** : un classique des entretiens techniques

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-isupper.c` | Vérifie si un caractère est une majuscule |
| `1-isdigit.c` | Vérifie si un caractère est un chiffre |
| `8-print_square.c` | Affiche un carré de caractères `#` |
| `9-fizz_buzz.c` | Implémentation de l'algorithme FizzBuzz |

#### 💻 Exemple - FizzBuzz
```c
int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf("FizzBuzz");
        else if (i % 3 == 0)
            printf("Fizz");
        else if (i % 5 == 0)
            printf("Buzz");
        else
            printf("%d", i);
        
        if (i < 100)
            printf(" ");
    }
    putchar('\n');
    return (0);
}
```

#### 🔑 Pourquoi c'est important ?
FizzBuzz est un **test classique** qui vérifie :
- La compréhension des conditions
- L'utilisation correcte du modulo
- La logique d'imbrication des `if`

---

### 5️⃣ pointers_arrays_strings

#### 📝 Présentation
Le **cœur du langage C**. Ce projet couvre les pointeurs, les tableaux et la manipulation de chaînes. C'est souvent considéré comme le tournant décisif dans l'apprentissage du C.

#### 🧠 Concepts abordés

##### Pointeurs
Un pointeur est une variable qui contient l'**adresse mémoire** d'une autre variable.

```
┌─────────────┐     ┌─────────────┐
│ Variable n  │     │ Pointeur *p │
│ Valeur: 42  │ ←── │ Adresse: &n │
│ Adresse: &n │     │             │
└─────────────┘     └─────────────┘
```

##### Tableaux
Un tableau est une séquence contiguë d'éléments du même type. Le nom du tableau est un **pointeur vers son premier élément**.

```c
int arr[5] = {10, 20, 30, 40, 50};
/* arr == &arr[0] */
/* *(arr + 2) == arr[2] == 30 */
```

##### Chaînes de caractères
En C, une chaîne est un **tableau de `char`** terminé par le caractère nul `\0`.

```
char str[] = "Hello";
┌───┬───┬───┬───┬───┬────┐
│ H │ e │ l │ l │ o │ \0 │
└───┴───┴───┴───┴───┴────┘
  0   1   2   3   4   5
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-reset_to_98.c` | Modifie une valeur via pointeur |
| `2-strlen.c` | Calcule la longueur d'une chaîne |
| `0-memset.c` | Remplit une zone mémoire |
| `0-strcat.c` | Concatène deux chaînes |
| `100-atoi.c` | Convertit une chaîne en entier |

#### 💻 Exemple - strlen personnalisé
```c
int _strlen(char *s)
{
    int i = 0;
    
    while (s[i] != '\0')  /* Tant qu'on n'atteint pas le terminateur */
        i++;
    
    return (i);
}
```

#### 💻 Exemple - memset personnalisé
```c
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;
    
    for (i = 0; i < n; i++)
        s[i] = b;  /* Remplit chaque octet avec b */
    
    return (s);
}
```

#### 🔑 Pourquoi c'est important ?
Les pointeurs sont **essentiels** pour :
- Modifier des variables dans des fonctions
- Créer des structures de données dynamiques
- Optimiser les performances (éviter les copies)
- Interagir avec le système d'exploitation

---

### 6️⃣ recursion

#### 📝 Présentation
La **récursivité** est une technique où une fonction s'appelle elle-même. Ce projet explore cette approche élégante pour résoudre des problèmes mathématiques.

#### 🧠 Concepts abordés
- **Cas de base** : condition d'arrêt pour éviter une récursion infinie
- **Cas récursif** : appel de la fonction avec des paramètres modifiés
- **Pile d'appels** : chaque appel crée un nouveau contexte d'exécution

```
factorial(4)
├── 4 * factorial(3)
│   ├── 3 * factorial(2)
│   │   ├── 2 * factorial(1)
│   │   │   └── return 1  (cas de base)
│   │   └── return 2 * 1 = 2
│   └── return 3 * 2 = 6
└── return 4 * 6 = 24
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `3-factorial.c` | Calcule la factorielle de n |
| `4-pow_recursion.c` | Calcule x^y récursivement |
| `5-sqrt_recursion.c` | Trouve la racine carrée entière |
| `6-is_prime_number.c` | Vérifie si un nombre est premier |

#### 💻 Exemple - Factorielle
```c
int factorial(int n)
{
    if (n < 0)              /* Cas invalide */
        return (-1);
    
    if (n == 0 || n == 1)   /* Cas de base : 0! = 1! = 1 */
        return (1);
    
    return n * factorial(n - 1);  /* Cas récursif */
}
```

#### 💻 Exemple - Puissance
```c
int _pow_recursion(int x, int y)
{
    if (y < 0)
        return (-1);
    
    if (y == 0)             /* x^0 = 1 pour tout x */
        return (1);
    
    return x * _pow_recursion(x, y - 1);
}
```

#### 🔑 Pourquoi c'est important ?
La récursivité est idéale pour :
- Les structures de données arborescentes
- Les algorithmes de tri (quicksort, mergesort)
- Les problèmes de recherche (backtracking)
- La résolution de puzzles (tours de Hanoï)

---

### 7️⃣ argc_argv

#### 📝 Présentation
Les programmes C peuvent recevoir des **arguments de ligne de commande**. Ce projet enseigne comment les récupérer et les traiter.

#### 🧠 Concepts abordés
- `argc` : **argument count** - nombre d'arguments
- `argv` : **argument vector** - tableau de chaînes contenant les arguments
- Conversion de chaînes en nombres avec `atoi()`

```bash
$ ./program hello world
```
```
argv[0] = "./program"
argv[1] = "hello"
argv[2] = "world"
argc = 3
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-whatsmyname.c` | Affiche le nom du programme |
| `1-args.c` | Affiche le nombre d'arguments |
| `2-args.c` | Affiche tous les arguments |
| `3-mul.c` | Multiplie deux nombres passés en arguments |
| `4-add.c` | Additionne tous les nombres passés |

#### 💻 Exemple - Multiplication
```c
int main(int argc, char **argv)
{
    int a, b;
    
    if (argc != 3)              /* Vérification du nombre d'arguments */
    {
        printf("Error\n");
        return (1);
    }
    
    a = atoi(argv[1]);          /* Conversion string → int */
    b = atoi(argv[2]);
    
    printf("%d\n", a * b);
    return (0);
}
```

#### 🔑 Pourquoi c'est important ?
Les arguments en ligne de commande permettent :
- La création d'**outils CLI** (Command Line Interface)
- L'**automatisation** via scripts
- La **flexibilité** des programmes

---

### 8️⃣ malloc_free

#### 📝 Présentation
L'**allocation dynamique de mémoire** est l'une des caractéristiques les plus puissantes (et dangereuses) du C. Ce projet enseigne comment allouer et libérer la mémoire manuellement.

#### 🧠 Concepts abordés

##### Le Heap (tas) vs la Stack (pile)

| Stack | Heap |
|-------|------|
| Allocation automatique | Allocation manuelle |
| Taille fixe | Taille variable |
| Libération automatique | Libération manuelle requise |
| Variables locales | Données persistantes |

##### Fonctions clés
- `malloc(size)` : alloue `size` octets et retourne un pointeur
- `free(ptr)` : libère la mémoire pointée par `ptr`

```c
int *ptr = malloc(sizeof(int) * 10);  /* Alloue 10 entiers */
if (ptr == NULL)
    return (NULL);  /* Toujours vérifier le retour de malloc ! */
/* ... utilisation ... */
free(ptr);  /* Libération obligatoire */
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-create_array.c` | Crée un tableau de chars dynamique |
| `1-strdup.c` | Duplique une chaîne en mémoire |
| `2-str_concat.c` | Concatène deux chaînes dynamiquement |
| `3-alloc_grid.c` | Crée une matrice 2D dynamique |
| `4-free_grid.c` | Libère une matrice 2D |

#### 💻 Exemple - Création de tableau
```c
char *create_array(unsigned int size, char c)
{
    char *array;
    unsigned int i;
    
    if (size == 0)
        return (NULL);
    
    array = malloc(size * sizeof(char));  /* Allocation */
    if (array == NULL)
        return (NULL);
    
    for (i = 0; i < size; i++)
        array[i] = c;  /* Initialisation */
    
    return (array);
}
```

#### 💻 Exemple - Matrice 2D
```c
int **alloc_grid(int width, int height)
{
    int **grid;
    int i, j;
    
    grid = malloc(height * sizeof(int *));  /* Lignes */
    
    for (i = 0; i < height; i++)
    {
        grid[i] = malloc(width * sizeof(int));  /* Colonnes */
        
        for (j = 0; j < width; j++)
            grid[i][j] = 0;  /* Initialisation à 0 */
    }
    
    return (grid);
}
```

#### 🔑 Pourquoi c'est important ?
L'allocation dynamique est **indispensable** pour :
- Gérer des données de taille inconnue à la compilation
- Créer des structures de données complexes
- Optimiser l'utilisation mémoire

#### ⚠️ Pièges courants
- **Memory leak** : oublier de `free()`
- **Double free** : libérer deux fois la même zone
- **Use after free** : utiliser un pointeur après `free()`
- **Buffer overflow** : écrire au-delà de la zone allouée

---

### 9️⃣ more_malloc_free

#### 📝 Présentation
Exercices avancés sur l'allocation mémoire, incluant des fonctions de sécurité et des réimplémentations de fonctions standard.

#### 🧠 Concepts abordés
- **Gestion d'erreurs robuste** avec `exit()`
- **calloc** : allocation avec initialisation à zéro
- **Concaténation sécurisée** avec contrôle du nombre de caractères

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-malloc_checked.c` | Malloc qui termine le programme en cas d'échec |
| `1-string_nconcat.c` | Concatène n caractères de deux chaînes |
| `2-calloc.c` | Réimplémentation de calloc |

#### 💻 Exemple - malloc_checked
```c
void *malloc_checked(unsigned int b)
{
    void *ptr;
    
    ptr = malloc(b);
    
    if (ptr == NULL)
        exit(98);  /* Termine le programme avec code 98 */
    
    return (ptr);
}
```

#### 💻 Exemple - _calloc
```c
void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *ptr;
    unsigned int i, total;
    
    if (nmemb == 0 || size == 0)
        return (NULL);
    
    total = nmemb * size;
    ptr = malloc(total);
    
    if (ptr == NULL)
        return (NULL);
    
    for (i = 0; i < total; i++)
        ptr[i] = 0;  /* Initialise à zéro */
    
    return ((void *)ptr);
}
```

---

### 🔟 structures_typedef

#### 📝 Présentation
Les **structures** permettent de regrouper des variables de types différents sous un même nom. Ce projet introduit également les **typedef** pour créer des alias de types.

#### 🧠 Concepts abordés

##### Structures
```c
struct dog {
    char *name;    /* Pointeur vers le nom */
    float age;     /* Âge en années */
    char *owner;   /* Pointeur vers le propriétaire */
};
```

##### Typedef
```c
typedef struct dog dog_t;  /* dog_t est maintenant un alias pour struct dog */
```

##### Accès aux membres
```c
struct dog buddy;
buddy.name = "Buddy";      /* Avec une variable */

struct dog *ptr = &buddy;
ptr->name = "Max";         /* Avec un pointeur (équivalent à (*ptr).name) */
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `dog.h` | Définition de la structure et des prototypes |
| `1-init_dog.c` | Initialise une structure existante |
| `2-print_dog.c` | Affiche les informations d'un chien |
| `4-new_dog.c` | Crée un nouveau chien dynamiquement |
| `5-free_dog.c` | Libère la mémoire d'un chien |

#### 💻 Exemple - Création d'une structure
```c
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;
    
    d = malloc(sizeof(dog_t));
    if (d == NULL)
        return (NULL);
    
    /* Copie du nom (allocation séparée) */
    d->name = strdup(name);
    d->age = age;
    d->owner = strdup(owner);
    
    return (d);
}
```

#### 🔑 Pourquoi c'est important ?
Les structures permettent de :
- Modéliser des **entités du monde réel**
- Créer des **types de données personnalisés**
- Organiser les données de manière **logique**
- Préparer la transition vers la **POO** (C++, Java)

---

### 1️⃣1️⃣ function_pointers

#### 📝 Présentation
Un **pointeur de fonction** stocke l'adresse d'une fonction. Cela permet de passer des fonctions en argument et de créer des comportements dynamiques.

#### 🧠 Concepts abordés

##### Syntaxe d'un pointeur de fonction
```c
/* Déclaration d'un pointeur vers une fonction prenant un int et retournant void */
void (*f)(int);

/* Attribution */
f = ma_fonction;

/* Appel */
f(42);  /* Équivalent à ma_fonction(42) */
```

##### Tableaux de pointeurs de fonctions
```c
typedef struct op {
    char *op;
    int (*f)(int, int);  /* Pointeur vers fonction prenant 2 int */
} op_t;
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-print_name.c` | Appelle une fonction passée en paramètre |
| `1-array_iterator.c` | Applique une fonction à chaque élément d'un tableau |
| `2-int_index.c` | Recherche avec une fonction de comparaison |
| `3-get_op_func.c` | Sélecteur de fonction selon l'opérateur |
| `3-op_functions.c` | Fonctions d'opérations arithmétiques |
| `3-calc.h` | Structure pour la calculatrice |

#### 💻 Exemple - Itérateur de tableau
```c
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;
    
    if (array == NULL || action == NULL)
        return;
    
    for (i = 0; i < size; i++)
        action(array[i]);  /* Appelle la fonction sur chaque élément */
}
```

#### 💻 Exemple - Sélecteur de fonction
```c
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i = 0;
    
    while (ops[i].op != NULL)
    {
        if (strcmp(ops[i].op, s) == 0)
            return (ops[i].f);  /* Retourne le pointeur de fonction */
        i++;
    }
    return (NULL);
}
```

#### 🔑 Pourquoi c'est important ?
Les pointeurs de fonctions permettent :
- Les **callbacks** (fonctions de rappel)
- Les **design patterns** (stratégie, factory)
- L'implémentation de **machines à états**
- La création de **plugins** et bibliothèques dynamiques

---

### 1️⃣2️⃣ variadic_functions

#### 📝 Présentation
Les **fonctions variadiques** acceptent un nombre variable d'arguments, comme `printf()`. Ce projet enseigne leur implémentation avec les macros `<stdarg.h>`.

#### 🧠 Concepts abordés

##### Macros de stdarg.h
| Macro | Description |
|-------|-------------|
| `va_list` | Type pour stocker la liste d'arguments |
| `va_start(ap, last)` | Initialise la liste après le dernier argument fixe |
| `va_arg(ap, type)` | Récupère le prochain argument du type spécifié |
| `va_end(ap)` | Termine l'utilisation de la liste |

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `0-sum_them_all.c` | Somme un nombre variable d'entiers |
| `1-print_numbers.c` | Affiche des nombres avec séparateur |
| `2-print_strings.c` | Affiche des chaînes avec séparateur |
| `3-print_all.c` | Affiche des types variés selon un format |

#### 💻 Exemple - Somme variadique
```c
int sum_them_all(const unsigned int n, ...)
{
    va_list boite;
    unsigned int i;
    int sum = 0;
    
    if (n == 0)
        return (0);
    
    va_start(boite, n);  /* Initialise après n */
    
    for (i = 0; i < n; i++)
        sum += va_arg(boite, int);  /* Récupère chaque int */
    
    va_end(boite);
    return (sum);
}
```

#### 💻 Exemple - print_all (mini printf)
```c
void print_all(const char * const format, ...)
{
    va_list boite;
    unsigned int i = 0;
    
    va_start(boite, format);
    
    while (format && format[i])
    {
        switch (format[i])
        {
            case 'c': printf("%c", va_arg(boite, int)); break;
            case 'i': printf("%d", va_arg(boite, int)); break;
            case 'f': printf("%f", va_arg(boite, double)); break;
            case 's': printf("%s", va_arg(boite, char *)); break;
        }
        i++;
    }
    
    va_end(boite);
    printf("\n");
}
```

#### 🔑 Pourquoi c'est important ?
Les fonctions variadiques sont utilisées dans :
- Les fonctions de **formatage** (`printf`, `sprintf`)
- Les **wrappers** de fonctions
- Les **systèmes de logging**

---

### 1️⃣3️⃣ singly_linked_lists

#### 📝 Présentation
Une **liste chaînée** est une structure de données où chaque élément (nœud) contient une valeur et un pointeur vers l'élément suivant. C'est l'une des structures de données les plus fondamentales.

#### 🧠 Concepts abordés

##### Structure d'un nœud
```c
typedef struct list_s
{
    char *str;              /* Donnée : chaîne de caractères */
    unsigned int len;       /* Longueur de la chaîne */
    struct list_s *next;    /* Pointeur vers le nœud suivant */
} list_t;
```

##### Représentation visuelle
```
┌─────────┐    ┌─────────┐    ┌─────────┐
│  "Hi"   │    │ "World" │    │  "!"    │
│  len:2  │───►│  len:5  │───►│  len:1  │───► NULL
└─────────┘    └─────────┘    └─────────┘
    HEAD
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `lists.h` | Définition de la structure list_t |
| `0-print_list.c` | Parcourt et affiche tous les nœuds |
| `1-list_len.c` | Compte le nombre de nœuds |
| `2-add_node.c` | Ajoute un nœud au début |
| `3-add_node_end.c` | Ajoute un nœud à la fin |
| `4-free_list.c` | Libère toute la liste |

#### 💻 Exemple - Ajout au début
```c
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
    
    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);
    
    new_node->str = strdup(str);       /* Copie la chaîne */
    new_node->len = strlen(str);
    new_node->next = *head;            /* Pointe vers l'ancien premier */
    *head = new_node;                  /* Devient le nouveau premier */
    
    return (new_node);
}
```

#### 🔑 Avantages des listes chaînées
- **Insertion/suppression O(1)** au début
- **Taille dynamique** sans réallocation
- **Flexibilité** de la structure

#### ⚠️ Inconvénients
- **Accès O(n)** (pas d'indexation directe)
- **Mémoire supplémentaire** pour les pointeurs

---

### 1️⃣4️⃣ doubly_linked_lists

#### 📝 Présentation
Une **liste doublement chaînée** ajoute un pointeur vers le nœud précédent, permettant un parcours dans les deux sens.

#### 🧠 Concepts abordés

##### Structure d'un nœud
```c
typedef struct dlistint_s
{
    int n;                      /* Donnée : entier */
    struct dlistint_s *prev;    /* Pointeur vers le précédent */
    struct dlistint_s *next;    /* Pointeur vers le suivant */
} dlistint_t;
```

##### Représentation visuelle
```
NULL ◄─── ┌─────┐ ◄──► ┌─────┐ ◄──► ┌─────┐ ───► NULL
          │  1  │      │  2  │      │  3  │
          └─────┘      └─────┘      └─────┘
            HEAD                      TAIL
```

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `lists.h` | Définition de la structure dlistint_t |
| `0-print_dlistint.c` | Affiche la liste |
| `2-add_dnodeint.c` | Ajoute au début |
| `3-add_dnodeint_end.c` | Ajoute à la fin |
| `5-get_dnodeint.c` | Accède à un nœud par index |
| `6-sum_dlistint.c` | Somme toutes les valeurs |
| `7-insert_dnodeint.c` | Insère à une position donnée |
| `8-delete_dnodeint.c` | Supprime à une position donnée |

#### 💻 Exemple - Insertion à un index
```c
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp = *h;
    unsigned int count;
    
    if (idx == 0)
        return (add_dnodeint(h, n));  /* Cas début */
    
    for (count = 0; temp && count < idx - 1; count++)
        temp = temp->next;
    
    if (temp == NULL)
        return (NULL);  /* Index trop grand */
    
    new_node = malloc(sizeof(dlistint_t));
    new_node->n = n;
    
    /* Mise à jour des pointeurs */
    new_node->next = temp->next;
    new_node->prev = temp;
    
    if (new_node->next)
        new_node->next->prev = new_node;
    
    temp->next = new_node;
    
    return (new_node);
}
```

#### 🔑 Avantages par rapport aux listes simples
- **Parcours bidirectionnel**
- **Suppression O(1)** si on a le pointeur vers le nœud
- Implémentation de **deques** (double-ended queues)

---

### 1️⃣5️⃣ file_io

#### 📝 Présentation
Ce projet couvre les **entrées/sorties fichiers** au niveau système avec les appels systèmes Unix : `open()`, `read()`, `write()`, `close()`.

#### 🧠 Concepts abordés

##### File Descriptors
Un **file descriptor** (fd) est un entier qui identifie un fichier ouvert.

| fd | Description |
|----|-------------|
| 0  | stdin (entrée standard) |
| 1  | stdout (sortie standard) |
| 2  | stderr (erreur standard) |
| 3+ | Fichiers ouverts par le programme |

##### Appels systèmes
```c
#include <fcntl.h>
#include <unistd.h>

int fd = open("file.txt", O_RDONLY);           /* Ouvre en lecture */
ssize_t n = read(fd, buffer, size);            /* Lit size octets */
ssize_t m = write(fd, buffer, size);           /* Écrit size octets */
int ret = close(fd);                           /* Ferme le fichier */
```

##### Flags d'ouverture
| Flag | Description |
|------|-------------|
| `O_RDONLY` | Lecture seule |
| `O_WRONLY` | Écriture seule |
| `O_RDWR` | Lecture et écriture |
| `O_CREAT` | Crée le fichier s'il n'existe pas |
| `O_TRUNC` | Vide le fichier s'il existe |
| `O_APPEND` | Écrit à la fin du fichier |

#### 📄 Fichiers clés

| Fichier | Description |
|---------|-------------|
| `main.h` | Prototypes et includes système |
| `0-read_textfile.c` | Lit et affiche un fichier texte |
| `1-create_file.c` | Crée un fichier avec du contenu |
| `2-append_text_to_file.c` | Ajoute du texte à un fichier existant |
| `3-cp.c` | Programme de copie de fichiers (comme `cp`) |

#### 💻 Exemple - Lecture de fichier
```c
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t rd, wr;
    char *buffer;
    
    if (filename == NULL)
        return (0);
    
    buffer = malloc(letters);
    if (buffer == NULL)
        return (0);
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buffer);
        return (0);
    }
    
    rd = read(fd, buffer, letters);    /* Lit les octets */
    wr = write(STDOUT_FILENO, buffer, rd);  /* Affiche */
    
    free(buffer);
    close(fd);
    
    return (wr);
}
```

#### 💻 Exemple - Copie de fichiers
```c
int main(int argc, char *argv[])
{
    int fd_from, fd_to, r, w;
    char buf[1024];
    
    fd_from = open(argv[1], O_RDONLY);
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    
    while ((r = read(fd_from, buf, 1024)) > 0)
    {
        w = write(fd_to, buf, r);
        if (w != r)
            /* Gestion d'erreur */
    }
    
    close(fd_from);
    close(fd_to);
    
    return (0);
}
```

#### 🔑 Pourquoi c'est important ?
Les I/O fichiers sont essentiels pour :
- La **persistance des données**
- La communication **inter-processus** (pipes)
- Le développement de **serveurs**
- La manipulation de **fichiers de configuration**

---

## ⚙️ Compilation et exécution

### Compilation standard
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o program
```

### Exemple avec un fichier main
```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-function.c -o test

# Exécuter
./test
```

### Vérification mémoire avec Valgrind
```bash
valgrind --leak-check=full ./program
```

---

## 📏 Conventions de code

Ce repository suit le **Betty style guide** de Holberton :

### Règles principales
- **Indentation** : 1 tabulation (pas d'espaces)
- **Longueur de ligne** : max 80 caractères
- **Accolades** : style K&R
- **Fonctions** : max 40 lignes, max 5 variables locales
- **Fichiers** : max 5 fonctions par fichier
- **Nommage** : snake_case pour les fonctions et variables

### Vérification
```bash
betty *.c *.h
```

---

## 👨‍💻 Auteur

**Maxim** - Étudiant Holberton School

[![GitHub](https://img.shields.io/badge/GitHub-maxim880000-181717?style=flat&logo=github)](https://github.com/maxim880000)

---

## 📄 License

Ce projet fait partie du curriculum de **Holberton School**.

---

<p align="center">
  <i>« The only way to learn a new programming language is by writing programs in it. »</i><br>
  — Dennis Ritchie, créateur du C
</p>
