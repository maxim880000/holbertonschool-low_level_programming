# 🏗️ Structures & Typedef - Types de données personnalisés

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Intermédiaire-orange?style=for-the-badge" alt="Intermédiaire"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Les structures en C](#-les-structures-en-c)
4. [Le mot-clé typedef](#-le-mot-clé-typedef)
5. [Fichiers du projet](#-fichiers-du-projet)
6. [Détail des fichiers](#-détail-des-fichiers)
7. [Allocation dynamique de structures](#-allocation-dynamique-de-structures)
8. [Compilation et exécution](#-compilation-et-exécution)
9. [Ressources](#-ressources)

---

## 📝 Description

Ce projet introduit les **structures** (`struct`) et le mot-clé **`typedef`** en C. Les structures permettent de regrouper des variables de types différents sous un même nom, créant ainsi des **types de données personnalisés**.

C'est un concept fondamental qui prépare à la programmation orientée objet et permet de modéliser des entités du monde réel.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Définir et utiliser des **structures**
- ✅ Accéder aux **membres** d'une structure avec `.` et `->`
- ✅ Utiliser **typedef** pour créer des alias de types
- ✅ Allouer des structures **dynamiquement**
- ✅ Libérer correctement la mémoire des structures
- ✅ Comprendre la **taille** des structures en mémoire

---

## 🧱 Les structures en C

### Définition d'une structure

```c
struct dog
{
    char *name;    /* Nom du chien (pointeur) */
    float age;     /* Âge en années */
    char *owner;   /* Nom du propriétaire */
};
```

### Déclaration de variables

```c
struct dog buddy;           /* Variable de type struct dog */
struct dog *ptr;            /* Pointeur vers struct dog */
```

### Accès aux membres

```c
/* Avec une variable : opérateur . (point) */
struct dog buddy;
buddy.name = "Buddy";
buddy.age = 3.5;
buddy.owner = "John";

/* Avec un pointeur : opérateur -> (flèche) */
struct dog *ptr = &buddy;
ptr->name = "Max";        /* Équivalent à (*ptr).name */
ptr->age = 4.0;
```

### Visualisation en mémoire

```
struct dog buddy;

┌──────────────────────────────────────────────┐
│              struct dog                      │
├──────────────────────────────────────────────┤
│  name (char *)  │  age (float)  │  owner     │
│     8 bytes     │    4 bytes    │  8 bytes   │
├─────────────────┼───────────────┼────────────┤
│   0x1234567     │     3.5       │ 0x2345678  │
│       │         │               │     │      │
│       ▼         │               │     ▼      │
│   "Buddy\0"     │               │  "John\0"  │
└─────────────────┴───────────────┴────────────┘
```

---

## 📛 Le mot-clé typedef

### Pourquoi typedef ?

`typedef` crée un **alias** pour un type existant, rendant le code plus lisible.

```c
/* Sans typedef : verbeux */
struct dog my_dog;
struct dog *ptr_dog;

/* Avec typedef : plus propre */
typedef struct dog dog_t;
dog_t my_dog;
dog_t *ptr_dog;
```

### Syntaxe combinée

```c
/* Définition et typedef en une fois */
typedef struct dog
{
    char *name;
    float age;
    char *owner;
} dog_t;

/* Utilisation */
dog_t buddy;
dog_t *ptr = &buddy;
```

### Exemples courants de typedef

```c
typedef unsigned int uint;
typedef unsigned char byte;
typedef struct node node_t;
typedef int (*compare_func)(int, int);  /* Pointeur de fonction */
```

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `dog.h` | Définition de la structure dog | - |
| `1-init_dog.c` | Initialise une structure dog | `void init_dog(struct dog *d, char *name, float age, char *owner)` |
| `2-print_dog.c` | Affiche les infos d'un chien | `void print_dog(struct dog *d)` |
| `4-new_dog.c` | Crée un nouveau chien (allocation) | `dog_t *new_dog(char *name, float age, char *owner)` |
| `5-free_dog.c` | Libère la mémoire d'un chien | `void free_dog(dog_t *d)` |

---

## 📄 Détail des fichiers

### dog.h

```c
#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Représente un chien
 * @name: Nom du chien
 * @age: Âge du chien
 * @owner: Propriétaire du chien
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/* Alias pour struct dog */
typedef struct dog dog_t;

/* Prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
```

---

### 1-init_dog.c

```c
#include "dog.h"

void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d == NULL)
        return;

    d->name = name;
    d->age = age;
    d->owner = owner;
}
```

**Note** : Cette fonction **n'alloue pas** de mémoire. Elle initialise une structure existante avec des pointeurs vers des chaînes existantes.

**Usage** :
```c
struct dog buddy;
init_dog(&buddy, "Buddy", 3.5, "John");
```

---

### 2-print_dog.c

```c
#include <stdio.h>
#include "dog.h"

void print_dog(struct dog *d)
{
    if (d == NULL)
        return;

    printf("Name: %s\n", d->name ? d->name : "(nil)");
    printf("Age: %f\n", d->age);
    printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
```

**Gestion des NULL** : Affiche `(nil)` si name ou owner est NULL.

---

### 4-new_dog.c

```c
#include <stdlib.h>
#include "dog.h"

dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;
    char *n, *o;
    int i;

    /* Allouer la structure */
    d = malloc(sizeof(dog_t));
    if (d == NULL)
        return (NULL);

    /* Copier le nom */
    for (i = 0; name[i]; i++)
        ;
    n = malloc(i + 1);
    if (n == NULL)
    {
        free(d);
        return (NULL);
    }
    for (i = 0; name[i]; i++)
        n[i] = name[i];
    n[i] = '\0';

    /* Copier le owner */
    for (i = 0; owner[i]; i++)
        ;
    o = malloc(i + 1);
    if (o == NULL)
    {
        free(n);
        free(d);
        return (NULL);
    }
    for (i = 0; owner[i]; i++)
        o[i] = owner[i];
    o[i] = '\0';

    /* Initialiser la structure */
    d->name = n;
    d->age = age;
    d->owner = o;

    return (d);
}
```

**Points importants** :
1. Alloue la structure elle-même
2. **Copie** les chaînes (ne garde pas juste les pointeurs)
3. En cas d'échec, libère ce qui a déjà été alloué
4. Retourne un pointeur vers la nouvelle structure

**Visualisation** :
```
new_dog("Max", 2.5, "Alice")

Heap:
┌─────────────────────────────┐
│  dog_t structure            │
│  ┌─────────────────────┐   │
│  │ name ──────────────────► "Max\0"
│  │ age = 2.5            │   │
│  │ owner ─────────────────► "Alice\0"
│  └─────────────────────┘   │
└─────────────────────────────┘

Toutes les chaînes sont des COPIES indépendantes
```

---

### 5-free_dog.c

```c
#include <stdlib.h>
#include "dog.h"

void free_dog(dog_t *d)
{
    if (d == NULL)
        return;

    free(d->name);   /* Libère la copie du nom */
    free(d->owner);  /* Libère la copie du owner */
    free(d);         /* Libère la structure */
}
```

**Ordre de libération** :
1. D'abord les membres alloués (name, owner)
2. Ensuite la structure elle-même

---

## 💾 Allocation dynamique de structures

### Pattern complet

```c
/* Création */
dog_t *my_dog = new_dog("Rex", 5.0, "Bob");
if (my_dog == NULL)
{
    /* Gestion d'erreur */
    return (1);
}

/* Utilisation */
print_dog(my_dog);
my_dog->age = 6.0;  /* Modification */

/* Libération */
free_dog(my_dog);
my_dog = NULL;
```

### ⚠️ Erreur courante : shallow copy

```c
/* MAUVAIS : shallow copy */
dog_t *bad_new_dog(char *name, float age, char *owner)
{
    dog_t *d = malloc(sizeof(dog_t));
    d->name = name;    /* Juste une copie du POINTEUR ! */
    d->owner = owner;  /* Si la chaîne originale change, le chien aussi */
    d->age = age;
    return (d);
}

/* BON : deep copy */
/* Comme dans 4-new_dog.c - on copie les DONNÉES */
```

---

## 📊 Taille des structures

```c
struct example
{
    char c;      /* 1 byte */
    int n;       /* 4 bytes */
    char *ptr;   /* 8 bytes (64-bit) */
};

printf("Size: %zu\n", sizeof(struct example));
/* Peut être > 13 à cause du padding (alignement mémoire) */
```

**Padding et alignement** :
```
Sans padding (théorique):
┌───┬───────────┬─────────────────┐
│ c │     n     │       ptr       │
│ 1 │     4     │        8        │
└───┴───────────┴─────────────────┘
= 13 bytes

Avec padding (réel sur 64-bit):
┌───┬───────┬───────────┬─────────────────┐
│ c │padding│     n     │       ptr       │
│ 1 │   3   │     4     │        8        │
└───┴───────┴───────────┴─────────────────┘
= 16 bytes
```

---

## 🔧 Compilation et exécution

```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-init_dog.c -o init_dog
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-main.c 4-new_dog.c -o new_dog
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 5-main.c 4-new_dog.c 5-free_dog.c -o free_dog

# Exécuter
./init_dog
./new_dog
./free_dog

# Vérifier les fuites mémoire
valgrind --leak-check=full ./free_dog
```

---

## 📚 Ressources

- [Structures in C - GeeksforGeeks](https://www.geeksforgeeks.org/structures-c/)
- [typedef - cppreference](https://en.cppreference.com/w/c/language/typedef)
- [Structure Padding - GeeksforGeeks](https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Les structures sont les briques de base de l'abstraction en C. »</i>
</p>
