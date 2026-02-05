# 📦 Variadic Functions - Fonctions à arguments variables

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Avancé-red?style=for-the-badge" alt="Avancé"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Comprendre les fonctions variadiques](#-comprendre-les-fonctions-variadiques)
4. [Les macros de stdarg.h](#-les-macros-de-stdargh)
5. [Fichiers du projet](#-fichiers-du-projet)
6. [Détail des fichiers](#-détail-des-fichiers)
7. [Cas d'utilisation avancés](#-cas-dutilisation-avancés)
8. [Compilation et exécution](#-compilation-et-exécution)
9. [Ressources](#-ressources)

---

## 📝 Description

Ce projet explore les **fonctions variadiques** (variadic functions) en C - des fonctions qui acceptent un nombre **variable** d'arguments. C'est le mécanisme qui permet à `printf` d'accepter 1, 5, ou 100 arguments !

Les fonctions variadiques utilisent la bibliothèque `<stdarg.h>` et un ensemble de macros pour accéder aux arguments.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre la syntaxe **`...`** (ellipsis)
- ✅ Utiliser **`va_list`**, **`va_start`**, **`va_arg`**, **`va_end`**
- ✅ Créer des fonctions avec un nombre **variable** d'arguments
- ✅ Implémenter des fonctions type **printf**
- ✅ Gérer différents **types** d'arguments variadiques
- ✅ Comprendre le **const** dans les prototypes

---

## 🧠 Comprendre les fonctions variadiques

### Syntaxe de base

```c
#include <stdarg.h>

/* Le ... (ellipsis) indique "n'importe quel nombre d'arguments" */
int my_function(int fixed_arg, ...)
{
    va_list args;           /* Variable pour parcourir les arguments */
    va_start(args, fixed_arg);  /* Initialiser après le dernier arg fixe */
    
    /* Récupérer les arguments un par un */
    int val = va_arg(args, int);
    
    va_end(args);           /* Nettoyer */
    return val;
}
```

### Pourquoi un argument fixe ?

La fonction doit savoir **combien** d'arguments ont été passés. Cela peut être :
- Un **compteur** : `sum(3, 10, 20, 30)` → 3 arguments suivent
- Une **chaîne format** : `printf("%d %s", 42, "hello")` → le format indique les types

```c
/* Avec compteur */
int sum(int count, ...);
sum(3, 10, 20, 30);  /* count=3 indique 3 arguments */

/* Avec format (comme printf) */
void print(const char *format, ...);
print("%d%s", 42, "hello");  /* format indique: int, puis string */
```

---

## 🔧 Les macros de stdarg.h

### va_list

```c
va_list args;
```
Déclare une variable qui servira à **parcourir** les arguments. C'est comme un curseur dans une liste.

### va_start

```c
va_start(args, last_fixed);
```
**Initialise** le curseur `args` pour commencer après `last_fixed` (le dernier argument nommé).

### va_arg

```c
int n = va_arg(args, int);
char *s = va_arg(args, char *);
double d = va_arg(args, double);
```
**Récupère** l'argument suivant du type spécifié et **avance** le curseur.

⚠️ **Important** : Vous devez connaître le type de chaque argument !

### va_end

```c
va_end(args);
```
**Nettoie** la liste d'arguments. Toujours appeler avant de quitter la fonction.

### va_copy (C99+)

```c
va_list copy;
va_copy(copy, args);  /* Copie args dans copy */
/* ... utiliser copy ... */
va_end(copy);
```

### Visualisation du parcours

```
Appel: sum_them_all(4, 10, 20, 30, 40)

Arguments en mémoire:
┌────┬────┬────┬────┬────┐
│ 4  │ 10 │ 20 │ 30 │ 40 │
└────┴────┴────┴────┴────┘
  n    ▲
       │
       └── va_start(args, n) positionne ici

va_arg(args, int) = 10, avance →
                       ▲
va_arg(args, int) = 20, avance →
                            ▲
va_arg(args, int) = 30, avance →
                                 ▲
va_arg(args, int) = 40, avance →
                                      (fin)
```

---

## 📂 Fichiers du projet

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `variadic_functions.h` | Prototypes des fonctions | - |
| `0-sum_them_all.c` | Somme de n entiers | `int sum_them_all(const unsigned int n, ...)` |
| `1-print_numbers.c` | Affiche n nombres avec séparateur | `void print_numbers(const char *separator, const unsigned int n, ...)` |
| `2-print_strings.c` | Affiche n chaînes avec séparateur | `void print_strings(const char *separator, const unsigned int n, ...)` |
| `3-print_all.c` | Affiche n'importe quoi selon un format | `void print_all(const char * const format, ...)` |

---

## 📄 Détail des fichiers

### variadic_functions.h

```c
#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
```

---

### 0-sum_them_all.c

```c
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of parameters to sum
 *
 * Return: sum of all parameters, or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
    unsigned int i;
    va_list args;
    int sum = 0;

    if (n == 0)
        return (0);

    va_start(args, n);

    for (i = 0; i < n; i++)
        sum += va_arg(args, int);

    va_end(args);

    return (sum);
}
```

**Exécution pas à pas** :
```
sum_them_all(3, 100, 200, 300)

n = 3
va_start(args, n)       // args pointe sur 100

i=0: sum += va_arg(args, int)  // sum = 0 + 100 = 100
i=1: sum += va_arg(args, int)  // sum = 100 + 200 = 300
i=2: sum += va_arg(args, int)  // sum = 300 + 300 = 600

va_end(args)
return 600
```

---

### 1-print_numbers.c

```c
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers followed by a separator
 * @separator: string to print between numbers
 * @n: number of integers passed
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
    unsigned int i;
    va_list args;

    va_start(args, n);

    for (i = 0; i < n; i++)
    {
        printf("%d", va_arg(args, int));
        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }

    printf("\n");
    va_end(args);
}
```

**Exemple** :
```c
print_numbers(", ", 4, 10, 20, 30, 40);
/* Output: 10, 20, 30, 40 */

print_numbers(" - ", 3, 1, 2, 3);
/* Output: 1 - 2 - 3 */

print_numbers(NULL, 2, 42, 99);
/* Output: 4299 (pas de séparateur) */
```

---

### 2-print_strings.c

```c
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings followed by a separator
 * @separator: string to print between strings
 * @n: number of strings passed
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
    unsigned int i;
    va_list args;
    char *str;

    va_start(args, n);

    for (i = 0; i < n; i++)
    {
        str = va_arg(args, char *);
        printf("%s", str ? str : "(nil)");
        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }

    printf("\n");
    va_end(args);
}
```

**Gestion de NULL** :
```c
print_strings(", ", 3, "Hello", NULL, "World");
/* Output: Hello, (nil), World */
```

---

### 3-print_all.c

```c
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything based on format string
 * @format: format string (c=char, i=int, f=float, s=string)
 *
 * Any other character in format is ignored
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    char *str;

    va_start(args, format);

    if (format)
    {
        while (format[i])
        {
            switch (format[i])
            {
                case 'c':
                    printf("%c", va_arg(args, int));
                    break;
                case 'i':
                    printf("%d", va_arg(args, int));
                    break;
                case 'f':
                    printf("%f", va_arg(args, double));
                    break;
                case 's':
                    str = va_arg(args, char *);
                    printf("%s", str ? str : "(nil)");
                    break;
                default:
                    i++;
                    continue;  /* Skip invalid format chars */
            }
            if (format[i + 1] && (format[i] == 'c' || format[i] == 'i' ||
                                  format[i] == 'f' || format[i] == 's'))
                printf(", ");
            i++;
        }
    }
    printf("\n");
    va_end(args);
}
```

**Exemple d'exécution** :
```c
print_all("ceis", 'H', 42, 3.14, "Hello");
/* Output: H, 42, 3.140000, Hello */

print_all("si", "Age:", 25);
/* Output: Age:, 25 */

print_all("sss", "One", NULL, "Three");
/* Output: One, (nil), Three */
```

**Visualisation du switch** :
```
format = "cis"
args = ['B', 42, "test"]

i=0: format[0]='c' → case 'c' → printf("%c", 'B') → "B"
     format[1] existe → printf(", ")
i=1: format[1]='i' → case 'i' → printf("%d", 42) → "42"
     format[2] existe → printf(", ")
i=2: format[2]='s' → case 's' → printf("%s", "test") → "test"
     format[3] = '\0' → pas de virgule

printf("\n")
Output final: "B, 42, test\n"
```

---

## 🔬 Cas d'utilisation avancés

### Mini-printf

```c
void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'd':
                    printf("%d", va_arg(args, int));
                    break;
                case 's':
                    printf("%s", va_arg(args, char *));
                    break;
                case 'c':
                    printf("%c", va_arg(args, int));
                    break;
                case '%':
                    putchar('%');
                    break;
            }
        }
        else
            putchar(*format);
        format++;
    }
    va_end(args);
}

my_printf("Hello %s, you are %d years old!\n", "Alice", 25);
/* Output: Hello Alice, you are 25 years old! */
```

### Fonction de logging

```c
void log_message(const char *level, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    printf("[%s] ", level);
    vprintf(format, args);  /* vprintf utilise va_list directement */
    printf("\n");

    va_end(args);
}

log_message("INFO", "User %s logged in", "john");
/* Output: [INFO] User john logged in */

log_message("ERROR", "Failed after %d attempts", 3);
/* Output: [ERROR] Failed after 3 attempts */
```

---

## ⚠️ Pièges courants

### 1. Type promotion

```c
/* char et short sont promus en int */
char c = 'A';
my_func(c);  /* Passé comme int */
/* Récupérer avec: va_arg(args, int) */

/* float est promu en double */
float f = 3.14f;
my_func(f);  /* Passé comme double */
/* Récupérer avec: va_arg(args, double) */
```

### 2. Mauvais type dans va_arg

```c
/* DANGER: Undefined behavior */
int n = va_arg(args, double);  /* Mauvais si l'arg est int ! */
```

### 3. Trop ou pas assez d'arguments

```c
sum_them_all(5, 1, 2, 3);  /* n=5 mais seulement 3 args → UB */
sum_them_all(2, 1, 2, 3, 4);  /* n=2 mais 4 args → 3 et 4 ignorés */
```

---

## 🔧 Compilation et exécution

```bash
# Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-sum_them_all.c -o sum
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-print_numbers.c -o print_num
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-print_strings.c -o print_str
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-print_all.c -o print_all

# Exécuter
./sum
./print_num
./print_str
./print_all
```

---

## 📚 Ressources

- [stdarg.h - cppreference](https://en.cppreference.com/w/c/variadic)
- [Variadic Functions - GNU](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [How printf works](https://www.cypress.com/file/54441/download)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Les fonctions variadiques rendent le C plus flexible que jamais. »</i>
</p>
