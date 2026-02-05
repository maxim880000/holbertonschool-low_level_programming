# 🔒 More Malloc & Free - Gestion avancée de la mémoire

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Avancé-red?style=for-the-badge" alt="Avancé"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Nouvelles fonctions](#-nouvelles-fonctions)
4. [Fichiers du projet](#-fichiers-du-projet)
5. [Détail des fichiers](#-détail-des-fichiers)
6. [Gestion robuste des erreurs](#-gestion-robuste-des-erreurs)
7. [Compilation et exécution](#-compilation-et-exécution)
8. [Ressources](#-ressources)

---

## 📝 Description

Ce projet approfondit l'allocation dynamique avec des exercices plus avancés. Vous apprendrez à :
- Gérer les erreurs d'allocation de manière **robuste** avec `exit()`
- Implémenter `_calloc()` (allocation avec initialisation à zéro)
- Créer des fonctions de concaténation avec contrôle de longueur
- Générer des tableaux d'entiers dans une plage donnée

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Utiliser `exit()` pour terminer un programme en cas d'erreur critique
- ✅ Comprendre la différence entre `malloc` et `calloc`
- ✅ Implémenter des fonctions d'allocation **sécurisées**
- ✅ Gérer les cas limites avec précision
- ✅ Créer des tableaux dynamiques avec des valeurs calculées

---

## 🆕 Nouvelles fonctions

### malloc_checked : malloc avec exit

Contrairement à `malloc` standard qui retourne `NULL` en cas d'échec, `malloc_checked` **termine le programme** avec le code de sortie `98`.

```c
void *malloc_checked(unsigned int b);
```

### calloc : malloc avec initialisation

`calloc` alloue ET initialise la mémoire à **zéro**.

```c
/* malloc : mémoire non initialisée (contient des "déchets") */
int *p1 = malloc(10 * sizeof(int));

/* calloc : mémoire initialisée à 0 */
int *p2 = calloc(10, sizeof(int));
```

| Aspect | malloc | calloc |
|--------|--------|--------|
| Initialisation | Non | Oui (à 0) |
| Paramètres | `size` total | `nmemb` × `size` |
| Usage | Quand on va tout remplir | Quand on veut des zéros |

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-malloc_checked.c` | malloc qui exit(98) en cas d'échec | `void *malloc_checked(unsigned int b)` |
| `1-string_nconcat.c` | Concatène s1 et n premiers chars de s2 | `char *string_nconcat(char *s1, char *s2, unsigned int n)` |
| `2-calloc.c` | Réimplémentation de calloc | `void *_calloc(unsigned int nmemb, unsigned int size)` |
| `3-array_range.c` | Crée un tableau de min à max | `int *array_range(int min, int max)` |
| `main.h` | Prototypes des fonctions | - |

---

## 📄 Détail des fichiers

### 0-malloc_checked.c

```c
#include <stdlib.h>
#include "main.h"

void *malloc_checked(unsigned int b)
{
    void *ptr;

    ptr = malloc(b);

    if (ptr == NULL)
        exit(98);  /* Termine le programme avec code 98 */

    return (ptr);
}
```

**Pourquoi utiliser exit() ?**
- Dans certains cas, un échec d'allocation est **fatal**
- Le programme ne peut pas continuer sans cette mémoire
- `exit(98)` informe le système d'exploitation de l'erreur

**Comparaison** :
```c
/* Avec malloc standard */
ptr = malloc(size);
if (ptr == NULL)
{
    /* On doit gérer l'erreur nous-mêmes */
    return (NULL);
}

/* Avec malloc_checked */
ptr = malloc_checked(size);
/* Si on arrive ici, ptr est valide (sinon le programme est terminé) */
```

---

### 1-string_nconcat.c

```c
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int len1 = 0, len2 = 0;
    unsigned int i, j;
    char *ptr;

    /* Gestion des NULL */
    if (s1 == NULL) s1 = "";
    if (s2 == NULL) s2 = "";

    /* Calcul des longueurs */
    while (s1[len1]) len1++;
    while (s2[len2]) len2++;

    /* Si n >= len2, on prend toute la chaîne s2 */
    if (n >= len2)
        n = len2;

    /* Allocation : s1 + n caractères de s2 + '\0' */
    ptr = malloc((len1 + n + 1) * sizeof(char));
    if (ptr == NULL)
        return (NULL);

    /* Copie de s1 */
    for (i = 0; i < len1; i++)
        ptr[i] = s1[i];

    /* Copie des n premiers caractères de s2 */
    for (j = 0; j < n; j++)
        ptr[i + j] = s2[j];

    ptr[i + j] = '\0';
    return (ptr);
}
```

**Exemple** :
```c
char *result = string_nconcat("Hello ", "World!", 3);
/* result = "Hello Wor" */
```

---

### 2-calloc.c

```c
#include <stdlib.h>
#include "main.h"

void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *ptr;
    unsigned int i;
    unsigned int total;

    /* Vérification des paramètres */
    if (nmemb == 0 || size == 0)
        return (NULL);

    total = nmemb * size;

    /* Allocation */
    ptr = malloc(total);
    if (ptr == NULL)
        return (NULL);

    /* Initialisation à 0 */
    for (i = 0; i < total; i++)
        ptr[i] = 0;

    return ((void *)ptr);
}
```

**Visualisation** :
```
malloc(12) pour 3 ints :
┌────┬────┬────┐
│ ?? │ ?? │ ?? │  ← Valeurs indéfinies (garbage)
└────┴────┴────┘

_calloc(3, sizeof(int)) :
┌────┬────┬────┐
│  0 │  0 │  0 │  ← Tout est initialisé à 0
└────┴────┴────┘
```

---

### 3-array_range.c

```c
int *array_range(int min, int max)
{
    int *ptr;
    int size;
    int i;

    /* Validation */
    if (min > max)
        return (NULL);

    /* Calcul de la taille */
    size = max - min + 1;

    /* Allocation */
    ptr = malloc(size * sizeof(int));
    if (ptr == NULL)
        return (NULL);

    /* Remplissage */
    for (i = 0; i < size; i++)
        ptr[i] = min + i;

    return (ptr);
}
```

**Exemple** :
```c
int *arr = array_range(3, 7);
/* arr = [3, 4, 5, 6, 7] */
/* size = 7 - 3 + 1 = 5 éléments */
```

**Visualisation** :
```
array_range(3, 7):

size = max - min + 1 = 7 - 3 + 1 = 5

┌────┬────┬────┬────┬────┐
│  3 │  4 │  5 │  6 │  7 │
└────┴────┴────┴────┴────┘
 [0]  [1]  [2]  [3]  [4]

arr[i] = min + i
arr[0] = 3 + 0 = 3
arr[1] = 3 + 1 = 4
...
```

---

## 🛡️ Gestion robuste des erreurs

### Pattern avec exit()

```c
/* Pour les erreurs fatales */
void *critical_alloc(size_t size)
{
    void *ptr = malloc(size);
    
    if (ptr == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);  /* ou exit(98) */
    }
    
    return (ptr);
}
```

### Pattern avec retour NULL

```c
/* Pour les erreurs récupérables */
void *safe_alloc(size_t size)
{
    void *ptr = malloc(size);
    
    if (ptr == NULL)
        return (NULL);  /* L'appelant gère l'erreur */
    
    return (ptr);
}
```

### Quand utiliser quoi ?

| Situation | Approche |
|-----------|----------|
| Échec critique (pas de récupération possible) | `exit()` |
| L'appelant peut gérer l'erreur | Retourner `NULL` |
| Allocation dans une bibliothèque | Retourner `NULL` |
| Allocation dans le main d'un programme | `exit()` acceptable |

---

## 🔧 Compilation et exécution

```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-malloc_checked.c -o malloc_checked
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-calloc.c -o calloc_test
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-array_range.c -o array_range

# Exécuter
./malloc_checked
./calloc_test
./array_range

# Vérifier avec Valgrind
valgrind --leak-check=full ./calloc_test
```

---

## 📊 Comparaison malloc vs calloc

```
┌─────────────────────────────────────────────────────────────┐
│                    malloc(12)                               │
│  ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
│  │0xAB│0x12│0xFF│0x00│0xDE│0xAD│0xBE│0xEF│0x42│0x37│0x88│0x99│
│  └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
│              Contenu INDÉTERMINÉ (garbage)                  │
└─────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────┐
│                    calloc(12, 1)                            │
│  ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
│  │0x00│0x00│0x00│0x00│0x00│0x00│0x00│0x00│0x00│0x00│0x00│0x00│
│  └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
│              Tout est INITIALISÉ à 0                        │
└─────────────────────────────────────────────────────────────┘
```

---

## 📚 Ressources

- [calloc() - cppreference](https://en.cppreference.com/w/c/memory/calloc)
- [exit() - man page](https://man7.org/linux/man-pages/man3/exit.3.html)
- [Memory Allocation Best Practices](https://wiki.sei.cmu.edu/confluence/display/c/MEM00-C.+Allocate+and+free+memory+in+the+same+module%2C+at+the+same+level+of+abstraction)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Un bon programmeur sait quand exit() est la bonne réponse. »</i>
</p>
