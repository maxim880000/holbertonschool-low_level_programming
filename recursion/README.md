# 🔁 Recursion - La puissance de l'auto-appel

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Intermédiaire-orange?style=for-the-badge" alt="Intermédiaire"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Qu'est-ce que la récursivité ?](#-quest-ce-que-la-récursivité-)
4. [Anatomie d'une fonction récursive](#-anatomie-dune-fonction-récursive)
5. [La pile d'appels](#-la-pile-dappels)
6. [Fichiers du projet](#-fichiers-du-projet)
7. [Détail des fichiers](#-détail-des-fichiers)
8. [Compilation et exécution](#-compilation-et-exécution)
9. [Récursivité vs Itération](#-récursivité-vs-itération)
10. [Ressources](#-ressources)

---

## 📝 Description

Ce projet explore la **récursivité**, une technique de programmation où une fonction **s'appelle elle-même**. C'est un concept fondamental en informatique, utilisé dans de nombreux algorithmes (tri, recherche, parcours d'arbres) et structures de données.

La récursivité permet d'écrire des solutions élégantes et concises pour des problèmes qui se décomposent naturellement en sous-problèmes similaires.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre le concept de **récursivité**
- ✅ Identifier le **cas de base** et le **cas récursif**
- ✅ Implémenter des fonctions **récursives**
- ✅ Comprendre le fonctionnement de la **pile d'appels**
- ✅ Convertir des algorithmes itératifs en récursifs
- ✅ Éviter les **récursions infinies**

---

## 🔄 Qu'est-ce que la récursivité ?

La récursivité est une technique où une fonction **s'appelle elle-même** pour résoudre un problème en le décomposant en sous-problèmes plus petits.

### Analogie : Les poupées russes

```
┌─────────────────────────────────────┐
│  ┌─────────────────────────────┐   │
│  │  ┌─────────────────────┐    │   │
│  │  │  ┌───────────────┐  │    │   │
│  │  │  │  ┌─────────┐  │  │    │   │
│  │  │  │  │  ┌───┐  │  │  │    │   │
│  │  │  │  │  │ ● │  │  │  │    │   │  ← Cas de base
│  │  │  │  │  └───┘  │  │  │    │   │
│  │  │  │  └─────────┘  │  │    │   │
│  │  │  └───────────────┘  │    │   │
│  │  └─────────────────────┘    │   │
│  └─────────────────────────────┘   │
└─────────────────────────────────────┘
  Chaque poupée contient une plus petite
  jusqu'à la dernière (cas de base)
```

---

## 🏗️ Anatomie d'une fonction récursive

Toute fonction récursive a **deux composants essentiels** :

### 1. Le cas de base (Base Case)
- **Condition d'arrêt** de la récursion
- Sans lui, la fonction s'appelle indéfiniment → **stack overflow**

### 2. Le cas récursif (Recursive Case)
- Appel de la fonction à elle-même
- Avec des **paramètres modifiés** qui se rapprochent du cas de base

### Structure générale

```c
type fonction(paramètres)
{
    /* CAS DE BASE */
    if (condition_d_arrêt)
        return valeur_finale;

    /* CAS RÉCURSIF */
    return opération + fonction(paramètres_modifiés);
}
```

### Exemple : Factorielle

```c
int factorial(int n)
{
    /* Cas de base */
    if (n == 0 || n == 1)
        return (1);

    /* Cas récursif : n! = n × (n-1)! */
    return (n * factorial(n - 1));
}
```

---

## 📚 La pile d'appels

Chaque appel de fonction crée un **cadre de pile** (stack frame) contenant :
- Les paramètres de la fonction
- Les variables locales
- L'adresse de retour

### Visualisation : factorial(4)

```
                    PILE D'APPELS
┌──────────────────────────────────────────┐
│                                          │
│  ┌────────────────────────────────────┐  │  ← factorial(1)
│  │  n = 1                             │  │     return 1
│  │  return 1                          │  │
│  └────────────────────────────────────┘  │
│                   ↑                      │
│  ┌────────────────────────────────────┐  │  ← factorial(2)
│  │  n = 2                             │  │     return 2 * 1 = 2
│  │  return 2 * factorial(1)           │  │
│  └────────────────────────────────────┘  │
│                   ↑                      │
│  ┌────────────────────────────────────┐  │  ← factorial(3)
│  │  n = 3                             │  │     return 3 * 2 = 6
│  │  return 3 * factorial(2)           │  │
│  └────────────────────────────────────┘  │
│                   ↑                      │
│  ┌────────────────────────────────────┐  │  ← factorial(4)
│  │  n = 4                             │  │     return 4 * 6 = 24
│  │  return 4 * factorial(3)           │  │
│  └────────────────────────────────────┘  │
│                                          │
└──────────────────────────────────────────┘

Résultat : 4! = 4 × 3 × 2 × 1 = 24
```

### Déroulement temporel

```
Appels (phase de descente) :
factorial(4) → factorial(3) → factorial(2) → factorial(1)

Retours (phase de remontée) :
1 ← 2*1=2 ← 3*2=6 ← 4*6=24
```

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-puts_recursion.c` | Affiche une chaîne récursivement | `void _puts_recursion(char *s)` |
| `1-print_rev_recursion.c` | Affiche une chaîne à l'envers | `void _print_rev_recursion(char *s)` |
| `2-strlen_recursion.c` | Longueur d'une chaîne | `int _strlen_recursion(char *s)` |
| `3-factorial.c` | Calcule n! | `int factorial(int n)` |
| `4-pow_recursion.c` | Calcule x^y | `int _pow_recursion(int x, int y)` |
| `5-sqrt_recursion.c` | Racine carrée naturelle | `int _sqrt_recursion(int n)` |
| `6-is_prime_number.c` | Vérifie si premier | `int is_prime_number(int n)` |

---

## 📄 Détail des fichiers

### 0-puts_recursion.c

```c
void _puts_recursion(char *s)
{
    /* Cas de base : fin de chaîne */
    if (s[0] == '\0')
    {
        _putchar('\n');
        return;
    }

    /* Affiche le caractère courant */
    _putchar(s[0]);

    /* Cas récursif : passe au caractère suivant */
    _puts_recursion(s + 1);
}
```

**Déroulement pour "Hi"** :
```
_puts_recursion("Hi")
  → _putchar('H')
  → _puts_recursion("i")
      → _putchar('i')
      → _puts_recursion("")
          → _putchar('\n')
          → return
```

---

### 2-strlen_recursion.c

```c
int _strlen_recursion(char *s)
{
    /* Cas de base : chaîne vide */
    if (*s == '\0')
        return (0);

    /* Cas récursif : 1 + longueur du reste */
    return (1 + _strlen_recursion(s + 1));
}
```

**Déroulement pour "abc"** :
```
_strlen_recursion("abc")
  → 1 + _strlen_recursion("bc")
        → 1 + _strlen_recursion("c")
              → 1 + _strlen_recursion("")
                    → 0
              → 1 + 0 = 1
        → 1 + 1 = 2
  → 1 + 2 = 3
```

---

### 3-factorial.c

```c
int factorial(int n)
{
    /* Cas invalide */
    if (n < 0)
        return (-1);

    /* Cas de base : 0! = 1! = 1 */
    if (n == 0 || n == 1)
        return (1);

    /* Cas récursif : n! = n × (n-1)! */
    return (n * factorial(n - 1));
}
```

**Formule mathématique** :
```
n! = n × (n-1) × (n-2) × ... × 2 × 1
0! = 1 (par définition)

Exemples :
5! = 5 × 4 × 3 × 2 × 1 = 120
3! = 3 × 2 × 1 = 6
```

---

### 4-pow_recursion.c

```c
int _pow_recursion(int x, int y)
{
    /* Cas invalide */
    if (y < 0)
        return (-1);

    /* Cas de base : x^0 = 1 */
    if (y == 0)
        return (1);

    /* Cas récursif : x^y = x × x^(y-1) */
    return (x * _pow_recursion(x, y - 1));
}
```

**Déroulement pour 2^3** :
```
_pow_recursion(2, 3)
  → 2 * _pow_recursion(2, 2)
        → 2 * _pow_recursion(2, 1)
              → 2 * _pow_recursion(2, 0)
                    → 1
              → 2 * 1 = 2
        → 2 * 2 = 4
  → 2 * 4 = 8

Résultat : 2³ = 8
```

---

### 5-sqrt_recursion.c

```c
int _sqrt_helper(int n, int i)
{
    if (n < 0)
        return (-1);

    if (i * i == n)
        return (i);

    if (i * i > n)
        return (-1);

    return (_sqrt_helper(n, i + 1));
}

int _sqrt_recursion(int n)
{
    return (_sqrt_helper(n, 0));
}
```

**Technique** : Fonction auxiliaire (helper) avec un paramètre supplémentaire pour le candidat testé.

**Déroulement pour √9** :
```
_sqrt_recursion(9)
  → _sqrt_helper(9, 0) : 0*0=0 < 9 → continuer
  → _sqrt_helper(9, 1) : 1*1=1 < 9 → continuer
  → _sqrt_helper(9, 2) : 2*2=4 < 9 → continuer
  → _sqrt_helper(9, 3) : 3*3=9 = 9 → return 3 ✓
```

---

### 6-is_prime_number.c

```c
int is_prime_number(int n)
{
    if (n < 2)
        return (0);

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return (0);
    }
    return (1);
}
```

**Note** : Cette implémentation utilise une boucle, mais peut être convertie en récursif avec une fonction helper.

**Algorithme** : On teste les diviseurs jusqu'à √n car si n = a × b, alors l'un des deux est ≤ √n.

---

## 🔧 Compilation et exécution

```bash
# Compiler la factorielle
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-factorial.c -o factorial
./factorial

# Compiler la puissance
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-main.c 4-pow_recursion.c -o pow
./pow

# Compiler avec _putchar
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-main.c 0-puts_recursion.c -o puts_rec
./puts_rec
```

---

## ⚖️ Récursivité vs Itération

| Aspect | Récursif | Itératif |
|--------|----------|----------|
| Lisibilité | Souvent plus élégant | Peut être verbeux |
| Mémoire | Utilise la pile (stack) | Utilise des variables |
| Performance | Overhead des appels | Généralement plus rapide |
| Risque | Stack overflow | Boucle infinie |
| Cas d'usage | Arbres, divide & conquer | Parcours linéaires |

### Équivalence factorielle

```c
/* Version récursive */
int factorial_rec(int n)
{
    if (n <= 1) return 1;
    return n * factorial_rec(n - 1);
}

/* Version itérative */
int factorial_iter(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

---

## ⚠️ Pièges courants

### 1. Récursion infinie
```c
/* MAUVAIS : pas de cas de base ! */
int bad_factorial(int n)
{
    return n * bad_factorial(n - 1);  /* Ne s'arrête jamais */
}
```

### 2. Cas de base mal défini
```c
/* MAUVAIS : oublie le cas n < 0 */
int factorial(int n)
{
    if (n == 0) return 1;
    return n * factorial(n - 1);  /* factorial(-1) → crash */
}
```

### 3. Stack overflow
La pile a une taille limitée (~1-8 MB). Trop d'appels récursifs → crash.

---

## 📚 Ressources

- [Recursion - Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/recursive-algorithms/a/recursion)
- [Recursion in C - GeeksforGeeks](https://www.geeksforgeeks.org/recursion-in-c/)
- [The Call Stack - CS50](https://cs50.harvard.edu/x/2023/notes/4/#the-call-stack)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Pour comprendre la récursivité, il faut d'abord comprendre la récursivité. »</i>
</p>
