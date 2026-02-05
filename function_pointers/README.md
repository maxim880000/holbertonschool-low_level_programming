# 🎯 Function Pointers - Pointeurs de fonctions

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Avancé-red?style=for-the-badge" alt="Avancé"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Qu'est-ce qu'un pointeur de fonction ?](#-quest-ce-quun-pointeur-de-fonction-)
4. [Syntaxe des pointeurs de fonctions](#-syntaxe-des-pointeurs-de-fonctions)
5. [Cas d'utilisation](#-cas-dutilisation)
6. [Fichiers du projet](#-fichiers-du-projet)
7. [Détail des fichiers](#-détail-des-fichiers)
8. [La calculatrice - Projet complet](#-la-calculatrice---projet-complet)
9. [Compilation et exécution](#-compilation-et-exécution)
10. [Ressources](#-ressources)

---

## 📝 Description

Ce projet explore les **pointeurs de fonctions** en C - une fonctionnalité puissante qui permet de traiter les fonctions comme des données. Grâce aux pointeurs de fonctions, vous pouvez :
- Passer des fonctions en argument à d'autres fonctions
- Stocker des fonctions dans des tableaux
- Sélectionner dynamiquement quelle fonction exécuter

C'est le fondement de nombreux design patterns et de la programmation générique en C.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Déclarer et utiliser des **pointeurs de fonctions**
- ✅ Passer des fonctions en **argument** (callbacks)
- ✅ Créer des **tableaux de pointeurs de fonctions**
- ✅ Comprendre la syntaxe `int (*f)(int, int)`
- ✅ Implémenter un système de **dispatch** (sélection de fonction)
- ✅ Utiliser les pointeurs de fonctions avec des **structures**

---

## 🧠 Qu'est-ce qu'un pointeur de fonction ?

### Concept fondamental

En C, une fonction n'est pas seulement du code - elle existe à une **adresse mémoire**. Un pointeur de fonction stocke cette adresse, permettant d'appeler la fonction indirectement.

```c
#include <stdio.h>

void hello(void)
{
    printf("Hello!\n");
}

int main(void)
{
    /* Le nom de la fonction EST son adresse */
    printf("Adresse de hello: %p\n", (void *)hello);

    /* Pointeur vers la fonction hello */
    void (*ptr)(void) = hello;

    /* Appel via le pointeur */
    ptr();  /* Affiche: Hello! */

    return (0);
}
```

### Visualisation en mémoire

```
Mémoire programme (section .text)
┌────────────────────────────────────────┐
│ ...                                    │
│ 0x00401000:  void hello(void)          │  ◄── Adresse de la fonction
│              { printf("Hello!"); }     │
│ ...                                    │
│ 0x00401050:  int add(int a, int b)     │
│              { return a + b; }         │
│ ...                                    │
└────────────────────────────────────────┘

Stack (variable ptr)
┌────────────────────────────┐
│  ptr = 0x00401000          │  ◄── Contient l'adresse de hello
└────────────────────────────┘

ptr() → va à l'adresse 0x00401000 et exécute le code
```

---

## 📐 Syntaxe des pointeurs de fonctions

### Déclaration

```c
/*
 * Lecture de droite à gauche:
 * "ptr est un pointeur vers une fonction
 *  qui prend (int, int) et retourne int"
 */
int (*ptr)(int, int);

/* Exemples de signatures */
void (*f1)(void);              /* Pas de param, pas de retour */
int (*f2)(char *);             /* char* en param, retourne int */
char *(*f3)(int, int, char);   /* 3 params, retourne char* */
```

### Assignation et appel

```c
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

/* Assignation */
int (*operation)(int, int);
operation = add;       /* ou &add (optionnel) */

/* Appel */
int result = operation(5, 3);   /* result = 8 */

/* Changement de fonction */
operation = sub;
result = operation(5, 3);       /* result = 2 */
```

### Avec typedef (plus lisible)

```c
/* Définir un type pour les pointeurs de fonction */
typedef int (*math_func)(int, int);

/* Utilisation simplifiée */
math_func op = add;
int result = op(10, 5);
```

---

## 🔧 Cas d'utilisation

### 1. Callbacks (fonctions de rappel)

```c
void process_array(int *arr, size_t size, void (*callback)(int))
{
    for (size_t i = 0; i < size; i++)
        callback(arr[i]);
}

void print_int(int n) { printf("%d ", n); }
void print_square(int n) { printf("%d ", n * n); }

/* Utilisation */
int arr[] = {1, 2, 3, 4, 5};
process_array(arr, 5, print_int);    /* 1 2 3 4 5 */
process_array(arr, 5, print_square); /* 1 4 9 16 25 */
```

### 2. Tableau de pointeurs de fonctions

```c
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int main(void)
{
    /* Tableau de pointeurs de fonctions */
    int (*ops[])(int, int) = {add, sub, mul};

    printf("add: %d\n", ops[0](5, 3));  /* 8 */
    printf("sub: %d\n", ops[1](5, 3));  /* 2 */
    printf("mul: %d\n", ops[2](5, 3));  /* 15 */

    return (0);
}
```

### 3. Dispatch avec structures

```c
typedef struct {
    char *name;
    int (*func)(int, int);
} operation_t;

operation_t operations[] = {
    {"add", add},
    {"sub", sub},
    {"mul", mul},
    {NULL, NULL}
};

int (*find_operation(char *name))(int, int)
{
    for (int i = 0; operations[i].name != NULL; i++)
        if (strcmp(operations[i].name, name) == 0)
            return operations[i].func;
    return NULL;
}
```

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `function_pointers.h` | Prototypes des fonctions | - |
| `0-print_name.c` | Appelle une fonction pour imprimer un nom | `void print_name(char *name, void (*f)(char *))` |
| `1-array_iterator.c` | Applique une fonction à chaque élément | `void array_iterator(int *array, size_t size, void (*action)(int))` |
| `2-int_index.c` | Recherche un élément avec une fonction de comparaison | `int int_index(int *array, int size, int (*cmp)(int))` |
| `3-calc.h` | Header de la calculatrice | Structure `op_t` |
| `3-op_functions.c` | Opérations arithmétiques | `op_add`, `op_sub`, `op_mul`, `op_div`, `op_mod` |
| `3-get_op_func.c` | Sélectionne l'opération | `int (*get_op_func(char *s))(int, int)` |
| `3-main.c` | Programme principal calculatrice | - |

---

## 📄 Détail des fichiers

### function_pointers.h

```c
#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif
```

---

### 0-print_name.c

```c
#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - prints a name using a callback function
 * @name: name to print
 * @f: pointer to the printing function
 */
void print_name(char *name, void (*f)(char *))
{
    if (name == NULL || f == NULL)
        return;
    f(name);  /* Appelle la fonction passée en paramètre */
}
```

**Exemple d'utilisation** :
```c
void print_upper(char *name) { /* imprime en majuscules */ }
void print_lower(char *name) { /* imprime en minuscules */ }

print_name("JOHN", print_lower);  /* john */
print_name("john", print_upper);  /* JOHN */
```

---

### 1-array_iterator.c

```c
#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: array to iterate over
 * @size: size of the array
 * @action: function to apply to each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;

    if (array == NULL || action == NULL)
        return;

    for (i = 0; i < size; i++)
        action(array[i]);
}
```

**Visualisation** :
```
array = {10, 20, 30, 40, 50}
action = print_int

array_iterator(array, 5, print_int):

  Itération 0: action(10) → print 10
  Itération 1: action(20) → print 20
  Itération 2: action(30) → print 30
  Itération 3: action(40) → print 40
  Itération 4: action(50) → print 50
```

---

### 2-int_index.c

```c
#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: array to search
 * @size: number of elements
 * @cmp: comparison function (returns non-zero if match)
 *
 * Return: index of first match, or -1 if not found
 */
int int_index(int *array, int size, int (*cmp)(int))
{
    int i;

    if (array == NULL || cmp == NULL)
        return (-1);

    for (i = 0; i < size; i++)
    {
        if (cmp(array[i]))
            return (i);
    }
    return (-1);
}
```

**Exemple** :
```c
int is_even(int n) { return (n % 2 == 0); }
int is_greater_than_10(int n) { return (n > 10); }

int arr[] = {1, 3, 5, 12, 8};
int_index(arr, 5, is_even);           /* Returns 3 (12 is first even) */
int_index(arr, 5, is_greater_than_10); /* Returns 3 (12 > 10) */
```

---

## 🧮 La calculatrice - Projet complet

### 3-calc.h

```c
#ifndef CALC_H
#define CALC_H

/**
 * struct op - Associates an operator with its function
 * @op: The operator string ("+", "-", etc.)
 * @f: Pointer to the function
 */
typedef struct op
{
    char *op;
    int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif
```

---

### 3-op_functions.c

```c
#include "3-calc.h"

int op_add(int a, int b) { return (a + b); }
int op_sub(int a, int b) { return (a - b); }
int op_mul(int a, int b) { return (a * b); }
int op_div(int a, int b) { return (a / b); }
int op_mod(int a, int b) { return (a % b); }
```

---

### 3-get_op_func.c

```c
#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - selects the correct function based on operator
 * @s: the operator passed as argument
 *
 * Return: pointer to the matching function, or NULL
 */
int (*get_op_func(char *s))(int, int)
{
    int i = 0;

    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };

    while (ops[i].op != NULL)
    {
        if (strcmp(ops[i].op, s) == 0)
            return (ops[i].f);
        i++;
    }
    return (NULL);
}
```

**Visualisation du dispatch** :
```
get_op_func("*")

ops[] = [
  {"+", op_add},  ← strcmp("+", "*") ≠ 0, continue
  {"-", op_sub},  ← strcmp("-", "*") ≠ 0, continue
  {"*", op_mul},  ← strcmp("*", "*") == 0, MATCH!
  ...
]

Retourne: op_mul (adresse de la fonction)
```

---

### Flux d'exécution de la calculatrice

```
./calc 10 + 5

main(argc=4, argv=["./calc", "10", "+", "5"])
  │
  ├── num1 = atoi("10") = 10
  ├── num2 = atoi("5") = 5
  │
  ├── op_func = get_op_func("+")
  │     │
  │     └── Recherche dans ops[]
  │         └── Trouve {"+", op_add}
  │         └── Retourne: op_add
  │
  ├── result = op_func(10, 5)
  │     │
  │     └── op_add(10, 5) = 15
  │
  └── printf("%d\n", 15)

Output: 15
```

---

## 🔧 Compilation et exécution

```bash
# Compiler les exemples simples
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-print_name.c -o print_name
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-array_iterator.c -o array_iter

# Compiler la calculatrice
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
    3-main.c 3-op_functions.c 3-get_op_func.c -o calc

# Exécuter
./print_name
./array_iter

# Calculatrice
./calc 10 + 5     # 15
./calc 20 - 8     # 12
./calc 6 \* 7     # 42 (escape * for shell)
./calc 100 / 10   # 10
./calc 17 % 5     # 2
```

---

## ⚠️ Erreurs courantes

### Syntaxe de déclaration

```c
/* FAUX - ceci déclare une fonction qui retourne int* */
int *func(int, int);

/* CORRECT - pointeur vers une fonction retournant int */
int (*func)(int, int);
```

### Oubli des parenthèses

```c
int (*get_op_func(char *s))(int, int);  /* Correct */
/*      └──────────────┘
        fonction get_op_func qui retourne
        un pointeur vers fonction (int, int) → int */
```

---

## 📚 Ressources

- [Function Pointers in C - GeeksforGeeks](https://www.geeksforgeeks.org/function-pointer-in-c/)
- [Callbacks in C](https://www.learn-c.org/en/Function_Pointers)
- [How to Read C Declarations](https://cdecl.org/)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Les pointeurs de fonctions transforment le C statique en langage dynamique. »</i>
</p>
