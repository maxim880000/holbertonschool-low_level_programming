# 🔢 More Functions & Nested Loops - Exercices avancés

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Débutant/Intermédiaire-yellow?style=for-the-badge" alt="Level"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Concepts clés](#-concepts-clés)
4. [Fichiers du projet](#-fichiers-du-projet)
5. [Détail des fichiers](#-détail-des-fichiers)
6. [L'algorithme FizzBuzz](#-lalgorithme-fizzbuzz)
7. [Patterns géométriques](#-patterns-géométriques)
8. [Compilation et exécution](#-compilation-et-exécution)
9. [Ressources](#-ressources)

---

## 📝 Description

Ce projet prolonge l'apprentissage des fonctions et des boucles imbriquées avec des exercices plus complexes. Vous implémenterez des fonctions de validation (comme `isupper`, `isdigit`), des patterns géométriques (lignes, carrés, triangles, diagonales) et le célèbre algorithme **FizzBuzz**.

Ces exercices renforcent la logique algorithmique et préparent aux entretiens techniques où FizzBuzz est un classique.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Implémenter des fonctions de **validation de caractères**
- ✅ Créer des **patterns géométriques** avec des boucles imbriquées
- ✅ Comprendre et implémenter l'algorithme **FizzBuzz**
- ✅ Maîtriser les **boucles imbriquées** complexes
- ✅ Gérer les **cas limites** (tailles nulles, nombres négatifs)
- ✅ Optimiser l'affichage avec `_putchar`

---

## 💡 Concepts clés

### Fonctions de validation

Ces fonctions vérifient si un caractère appartient à une catégorie :

```c
int _isupper(int c);   /* Retourne 1 si majuscule, 0 sinon */
int _isdigit(int c);   /* Retourne 1 si chiffre, 0 sinon */
```

### Boucles imbriquées pour patterns

Pour dessiner des formes, on utilise :
- **Boucle externe** : parcourt les **lignes**
- **Boucle(s) interne(s)** : parcourt les **colonnes** (espaces, caractères)

```c
for (ligne = 0; ligne < hauteur; ligne++)
{
    for (colonne = 0; colonne < largeur; colonne++)
    {
        /* Afficher le caractère */
    }
    /* Nouvelle ligne */
}
```

### L'opérateur modulo (`%`)

Essentiel pour FizzBuzz :
- `n % 3 == 0` → n est divisible par 3
- `n % 5 == 0` → n est divisible par 5
- `n % 15 == 0` → n est divisible par 3 ET par 5

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-isupper.c` | Vérifie si c'est une majuscule | `int _isupper(int c)` |
| `1-isdigit.c` | Vérifie si c'est un chiffre | `int _isdigit(int c)` |
| `2-mul.c` | Multiplie deux entiers | `int mul(int a, int b)` |
| `3-print_numbers.c` | Affiche 0-9 | `void print_numbers(void)` |
| `4-print_most_numbers.c` | Affiche 0-9 sauf 2 et 4 | `void print_most_numbers(void)` |
| `5-more_numbers.c` | Affiche 0-14 dix fois | `void more_numbers(void)` |
| `6-print_line.c` | Dessine une ligne horizontale | `void print_line(int n)` |
| `7-print_diagonal.c` | Dessine une diagonale | `void print_diagonal(int n)` |
| `8-print_square.c` | Dessine un carré | `void print_square(int size)` |
| `9-fizz_buzz.c` | Algorithme FizzBuzz | Programme complet |
| `10-print_triangle.c` | Dessine un triangle | `void print_triangle(int size)` |

---

## 📄 Détail des fichiers

### 0-isupper.c

```c
#include "main.h"

int _isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}
```

**Explication** :
- Les majuscules vont de 'A' (65) à 'Z' (90) en ASCII
- Retourne `1` (vrai) si c est dans cette plage

---

### 1-isdigit.c

```c
#include "main.h"

int _isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
```

**Explication** :
- Les chiffres vont de '0' (48) à '9' (57) en ASCII
- Similaire à `isdigit()` de `<ctype.h>`

---

### 6-print_line.c

```c
#include "main.h"

void print_line(int n)
{
    int i;

    if (n <= 0)
    {
        _putchar('\n');
        return;
    }

    for (i = 0; i < n; i++)
        _putchar('_');

    _putchar('\n');
}
```

**Sortie pour `print_line(5)` :**
```
_____
```

---

### 7-print_diagonal.c

```c
#include "main.h"

void print_diagonal(int n)
{
    int ligne, espace;

    if (n <= 0)
    {
        _putchar('\n');
        return;
    }

    for (ligne = 0; ligne < n; ligne++)
    {
        for (espace = 0; espace < ligne; espace++)
            _putchar(' ');
        _putchar('\\');
        _putchar('\n');
    }
}
```

**Sortie pour `print_diagonal(5)` :**
```
\
 \
  \
   \
    \
```

---

### 8-print_square.c

```c
#include "main.h"

void print_square(int size)
{
    int x, y;

    if (size <= 0)
    {
        _putchar('\n');
        return;
    }

    for (x = 0; x < size; x++)          /* Lignes */
    {
        for (y = 0; y < size; y++)      /* Colonnes */
            _putchar('#');
        _putchar('\n');
    }
}
```

**Sortie pour `print_square(4)` :**
```
####
####
####
####
```

---

### 10-print_triangle.c

```c
#include "main.h"

void print_triangle(int size)
{
    int x, y, space;

    if (size <= 0)
    {
        _putchar('\n');
        return;
    }

    for (x = 1; x <= size; x++)
    {
        /* Espaces avant les # */
        for (space = size - x; space > 0; space--)
            _putchar(' ');

        /* Les # de la ligne */
        for (y = 0; y < x; y++)
            _putchar('#');

        _putchar('\n');
    }
}
```

**Sortie pour `print_triangle(5)` :**
```
    #
   ##
  ###
 ####
#####
```

**Visualisation de la logique :**
```
Ligne 1: 4 espaces + 1 #
Ligne 2: 3 espaces + 2 #
Ligne 3: 2 espaces + 3 #
Ligne 4: 1 espace  + 4 #
Ligne 5: 0 espace  + 5 #
```

---

## 🎮 L'algorithme FizzBuzz

### 9-fizz_buzz.c

```c
#include <stdio.h>

int main(void)
{
    int i;

    for (i = 1; i <= 100; i++)
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

### Règles de FizzBuzz

| Condition | Affichage |
|-----------|-----------|
| Divisible par 3 uniquement | `Fizz` |
| Divisible par 5 uniquement | `Buzz` |
| Divisible par 3 ET 5 | `FizzBuzz` |
| Sinon | Le nombre |

### Pourquoi tester `% 15` d'abord ?

```c
/* MAUVAIS ordre */
if (i % 3 == 0)       /* 15 % 3 == 0 → affiche Fizz (FAUX!) */
    printf("Fizz");
else if (i % 5 == 0)
    printf("Buzz");
else if (i % 15 == 0) /* Ne sera JAMAIS atteint ! */
    printf("FizzBuzz");

/* BON ordre */
if (i % 15 == 0)      /* OU: i % 3 == 0 && i % 5 == 0 */
    printf("FizzBuzz");
else if (i % 3 == 0)
    printf("Fizz");
else if (i % 5 == 0)
    printf("Buzz");
```

### Sortie FizzBuzz (extrait)

```
1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 ...
```

---

## 📐 Patterns géométriques

### Tableau récapitulatif

| Pattern | Boucles | Complexité |
|---------|---------|------------|
| Ligne | 1 boucle | O(n) |
| Diagonale | 2 boucles | O(n²) |
| Carré | 2 boucles | O(n²) |
| Triangle | 3 boucles | O(n²) |

### Visualisation des boucles imbriquées

```
┌─────────────────────────────────────────────┐
│  Boucle externe (lignes)                    │
│  ┌─────────────────────────────────────┐    │
│  │  Boucle interne 1 (espaces)         │    │
│  └─────────────────────────────────────┘    │
│  ┌─────────────────────────────────────┐    │
│  │  Boucle interne 2 (caractères)      │    │
│  └─────────────────────────────────────┘    │
│  → Nouvelle ligne                           │
└─────────────────────────────────────────────┘
```

---

## 🔧 Compilation et exécution

```bash
# Compiler FizzBuzz
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 9-fizz_buzz.c -o fizzbuzz
./fizzbuzz

# Compiler le carré
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 8-main.c 8-print_square.c -o square
./square

# Compiler le triangle
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 10-main.c 10-print_triangle.c -o triangle
./triangle
```

---

## 🧪 Tests

### Cas limites à tester

```c
print_line(0);      /* Doit afficher une ligne vide */
print_line(-5);     /* Doit afficher une ligne vide */
print_square(0);    /* Doit afficher une ligne vide */
print_triangle(1);  /* Doit afficher un seul # */
```

---

## 💡 Conseils

1. **Dessinez d'abord sur papier** : avant de coder, visualisez le pattern
2. **Identifiez les relations** : ligne `i` → combien d'espaces ? combien de `#` ?
3. **Gérez les cas limites** : tailles nulles ou négatives
4. **Testez progressivement** : commencez par des petites tailles

---

## 📚 Ressources

- [FizzBuzz - Wikipedia](https://en.wikipedia.org/wiki/Fizz_buzz)
- [Nested Loops Patterns](https://www.programiz.com/c-programming/c-for-loop)
- [ASCII Art Patterns](https://www.geeksforgeeks.org/c-program-print-pyramid-pattern/)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« FizzBuzz : le test qui sépare les développeurs des imposteurs. »</i>
</p>
