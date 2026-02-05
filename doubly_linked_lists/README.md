# 🔗🔗 Doubly Linked Lists - Listes doublement chaînées

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Data_Structure-Doubly_Linked_List-green?style=for-the-badge" alt="Doubly Linked List"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Simple vs Double](#-simple-vs-double)
4. [Structure de données](#-structure-de-données)
5. [Opérations fondamentales](#-opérations-fondamentales)
6. [Fichiers du projet](#-fichiers-du-projet)
7. [Détail des fichiers](#-détail-des-fichiers)
8. [Insertion et suppression](#-insertion-et-suppression)
9. [Compilation et exécution](#-compilation-et-exécution)
10. [Ressources](#-ressources)

---

## 📝 Description

Ce projet approfondit les listes chaînées avec les **listes doublement chaînées** (doubly linked lists). Chaque nœud possède maintenant **deux pointeurs** : un vers le nœud suivant (`next`) et un vers le nœud précédent (`prev`).

Cette structure permet un **parcours bidirectionnel** et simplifie certaines opérations comme la suppression.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre la différence entre liste **simple** et **double**
- ✅ Gérer les pointeurs **prev** et **next**
- ✅ Insérer un nœud à **n'importe quelle position**
- ✅ Supprimer un nœud à **n'importe quelle position**
- ✅ Accéder à un nœud par son **index**
- ✅ Calculer la **somme** des éléments
- ✅ Gérer les cas limites (début, fin, milieu)

---

## ⚖️ Simple vs Double

### Comparaison visuelle

**Liste simplement chaînée** :
```
head ──► [A] ──► [B] ──► [C] ──► NULL
         │       │       │
         └───────┴───────┴──── Sens unique →
```

**Liste doublement chaînée** :
```
NULL ◄── [A] ◄──► [B] ◄──► [C] ──► NULL
          │        │        │
          └────────┴────────┴──── Bidirectionnel ↔
```

### Avantages/Inconvénients

| Aspect | Simple | Double |
|--------|--------|--------|
| Parcours avant | ✅ O(1) | ✅ O(1) |
| Parcours arrière | ❌ O(n) | ✅ O(1) |
| Suppression (avec pointeur) | O(n) | ✅ O(1) |
| Mémoire par nœud | 1 pointeur | 2 pointeurs |
| Complexité code | Plus simple | Plus complexe |

---

## 🏗️ Structure de données

### lists.h

```c
#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer value
 * @prev: points to the previous node
 * @next: points to the next node
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/* Prototypes */
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif
```

### Représentation mémoire d'un nœud

```
dlistint_t node (24 bytes sur 64-bit):
┌──────────────────────────────────┐
│  n (int)          │  4 bytes    │ = valeur entière
├───────────────────┼─────────────┤
│  padding          │  4 bytes    │ (alignement)
├───────────────────┼─────────────┤
│  prev (dlistint_t *)│ 8 bytes   │ ──► nœud précédent
├───────────────────┼─────────────┤
│  next (dlistint_t *)│ 8 bytes   │ ──► nœud suivant
└──────────────────────────────────┘
```

---

## ⚙️ Opérations fondamentales

### Parcours avant et arrière

```c
/* Parcours AVANT (comme liste simple) */
dlistint_t *current = head;
while (current != NULL)
{
    printf("%d\n", current->n);
    current = current->next;
}

/* Parcours ARRIÈRE (avantage de la liste double) */
/* D'abord, aller à la fin */
dlistint_t *tail = head;
while (tail->next != NULL)
    tail = tail->next;

/* Puis remonter */
while (tail != NULL)
{
    printf("%d\n", tail->n);
    tail = tail->prev;
}
```

### Insertion - Les 4 cas

```
1. Liste vide      2. Au début       3. À la fin       4. Au milieu
   head = NULL        head──►[NEW]      [A]──►[NEW]       [A]──►[NEW]──►[B]
   │                    │                 │     │           │      │      │
   └► head = NEW        └►prev=NULL      NULL◄─┘          ◄──────┘  └──────►
```

### Suppression - Les 3 cas

```
1. Supprimer la tête    2. Supprimer la queue    3. Supprimer au milieu
   [X]──►[B]──►[C]        [A]──►[B]──►[X]          [A]──►[X]──►[C]
    │                              │                      
   head = [B]                [B]->next = NULL        [A]──────────►[C]
   [B]->prev = NULL                                  [C]->prev = [A]
```

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `lists.h` | Structure et prototypes | - |
| `0-print_dlistint.c` | Affiche tous les éléments | `size_t print_dlistint(const dlistint_t *h)` |
| `1-dlistint_len.c` | Compte les nœuds | `size_t dlistint_len(const dlistint_t *h)` |
| `2-add_dnodeint.c` | Ajoute au début | `dlistint_t *add_dnodeint(dlistint_t **head, const int n)` |
| `3-add_dnodeint_end.c` | Ajoute à la fin | `dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)` |
| `4-free_dlistint.c` | Libère toute la liste | `void free_dlistint(dlistint_t *head)` |
| `5-get_dnodeint.c` | Récupère un nœud par index | `dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)` |
| `6-sum_dlistint.c` | Somme de tous les éléments | `int sum_dlistint(dlistint_t *head)` |
| `7-insert_dnodeint.c` | Insère à un index donné | `dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)` |
| `8-delete_dnodeint.c` | Supprime à un index donné | `int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)` |

---

## 📄 Détail des fichiers

### 0-print_dlistint.c

```c
#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all elements of a dlistint_t list
 * @h: pointer to the first node
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        count++;
        h = h->next;
    }
    return (count);
}
```

---

### 2-add_dnodeint.c

```c
#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - adds a new node at the beginning
 * @head: double pointer to the first node
 * @n: value to store
 *
 * Return: address of the new node, or NULL if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;      /* Nouveau premier → pas de précédent */
    new_node->next = *head;     /* Nouveau pointe vers ancien premier */

    if (*head != NULL)
        (*head)->prev = new_node; /* Ancien premier pointe vers nouveau */

    *head = new_node;           /* Nouveau devient premier */

    return (new_node);
}
```

**Visualisation** :
```
add_dnodeint(&head, 5)

Avant:
NULL ◄── head ──► [10] ◄──► [20] ──► NULL

Étapes:
1. new_node->prev = NULL
2. new_node->next = [10]
3. [10]->prev = new_node
4. head = new_node

Après:
NULL ◄── head ──► [5] ◄──► [10] ◄──► [20] ──► NULL
```

---

### 3-add_dnodeint_end.c

```c
#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a new node at the end
 * @head: double pointer to the first node
 * @n: value to store
 *
 * Return: address of the new node, or NULL if failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *last;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;  /* Dernier → pas de suivant */

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    /* Trouver le dernier nœud */
    last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;   /* Ancien dernier pointe vers nouveau */
    new_node->prev = last;   /* Nouveau pointe vers ancien dernier */

    return (new_node);
}
```

---

### 5-get_dnodeint.c

```c
#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a list
 * @head: pointer to the first node
 * @index: index of the node (starting from 0)
 *
 * Return: pointer to the node, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i = 0;

    while (head != NULL)
    {
        if (i == index)
            return (head);
        head = head->next;
        i++;
    }
    return (NULL);
}
```

---

### 6-sum_dlistint.c

```c
#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data (n) in a list
 * @head: pointer to the first node
 *
 * Return: sum of all data, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }
    return (sum);
}
```

---

## 🎯 Insertion et suppression

### 7-insert_dnodeint.c (Insertion à un index)

```c
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp = *h;
    unsigned int count;

    /* Cas spécial : insertion au début */
    if (idx == 0)
        return (add_dnodeint(h, n));

    /* Parcourir jusqu'à idx - 1 */
    for (count = 0; temp != NULL && count < idx - 1; count++)
        temp = temp->next;

    if (temp == NULL)
        return (NULL);  /* Index trop grand */

    /* Cas spécial : insertion à la fin */
    if (temp->next == NULL && count == idx - 1)
        return (add_dnodeint_end(h, n));

    /* Insertion au milieu */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = n;

    /* Connecter les pointeurs */
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;

    return (new_node);
}
```

**Visualisation de l'insertion au milieu** :
```
insert_dnodeint_at_index(&head, 2, 99)

Avant: [10] ◄──► [20] ◄──► [30] ◄──► [40]
              idx=0   idx=1   idx=2

temp pointe vers [20] (idx - 1 = 1)

Étapes:
1. new_node->next = temp->next ([30])
2. new_node->prev = temp ([20])
3. [30]->prev = new_node
4. [20]->next = new_node

Après: [10] ◄──► [20] ◄──► [99] ◄──► [30] ◄──► [40]
```

---

### 8-delete_dnodeint.c (Suppression à un index)

```c
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int count = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    /* Cas spécial : supprimer la tête */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Parcourir jusqu'à l'index */
    while (current != NULL && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return (-1);  /* Index trop grand */

    /* Reconnecter les voisins */
    current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
```

**Visualisation de la suppression au milieu** :
```
delete_dnodeint_at_index(&head, 2)

Avant: [10] ◄──► [20] ◄──► [30] ◄──► [40]
                       ↑ current (à supprimer)

Étapes:
1. [20]->next = [40]  (bypass [30])
2. [40]->prev = [20]  (bypass [30])
3. free([30])

Après: [10] ◄──► [20] ◄──► [40]
```

---

## 📊 Complexité algorithmique

| Opération | Complexité | Note |
|-----------|------------|------|
| `print_dlistint` | O(n) | Parcours complet |
| `dlistint_len` | O(n) | Parcours complet |
| `add_dnodeint` | O(1) | Insertion directe |
| `add_dnodeint_end` | O(n) | Doit trouver la fin |
| `get_dnodeint_at_index` | O(n) | Pire cas: dernier élément |
| `sum_dlistint` | O(n) | Parcours complet |
| `insert_dnodeint_at_index` | O(n) | Doit trouver la position |
| `delete_dnodeint_at_index` | O(n) | Doit trouver la position |

---

## 🔧 Compilation et exécution

```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-print_dlistint.c -o print
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-add_dnodeint.c 0-print_dlistint.c -o add
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 7-main.c 2-add_dnodeint.c 7-insert_dnodeint.c 0-print_dlistint.c -o insert
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 8-main.c 8-delete_dnodeint.c 2-add_dnodeint.c 0-print_dlistint.c -o delete

# Exécuter
./print
./add
./insert
./delete

# Vérifier les fuites mémoire
valgrind --leak-check=full ./delete
```

---

## ⚠️ Erreurs courantes

### 1. Oublier de mettre à jour prev

```c
/* INCOMPLET */
new_node->next = temp->next;
temp->next = new_node;
/* Le nœud suivant ne sait pas que son prev a changé ! */

/* COMPLET */
new_node->next = temp->next;
new_node->prev = temp;
if (temp->next != NULL)
    temp->next->prev = new_node;  /* Important ! */
temp->next = new_node;
```

### 2. Oublier les cas limites

```c
/* Toujours vérifier */
if (*head == NULL)     /* Liste vide */
if (index == 0)        /* Premier élément */
if (current->next == NULL)  /* Dernier élément */
```

---

## 📚 Ressources

- [Doubly Linked List - GeeksforGeeks](https://www.geeksforgeeks.org/doubly-linked-list/)
- [Visualgo - Doubly Linked List](https://visualgo.net/en/list)
- [Operations on DLL](https://www.programiz.com/dsa/doubly-linked-list)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Les listes doublement chaînées : plus de pointeurs, plus de possibilités. »</i>
</p>
