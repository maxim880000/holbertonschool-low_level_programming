# 🔗 Singly Linked Lists - Listes chaînées simples

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Data_Structure-Linked_List-green?style=for-the-badge" alt="Linked List"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Concept : Listes chaînées](#-concept--listes-chaînées)
4. [Structure de données](#-structure-de-données)
5. [Opérations fondamentales](#-opérations-fondamentales)
6. [Fichiers du projet](#-fichiers-du-projet)
7. [Détail des fichiers](#-détail-des-fichiers)
8. [Complexité algorithmique](#-complexité-algorithmique)
9. [Compilation et exécution](#-compilation-et-exécution)
10. [Ressources](#-ressources)

---

## 📝 Description

Ce projet introduit les **listes chaînées simples** (singly linked lists), une structure de données fondamentale en informatique. Contrairement aux tableaux, les listes chaînées permettent une **insertion et suppression dynamiques** sans réallocation.

Les listes chaînées sont la base de nombreuses structures plus complexes (piles, files, graphes).

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre la différence entre **tableaux** et **listes chaînées**
- ✅ Définir une structure de **nœud** (node)
- ✅ Créer et manipuler des listes chaînées
- ✅ Ajouter des nœuds au **début** et à la **fin**
- ✅ Parcourir une liste chaînée
- ✅ Libérer correctement la mémoire d'une liste
- ✅ Utiliser le double pointeur `**head`

---

## 🧠 Concept : Listes chaînées

### Tableaux vs Listes chaînées

| Caractéristique | Tableau | Liste chaînée |
|-----------------|---------|---------------|
| Taille | Fixe | Dynamique |
| Accès par index | O(1) | O(n) |
| Insertion au début | O(n) | O(1) |
| Insertion à la fin | O(1) si espace | O(n) |
| Mémoire | Contiguë | Dispersée |
| Overhead | Aucun | Pointeur par nœud |

### Visualisation d'une liste chaînée

```
head
 │
 ▼
┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│ str: "abc"  │    │ str: "def"  │    │ str: "ghi"  │
│ len: 3      │    │ len: 3      │    │ len: 3      │
│ next: ──────────►│ next: ──────────►│ next: NULL  │
└─────────────┘    └─────────────┘    └─────────────┘
   Node 0             Node 1             Node 2
```

### Pourquoi un double pointeur ?

```c
/* Pour modifier head depuis la fonction, on a besoin d'un pointeur vers head */
void add_node(list_t **head, const char *str);

/* Si on utilisait un simple pointeur: */
void bad_add(list_t *head, const char *str)
{
    head = new_node;  /* Modifie la COPIE locale, pas l'original ! */
}

/* Avec double pointeur: */
void good_add(list_t **head, const char *str)
{
    *head = new_node;  /* Modifie le vrai head via déréférencement */
}
```

**Visualisation** :
```
Avant add_node:
main:     head = 0x1000 ─────► [Node A] ─► [Node B] ─► NULL
                  ▲
                  │
add_node: *head ──┘   (accès au vrai head)

Après add_node:
main:     head = 0x2000 ─────► [New Node] ─► [Node A] ─► [Node B] ─► NULL
                  ▲
                  │
          *head ──┘   (modification effective)
```

---

## 🏗️ Structure de données

### lists.h

```c
#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - singly linked list
 * @str: string (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;              /* Copie de la chaîne */
    unsigned int len;       /* Longueur de str */
    struct list_s *next;    /* Pointeur vers le nœud suivant */
} list_t;

/* Prototypes */
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
```

### Représentation mémoire d'un nœud

```
list_t node (24 bytes sur 64-bit):
┌──────────────────────────────────┐
│  str (char *)     │  8 bytes    │ ──► "Hello\0" (heap)
├───────────────────┼─────────────┤
│  len (unsigned)   │  4 bytes    │ = 5
├───────────────────┼─────────────┤
│  padding          │  4 bytes    │ (alignement)
├───────────────────┼─────────────┤
│  next (list_t *)  │  8 bytes    │ ──► next node (ou NULL)
└──────────────────────────────────┘
```

---

## ⚙️ Opérations fondamentales

### 1. Parcourir une liste

```c
list_t *current = head;
while (current != NULL)
{
    printf("%s\n", current->str);
    current = current->next;  /* Avancer au nœud suivant */
}
```

### 2. Ajouter au début (prepend)

```c
list_t *new_node = malloc(sizeof(list_t));
new_node->str = strdup(str);
new_node->next = *head;   /* Nouveau pointe vers ancien premier */
*head = new_node;         /* Nouveau devient premier */
```

```
Avant: head ──► [A] ──► [B] ──► NULL

Étape 1: new_node->next = *head
         new_node ──► [A] ──► [B] ──► NULL
         head ────────┘

Étape 2: *head = new_node
         head ──► [new] ──► [A] ──► [B] ──► NULL
```

### 3. Ajouter à la fin (append)

```c
list_t *new_node = malloc(sizeof(list_t));
new_node->str = strdup(str);
new_node->next = NULL;

if (*head == NULL)
    *head = new_node;  /* Liste vide */
else
{
    list_t *last = *head;
    while (last->next != NULL)  /* Trouver le dernier */
        last = last->next;
    last->next = new_node;
}
```

### 4. Libérer une liste

```c
while (head != NULL)
{
    list_t *temp = head->next;  /* Sauvegarder AVANT de free */
    free(head->str);            /* Libérer la string */
    free(head);                 /* Libérer le nœud */
    head = temp;                /* Avancer */
}
```

⚠️ **Important** : Toujours sauvegarder `next` AVANT de libérer le nœud !

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `lists.h` | Structure et prototypes | - |
| `0-print_list.c` | Affiche tous les éléments | `size_t print_list(const list_t *h)` |
| `1-list_len.c` | Compte les nœuds | `size_t list_len(const list_t *h)` |
| `2-add_node.c` | Ajoute au début | `list_t *add_node(list_t **head, const char *str)` |
| `3-add_node_end.c` | Ajoute à la fin | `list_t *add_node_end(list_t **head, const char *str)` |
| `4-free_list.c` | Libère toute la liste | `void free_list(list_t *head)` |

---

## 📄 Détail des fichiers

### 0-print_list.c

```c
#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the first node
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", h->len, h->str);
        count++;
        h = h->next;
    }
    return (count);
}
```

**Exemple de sortie** :
```
[5] Hello
[6] World!
[3] Bye
```

---

### 1-list_len.c

```c
#include "lists.h"

/**
 * list_len - returns the number of elements in a list
 * @h: pointer to the first node
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        count++;
        h = h->next;
    }
    return (count);
}
```

---

### 2-add_node.c

```c
#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list
 * @head: double pointer to the first node
 * @str: string to add (will be duplicated)
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
    unsigned int len = 0;

    /* Allouer le nœud */
    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    /* Dupliquer la chaîne */
    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    /* Calculer la longueur */
    while (str[len])
        len++;
    new_node->len = len;

    /* Insérer au début */
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}
```

**Visualisation** :
```
add_node(&head, "New")

Avant:
head ──► [Hello] ──► [World] ──► NULL

Après:
head ──► [New] ──► [Hello] ──► [World] ──► NULL
```

---

### 3-add_node_end.c

```c
#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list
 * @head: double pointer to the first node
 * @str: string to add
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *last;
    unsigned int len = 0;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    while (str[len])
        len++;
    new_node->len = len;
    new_node->next = NULL;

    /* Si liste vide */
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    /* Trouver le dernier nœud */
    last = *head;
    while (last->next != NULL)
        last = last->next;
    
    last->next = new_node;
    return (new_node);
}
```

**Visualisation** :
```
add_node_end(&head, "End")

Avant:
head ──► [Hello] ──► [World] ──► NULL

Parcours: [Hello] → [World] (last->next == NULL)

Après:
head ──► [Hello] ──► [World] ──► [End] ──► NULL
```

---

### 4-free_list.c

```c
#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees a list_t list
 * @head: pointer to the first node
 */
void free_list(list_t *head)
{
    list_t *temp;

    while (head != NULL)
    {
        temp = head->next;   /* Sauvegarder le suivant */
        free(head->str);     /* Libérer la chaîne */
        free(head);          /* Libérer le nœud */
        head = temp;         /* Avancer */
    }
}
```

**Visualisation** :
```
free_list(head)

Itération 1:
temp = head->next ──► [World]
free(head->str) → libère "Hello"
free(head) → libère nœud
head = temp

Itération 2:
temp = head->next ──► NULL
free(head->str) → libère "World"
free(head) → libère nœud
head = temp (NULL)

Boucle terminée: head == NULL
```

---

## 📊 Complexité algorithmique

| Opération | Complexité | Explication |
|-----------|------------|-------------|
| `print_list` | O(n) | Parcourt toute la liste |
| `list_len` | O(n) | Parcourt toute la liste |
| `add_node` | O(1) | Insertion directe au début |
| `add_node_end` | O(n) | Doit trouver le dernier |
| `free_list` | O(n) | Libère chaque nœud |

**Optimisation possible** : Garder un pointeur `tail` pour `add_node_end` en O(1).

---

## 🔧 Compilation et exécution

```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-print_list.c -o print
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-list_len.c -o len
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-add_node.c 0-print_list.c -o add
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-add_node_end.c 0-print_list.c -o add_end
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-main.c 4-free_list.c 2-add_node.c -o free

# Exécuter
./print
./len
./add
./add_end

# Vérifier les fuites mémoire
valgrind --leak-check=full ./free
```

---

## ⚠️ Erreurs courantes

### 1. Oublier de vérifier malloc

```c
/* MAUVAIS */
list_t *node = malloc(sizeof(list_t));
node->str = strdup(str);  /* Si malloc a échoué → crash ! */

/* BON */
list_t *node = malloc(sizeof(list_t));
if (node == NULL)
    return (NULL);
```

### 2. Perdre des nœuds lors de la libération

```c
/* MAUVAIS */
while (head != NULL)
{
    free(head);  /* head->next perdu ! */
    head = head->next;  /* Undefined behavior */
}

/* BON */
while (head != NULL)
{
    list_t *temp = head->next;  /* Sauvegarder AVANT */
    free(head->str);
    free(head);
    head = temp;
}
```

### 3. Ne pas dupliquer la chaîne

```c
/* MAUVAIS */
node->str = str;  /* Si str est sur la stack, danger ! */

/* BON */
node->str = strdup(str);  /* Copie indépendante */
```

---

## 📚 Ressources

- [Linked Lists - GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Visualgo - Linked List](https://visualgo.net/en/list)
- [Why double pointer for linked list?](https://stackoverflow.com/questions/7271647)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Les listes chaînées : simples en théorie, subtiles en pratique. »</i>
</p>
