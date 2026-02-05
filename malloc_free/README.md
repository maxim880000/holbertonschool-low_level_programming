# 🧠 Malloc & Free - Allocation dynamique de mémoire

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Intermédiaire/Avancé-red?style=for-the-badge" alt="Avancé"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Stack vs Heap](#-stack-vs-heap)
4. [La fonction malloc](#-la-fonction-malloc)
5. [La fonction free](#-la-fonction-free)
6. [Fichiers du projet](#-fichiers-du-projet)
7. [Détail des fichiers](#-détail-des-fichiers)
8. [Tableaux 2D dynamiques](#-tableaux-2d-dynamiques)
9. [Pièges et erreurs courantes](#-pièges-et-erreurs-courantes)
10. [Compilation et exécution](#-compilation-et-exécution)
11. [Ressources](#-ressources)

---

## 📝 Description

Ce projet introduit l'**allocation dynamique de mémoire** en C, l'une des caractéristiques les plus puissantes et les plus délicates du langage. Contrairement aux tableaux statiques dont la taille doit être connue à la compilation, l'allocation dynamique permet de réserver de la mémoire pendant l'exécution du programme.

Vous apprendrez à utiliser `malloc()` pour allouer de la mémoire et `free()` pour la libérer, évitant ainsi les **fuites de mémoire** (memory leaks).

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre la différence entre la **pile (stack)** et le **tas (heap)**
- ✅ Utiliser `malloc()` pour allouer de la mémoire dynamiquement
- ✅ Utiliser `free()` pour libérer la mémoire
- ✅ Vérifier le retour de `malloc()` (gestion des erreurs)
- ✅ Créer des **tableaux dynamiques** à une et deux dimensions
- ✅ Éviter les **fuites de mémoire**
- ✅ Utiliser `valgrind` pour détecter les problèmes mémoire

---

## 📊 Stack vs Heap

### La mémoire d'un programme

```
┌─────────────────────────────────────────────┐
│                   STACK                      │ ← Variables locales
│              (Pile d'appels)                 │   Allocation auto
│                    ↓                         │   Libération auto
│   ┌─────────────────────────────────────┐   │
│   │  Variables locales de main()        │   │
│   ├─────────────────────────────────────┤   │
│   │  Variables locales de fonction()    │   │
│   └─────────────────────────────────────┘   │
│                    ↓                         │
│                   ...                        │
│                                             │
│                    ↑                         │
│   ┌─────────────────────────────────────┐   │
│   │       Mémoire allouée avec         │   │
│   │       malloc(), calloc()           │   │
│   └─────────────────────────────────────┘   │
│                   HEAP                       │ ← Allocation manuelle
│                  (Tas)                       │   Libération manuelle
└─────────────────────────────────────────────┘
```

### Comparaison Stack vs Heap

| Caractéristique | Stack | Heap |
|-----------------|-------|------|
| Allocation | Automatique | Manuelle (`malloc`) |
| Libération | Automatique | Manuelle (`free`) |
| Taille | Limitée (~1-8 MB) | Grande (mémoire disponible) |
| Vitesse | Très rapide | Plus lente |
| Portée | Locale à la fonction | Globale (via pointeur) |
| Risque | Stack overflow | Memory leaks |

---

## 📦 La fonction malloc

### Prototype
```c
#include <stdlib.h>
void *malloc(size_t size);
```

### Comportement
- Alloue `size` octets de mémoire non initialisée
- Retourne un pointeur vers le début de la zone allouée
- Retourne `NULL` si l'allocation échoue

### Syntaxe courante

```c
/* Allouer un entier */
int *p = malloc(sizeof(int));

/* Allouer un tableau de 10 entiers */
int *arr = malloc(10 * sizeof(int));

/* Allouer une chaîne de caractères */
char *str = malloc(100 * sizeof(char));
```

### ⚠️ TOUJOURS vérifier le retour de malloc

```c
int *ptr = malloc(sizeof(int));
if (ptr == NULL)
{
    /* Gestion de l'erreur */
    return (NULL);
}
/* Utilisation de ptr */
```

---

## 🗑️ La fonction free

### Prototype
```c
#include <stdlib.h>
void free(void *ptr);
```

### Comportement
- Libère la mémoire pointée par `ptr`
- `ptr` doit pointer vers une zone allouée par `malloc`, `calloc` ou `realloc`
- Après `free()`, le pointeur devient **invalide** (dangling pointer)

### Exemple complet

```c
#include <stdlib.h>

int main(void)
{
    /* Allocation */
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL)
        return (1);

    /* Utilisation */
    arr[0] = 10;
    arr[1] = 20;

    /* Libération */
    free(arr);
    arr = NULL;  /* Bonne pratique : évite le dangling pointer */

    return (0);
}
```

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-create_array.c` | Crée un tableau de chars initialisé | `char *create_array(unsigned int size, char c)` |
| `1-strdup.c` | Duplique une chaîne | `char *_strdup(char *str)` |
| `2-str_concat.c` | Concatène deux chaînes | `char *str_concat(char *s1, char *s2)` |
| `3-alloc_grid.c` | Crée une grille 2D | `int **alloc_grid(int width, int height)` |
| `4-free_grid.c` | Libère une grille 2D | `void free_grid(int **grid, int height)` |
| `main.h` | Prototypes des fonctions | - |

---

## 📄 Détail des fichiers

### 0-create_array.c

```c
#include <stdlib.h>
#include "main.h"

char *create_array(unsigned int size, char c)
{
    char *array;
    unsigned int i;

    /* Cas spécial : taille 0 */
    if (size == 0)
        return (NULL);

    /* Allocation */
    array = malloc(size * sizeof(char));
    if (array == NULL)
        return (NULL);

    /* Initialisation */
    for (i = 0; i < size; i++)
        array[i] = c;

    return (array);
}
```

**Usage** :
```c
char *buffer = create_array(10, 'X');
/* buffer = "XXXXXXXXXX" */
free(buffer);
```

---

### 1-strdup.c

```c
#include <stdlib.h>
#include "main.h"

char *_strdup(char *str)
{
    int len;
    char *dup;
    int i;

    if (str == NULL)
        return (NULL);

    /* Calcul de la longueur */
    for (len = 0; str[len] != '\0'; len++)
        ;

    /* Allocation (+1 pour le \0) */
    dup = malloc((len + 1) * sizeof(char));
    if (dup == NULL)
        return (NULL);

    /* Copie */
    for (i = 0; i < len; i++)
        dup[i] = str[i];
    dup[len] = '\0';

    return (dup);
}
```

**Visualisation** :
```
Original:  str → "Hello\0"

Après _strdup:
           dup → "Hello\0"  (nouvelle zone mémoire)
```

---

### 2-str_concat.c

```c
char *str_concat(char *s1, char *s2)
{
    int len1, len2;
    char *result;
    int i, j;

    /* Gestion des NULL */
    if (s1 == NULL) s1 = "";
    if (s2 == NULL) s2 = "";

    /* Calcul des longueurs */
    for (len1 = 0; s1[len1]; len1++);
    for (len2 = 0; s2[len2]; len2++);

    /* Allocation */
    result = malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);

    /* Copie de s1 */
    for (i = 0; s1[i]; i++)
        result[i] = s1[i];

    /* Copie de s2 */
    for (j = 0; s2[j]; j++)
        result[i + j] = s2[j];

    result[i + j] = '\0';
    return (result);
}
```

**Visualisation** :
```
s1 = "Hello"    s2 = " World"

Résultat: "Hello World\0"
          └──────┬──────┘
       len1 + len2 + 1 octets
```

---

## 📐 Tableaux 2D dynamiques

### 3-alloc_grid.c

Un tableau 2D dynamique est un **tableau de pointeurs**, où chaque pointeur pointe vers une ligne.

```c
int **alloc_grid(int width, int height)
{
    int **grid;
    int i, j;

    if (width <= 0 || height <= 0)
        return (NULL);

    /* Étape 1 : Allouer le tableau de pointeurs (lignes) */
    grid = malloc(height * sizeof(int *));
    if (grid == NULL)
        return (NULL);

    /* Étape 2 : Allouer chaque ligne */
    for (i = 0; i < height; i++)
    {
        grid[i] = malloc(width * sizeof(int));

        /* En cas d'échec : libérer tout ce qui a été alloué */
        if (grid[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(grid[j]);
            free(grid);
            return (NULL);
        }

        /* Initialiser à 0 */
        for (j = 0; j < width; j++)
            grid[i][j] = 0;
    }

    return (grid);
}
```

### Visualisation mémoire

```
Pour alloc_grid(3, 2) :   width=3, height=2

grid (int **)
┌───────────┐
│  grid[0]  │───────► ┌────┬────┬────┐
├───────────┤         │ 0  │ 0  │ 0  │  (width éléments)
│  grid[1]  │───────► ├────┼────┼────┤
└───────────┘         │ 0  │ 0  │ 0  │
 (height              └────┴────┴────┘
  pointeurs)

Accès : grid[ligne][colonne]
        grid[0][2] → élément ligne 0, colonne 2
```

---

### 4-free_grid.c

```c
void free_grid(int **grid, int height)
{
    int i;

    if (grid == NULL)
        return;

    /* Étape 1 : Libérer chaque ligne */
    for (i = 0; i < height; i++)
        free(grid[i]);

    /* Étape 2 : Libérer le tableau de pointeurs */
    free(grid);
}
```

### ⚠️ Ordre de libération

```
IMPORTANT : Libérer dans l'ordre INVERSE de l'allocation !

Allocation :     1. grid        2. grid[0]    3. grid[1]    ...
Libération :     ...    2. grid[1]    1. grid[0]    0. grid
```

---

## ⚠️ Pièges et erreurs courantes

### 1. Memory Leak (Fuite de mémoire)

```c
/* MAUVAIS : on perd le pointeur ! */
void bad_function(void)
{
    int *p = malloc(100);
    /* ... utilisation ... */
    /* Oubli de free(p) ! La mémoire est perdue */
}
```

### 2. Double Free

```c
/* MAUVAIS : libération double */
int *p = malloc(sizeof(int));
free(p);
free(p);  /* CRASH ou comportement indéfini ! */
```

### 3. Use After Free

```c
/* MAUVAIS : utilisation après libération */
int *p = malloc(sizeof(int));
*p = 42;
free(p);
printf("%d\n", *p);  /* Comportement indéfini ! */
```

### 4. Buffer Overflow

```c
/* MAUVAIS : écriture hors limites */
int *arr = malloc(5 * sizeof(int));
arr[10] = 42;  /* Débordement ! */
```

### 5. Oublier de vérifier malloc

```c
/* MAUVAIS : pas de vérification */
int *p = malloc(SIZE_MAX);  /* Peut échouer */
*p = 42;  /* Si p == NULL → CRASH */
```

---

## 🔧 Compilation et exécution

```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-create_array.c -o create_array
./create_array

# Vérifier les fuites de mémoire avec Valgrind
valgrind --leak-check=full ./create_array
```

### Sortie Valgrind idéale

```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 2 allocs, 2 frees, 1,024 bytes allocated
==12345== 
==12345== All heap blocks were freed -- no leaks are possible
```

---

## 💡 Bonnes pratiques

1. **Toujours vérifier malloc** : `if (ptr == NULL)`
2. **Toujours free ce qui est malloc** : pas de fuite
3. **Mettre le pointeur à NULL après free** : évite use-after-free
4. **Libérer dans l'ordre inverse** : pour les structures complexes
5. **Utiliser Valgrind** : pour détecter les problèmes

```c
/* Pattern recommandé */
int *ptr = malloc(size);
if (ptr == NULL)
    return (NULL);

/* ... utilisation ... */

free(ptr);
ptr = NULL;  /* Optionnel mais recommandé */
```

---

## 📚 Ressources

- [malloc() - cppreference](https://en.cppreference.com/w/c/memory/malloc)
- [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html)
- [Memory Leaks - GeeksforGeeks](https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Avec un grand pouvoir (malloc) vient une grande responsabilité (free). »</i>
</p>
