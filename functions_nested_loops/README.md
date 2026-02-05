# 🔄 Functions & Nested Loops - Fonctions et boucles imbriquées

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Débutant-green?style=for-the-badge" alt="Débutant"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Concepts clés](#-concepts-clés)
4. [Le fichier header](#-le-fichier-header)
5. [Fichiers du projet](#-fichiers-du-projet)
6. [Détail des fichiers](#-détail-des-fichiers)
7. [Compilation et exécution](#-compilation-et-exécution)
8. [Ressources](#-ressources)

---

## 📝 Description

Ce projet approfondit les **fonctions** en C et introduit les **boucles imbriquées**. Vous apprendrez à créer vos propres fonctions, à utiliser des fichiers headers (`.h`) pour déclarer des prototypes, et à utiliser la fonction `_putchar` pour l'affichage caractère par caractère.

Les fonctions sont des blocs de code réutilisables qui permettent de **modulariser** votre programme, le rendant plus lisible, maintenable et testable.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre ce qu'est une **fonction** et comment la définir
- ✅ Distinguer **déclaration** (prototype) et **définition** d'une fonction
- ✅ Utiliser un **fichier header** (`.h`) correctement
- ✅ Comprendre la **portée des variables** (scope)
- ✅ Utiliser des **boucles imbriquées**
- ✅ Comprendre les **prototypes de fonctions**
- ✅ Utiliser les **include guards** (`#ifndef`, `#define`, `#endif`)

---

## 💡 Concepts clés

### Anatomie d'une fonction

```c
type_retour nom_fonction(paramètres)
{
    /* Corps de la fonction */
    return valeur;  /* Si type_retour n'est pas void */
}
```

**Exemple :**
```c
int add(int a, int b)
{
    return (a + b);
}
```

### Prototype vs Définition

| Aspect | Prototype | Définition |
|--------|-----------|------------|
| Où ? | Fichier `.h` | Fichier `.c` |
| Quoi ? | Signature uniquement | Code complet |
| Exemple | `int add(int, int);` | `int add(int a, int b) { return a + b; }` |

### Fichiers headers (`.h`)

Un fichier header contient :
- Les prototypes de fonctions
- Les définitions de macros
- Les structures et typedefs

```c
#ifndef MAIN_H        /* Include guard - début */
#define MAIN_H

int _putchar(char c);
void print_alphabet(void);
/* ... autres prototypes ... */

#endif                /* Include guard - fin */
```

### Boucles imbriquées

```c
for (int i = 0; i < 3; i++)         /* Boucle externe */
{
    for (int j = 0; j < 3; j++)     /* Boucle interne */
    {
        printf("(%d,%d) ", i, j);
    }
    printf("\n");
}
```

**Sortie :**
```
(0,0) (0,1) (0,2)
(1,0) (1,1) (1,2)
(2,0) (2,1) (2,2)
```

---

## 📑 Le fichier header

### main.h

```c
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void print_alphabet(void);
void print_alphabet_x10(void);
int _islower(int c);
int _isalpha(int c);
int print_sign(int n);
int _abs(int);
int print_last_digit(int n);
void jack_bauer(void);
void times_table(void);
int add(int, int);
void print_to_98(int n);

#endif
```

**Pourquoi les include guards ?**
- Empêchent l'inclusion multiple d'un fichier
- Évitent les erreurs de redéfinition

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-putchar.c` | Affiche `_putchar` | - |
| `1-alphabet.c` | Affiche l'alphabet en minuscules | `void print_alphabet(void)` |
| `2-print_alphabet_x10.c` | Affiche l'alphabet 10 fois | `void print_alphabet_x10(void)` |
| `3-islower.c` | Vérifie si un caractère est minuscule | `int _islower(int c)` |
| `4-isalpha.c` | Vérifie si un caractère est alphabétique | `int _isalpha(int c)` |
| `5-sign.c` | Affiche le signe d'un nombre | `int print_sign(int n)` |
| `6-abs.c` | Retourne la valeur absolue | `int _abs(int)` |
| `7-print_last_digit.c` | Affiche le dernier chiffre | `int print_last_digit(int n)` |
| `8-24_hours.c` | Affiche les minutes d'une journée | `void jack_bauer(void)` |
| `9-times_table.c` | Affiche la table de multiplication | `void times_table(void)` |
| `10-add.c` | Additionne deux entiers | `int add(int, int)` |
| `11-print_to_98.c` | Affiche les nombres jusqu'à 98 | `void print_to_98(int n)` |

---

## 📄 Détail des fichiers

### 1-alphabet.c

```c
#include "main.h"

void print_alphabet(void)
{
    char c = 'a';

    while (c <= 'z')
    {
        _putchar(c);
        c++;
    }
    _putchar('\n');
}
```

**Explication** :
- Fonction sans paramètres ni valeur de retour (`void`)
- Utilise `_putchar` au lieu de `printf` ou `putchar`
- Parcourt les lettres de 'a' à 'z' grâce à l'ASCII

---

### 5-sign.c

```c
#include "main.h"

int print_sign(int n)
{
    if (n > 0)
    {
        _putchar('+');
        return (1);
    }
    else if (n == 0)
    {
        _putchar('0');
        return (0);
    }
    else
    {
        _putchar('-');
        return (-1);
    }
}
```

**Explication** :
- Affiche `+`, `0` ou `-` selon le signe
- Retourne `1`, `0` ou `-1` respectivement
- Combine affichage et valeur de retour

---

### 9-times_table.c

```c
#include "main.h"

void times_table(void)
{
    int i, j, product;

    for (i = 0; i <= 9; i++)         /* Lignes */
    {
        for (j = 0; j <= 9; j++)     /* Colonnes */
        {
            product = i * j;

            if (j == 0)
                _putchar('0');
            else
            {
                _putchar(',');
                _putchar(' ');

                if (product < 10)
                    _putchar(' ');
                else
                    _putchar(product / 10 + '0');

                _putchar(product % 10 + '0');
            }
        }
        _putchar('\n');
    }
}
```

**Explication** :
- Boucle externe : lignes (multiplicande)
- Boucle interne : colonnes (multiplicateur)
- Formatage spécial pour aligner les nombres
- `product / 10` : chiffre des dizaines
- `product % 10` : chiffre des unités

**Sortie :**
```
0,  0,  0,  0,  0,  0,  0,  0,  0,  0
0,  1,  2,  3,  4,  5,  6,  7,  8,  9
0,  2,  4,  6,  8, 10, 12, 14, 16, 18
...
```

---

### 11-print_to_98.c

```c
#include <stdio.h>
#include "main.h"

void print_to_98(int n)
{
    if (n <= 98)
    {
        for (; n <= 98; n++)
        {
            if (n == 98)
                printf("%d\n", n);
            else
                printf("%d, ", n);
        }
    }
    else
    {
        for (; n >= 98; n--)
        {
            if (n == 98)
                printf("%d\n", n);
            else
                printf("%d, ", n);
        }
    }
}
```

**Explication** :
- Si `n <= 98` : compte vers le haut
- Si `n > 98` : compte vers le bas
- Gère les cas où n est négatif, nul, ou supérieur à 98

---

## 🔧 Compilation et exécution

```bash
# Compiler avec un fichier main de test
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 1-main.c 1-alphabet.c -o alphabet
./alphabet

# Compiler la table de multiplication
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 9-main.c 9-times_table.c -o times
./times
```

---

## 📊 Visualisation - Boucles imbriquées

```
Table de multiplication (extrait):
           j=0  j=1  j=2  j=3
        ┌─────┬─────┬─────┬─────┐
   i=0  │  0  │  0  │  0  │  0  │
        ├─────┼─────┼─────┼─────┤
   i=1  │  0  │  1  │  2  │  3  │
        ├─────┼─────┼─────┼─────┤
   i=2  │  0  │  2  │  4  │  6  │
        ├─────┼─────┼─────┼─────┤
   i=3  │  0  │  3  │  6  │  9  │
        └─────┴─────┴─────┴─────┘
         
         product = i * j
```

---

## 💡 Bonnes pratiques

1. **Une fonction = une tâche** : chaque fonction doit faire une seule chose
2. **Noms explicites** : `print_alphabet` est plus clair que `pa`
3. **Prototypes dans le header** : facilite la réutilisation
4. **Include guards** : toujours les utiliser dans les `.h`
5. **Documentation** : commenter le but de chaque fonction

---

## 📚 Ressources

- [Functions in C - GeeksforGeeks](https://www.geeksforgeeks.org/functions-in-c/)
- [Header Files - cppreference](https://en.cppreference.com/w/c/preprocessor/include)
- [Nested Loops - Programiz](https://www.programiz.com/c-programming/c-for-loop)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Divisez chaque difficulté en autant de parcelles qu'il se peut pour mieux les résoudre. »</i><br>
  — René Descartes
</p>
