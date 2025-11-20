a# 🔮 C - Variadic Functions

<div align="center">

![Holberton School Banner](https://www.holbertonschool.com/holberton-logo.png)

### Master the Art of Variable Arguments in C

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![Language](https://img.shields.io/badge/language-C-blue.svg)]()
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/maxim880000/holbertonschool-low_level_programming.svg)](https://github.com/maxim880000/holbertonschool-low_level_programming/issues)

**Créer tes propres `printf`, `scanf`, et bien d'autres fonctions variadiques comme un pro ! 🚀**

[📚 Documentation](#-table-des-matières) • [💻 Projets](#-projets-de-la-semaine) • [🎯 Learning Objectives](#-objectifs-apprentissage) • [📖 Ressources](#-ressources)

</div>

---

## 📋 Table des matières

1. [À propos](#-à-propos)
2. [Objectifs d'apprentissage](#-objectifs-apprentissage)
3. [Concept fondamental](#-concept-fondamental)
4. [Les 4 macros magiques](#-les-4-macros-magiques)
5. [Projets de la semaine](#-projets-de-la-semaine)
6. [Compilation et tests](#-compilation-et-tests)
7. [Pièges courants](#-pièges-courants)
8. [Ressources](#-ressources)

---

## 🎯 À propos

Ce projet te permet de **maîtriser les fonctions variadiques** - ces fonctions mystérieuses qui acceptent un nombre **indéterminé d'arguments**, tout comme `printf()` et `scanf()`.

**Tu utilises déjà des fonctions variadiques chaque jour :**

```c
printf("Nombre: %d, String: %s\n", 42, "Hello");  // 2 arguments variables
printf("Un seul: %d\n", 10);                       // 1 argument variable
printf("Trois: %d %d %d\n", 1, 2, 3);             // 3 arguments variables
```

**Après ce projet, tu pourras créer les TIENNES ! 💪**

---

## 🎓 Objectifs d'apprentissage

À la fin de ce projet, tu seras capable de :

✅ **Comprendre** le mécanisme des fonctions variadiques  
✅ **Déclarer** une fonction avec un nombre variable d'arguments  
✅ **Utiliser** les macros de `<stdarg.h>` correctement  
✅ **Implémenter** tes propres fonctions génériques (`print_numbers`, `print_strings`, `print_all`)  
✅ **Gérer** les erreurs et les cas limites (NULL, types mixtes)  
✅ **Maîtriser** la promotion de types en C  
✅ **Éviter** les pièges courants et comportements indéfinis  

---

## 💡 Concept fondamental

### Qu'est-ce qu'une fonction variadique ?

Une fonction qui prend un **nombre indéterminé d'arguments**, défini au runtime et non à la compilation.

**Syntaxe générale :**

```c
type fonction(paramètres_fixes, ...);
```

Les trois points `...` signifient : *"et potentiellement d'autres arguments"*.

### Règles absolues

| ✅ Obligatoire | ❌ Interdit |
|---|---|
| Au moins **1 paramètre fixe** avant les `...` | Les `...` n'importe où sauf la fin |
| Connaître le **type** de chaque argument | Oublier `va_end()` |
| Avoir un **moyen** de savoir combien d'args | Utiliser `va_arg()` sans `va_start()` |
| Appeler `va_end()` avant de quitter | Mélanger les types sans vérifier |

---

## 🔧 Les 4 macros magiques

Pour utiliser les fonctions variadiques, tu **DOIS** inclure :

```c
#include <stdarg.h>
```

### 1️⃣ `va_list` - La boîte des arguments

```c
va_list ap;  // "ap" = argument pointer
```

**C'est quoi ?** Un type spécial qui représente la **liste des arguments variables**.

**Pense à ça comme une boîte :** Tu vas l'ouvrir et récupérer les arguments un par un.

---

### 2️⃣ `va_start()` - Ouvrir la boîte

```c
va_start(ap, last_fixed_param);
```

**À quoi ça sert ?** Initialise `ap` pour qu'il pointe sur le **premier argument variable**.

**Exemple :**

```c
void my_function(unsigned int n, ...)
{
    va_list ap;
    va_start(ap, n);  // n = dernier paramètre fixe
    // Maintenant ap pointe sur le premier argument variable
}
```

**⚠️ Règle d'or :** `va_start` DOIT être appelé avant `va_arg`.

---

### 3️⃣ `va_arg()` - Récupérer un argument

```c
type valeur = va_arg(ap, type);
```

**À quoi ça sert ?** Récupère le **prochain argument** et avance automatiquement au suivant.

**Exemple :**

```c
void print_numbers(unsigned int n, ...)
{
    va_list ap;
    va_start(ap, n);
    
    for (unsigned int i = 0; i < n; i++)
    {
        int num = va_arg(ap, int);
        printf("%d ", num);
    }
    
    va_end(ap);
}

print_numbers(3, 10, 20, 30);  // Affiche: 10 20 30
```

**🚨 ATTENTION CRITIQUE :** Tu DOIS connaître le type exact. Sinon : **CRASH garanti !**

---

### 4️⃣ `va_end()` - Fermer la boîte

```c
va_end(ap);
```

**À quoi ça sert ?** Nettoie et termine l'utilisation de `ap`.

**⚠️ TOUJOURS appeler avant de quitter la fonction :**

```c
void my_function(unsigned int n, ...)
{
    va_list ap;
    va_start(ap, n);
    
    if (n == 0)
    {
        va_end(ap);  // Obligatoire avant le return !
        return;
    }
    
    va_end(ap);
}
```

---

## 📦 Projets de la semaine

Voici les 4 exercices à réaliser :

### **Exercice 0 : Beauty is variable, ugliness is constant**

**Fichier :** `0-sum_them_all.c`

**Prototype :**
```c
int sum_them_all(const unsigned int n, ...);
```

**Description :** Retourne la **somme de tous ses paramètres**.

**Comportement :**
- Si `n == 0`, retourne `0`
- Sinon, additionne tous les `n` arguments

**Exemple :**
```c
printf("%d\n", sum_them_all(2, 98, 1024));           // 1122
printf("%d\n", sum_them_all(4, 98, 1024, 402, -1024)); // 500
printf("%d\n", sum_them_all(0));                      // 0
```

**Logique :**
```c
int sum_them_all(const unsigned int n, ...)
{
    va_list ap;
    unsigned int i;
    int sum = 0;
    
    if (n == 0)
        return (0);
    
    va_start(ap, n);
    for (i = 0; i < n; i++)
        sum += va_arg(ap, int);
    va_end(ap);
    
    return (sum);
}
```

**Fonctions utilisées :** `va_list`, `va_start()`, `va_arg()`, `va_end()`

---

### **Exercice 1 : To be is to be the value of a variable**

**Fichier :** `1-print_numbers.c`

**Prototype :**
```c
void print_numbers(const char *separator, const unsigned int n, ...);
```

**Description :** Affiche des **nombres** séparés par `separator`, avec une nouvelle ligne à la fin.

**Comportement :**
- Si `separator` est `NULL`, n'affiche rien entre les nombres
- Si `n == 0`, affiche juste une nouvelle ligne
- Pas de séparateur après le dernier nombre

**Exemple :**
```c
print_numbers(", ", 4, 0, 98, -1024, 402);  // Affiche: 0, 98, -1024, 402
print_numbers(NULL, 3, 10, 20, 30);         // Affiche: 102030
print_numbers(" | ", 2, 25, 100);           // Affiche: 25 | 100
```

**Logique :**
```c
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list ap;
    unsigned int i;
    
    va_start(ap, n);
    for (i = 0; i < n; i++)
    {
        printf("%d", va_arg(ap, int));
        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }
    printf("\n");
    va_end(ap);
}
```

**Commandes clés :** `va_start()`, `va_arg()`, `va_end()`, `printf()`

---

### **Exercice 2 : One woman's constant is another woman's variable**

**Fichier :** `2-print_strings.c`

**Prototype :**
```c
void print_strings(const char *separator, const unsigned int n, ...);
```

**Description :** Affiche des **chaînes de caractères** séparées par `separator`.

**Comportement :**
- Si `separator` est `NULL`, n'affiche rien entre les strings
- Si une string est `NULL`, affiche `(nil)` à la place
- Pas de séparateur après la dernière string

**Exemple :**
```c
print_strings(", ", 2, "Jay", "Django");              // Jay, Django
print_strings(" | ", 3, "Hello", NULL, "World");     // Hello | (nil) | World
print_strings(":", 1, "42");                          // 42
```

**Logique :**
```c
void print_strings(const char *separator, const unsigned int n, ...)
{
    va_list ap;
    unsigned int i;
    char *str;
    
    va_start(ap, n);
    for (i = 0; i < n; i++)
    {
        str = va_arg(ap, char *);
        if (str == NULL)
            printf("(nil)");
        else
            printf("%s", str);
        if (separator != NULL && i < n - 1)
            printf("%s", separator);
    }
    printf("\n");
    va_end(ap);
}
```

**Commandes clés :** Vérification `NULL`, `va_arg()`, chaînes de caractères

**⚠️ CRITIQUE :** TOUJOURS vérifier `NULL` avant d'afficher une string. Sinon : **SEGFAULT !**

---

### **Exercice 3 : To be is a to be the value of a variable**

**Fichier :** `3-print_all.c`

**Prototype :**
```c
void print_all(const char * const format, ...);
```

**Description :** Affiche **n'importe quel type** selon un format donné, comme un mini `printf()`.

**Format :**
- `c` : char
- `i` : int
- `f` : float
- `s` : char * (affiche `(nil)` si NULL)
- Tout autre caractère est **ignoré**

**Comportement :**
- Les valeurs sont séparées par `, ` (virgule + espace)
- Termine par une nouvelle ligne
- Pas de séparateur après la dernière valeur

**Exemple :**
```c
print_all("ceis", 'B', 3, "stSchool");
// Affiche: B, 3, stSchool

print_all("ifs", 42, 3.14, "Hello");
// Affiche: 42, 3.140000, Hello

print_all("csisciifs", 'A', "String", 98, 'B', NULL, 1024, 402, 3.14, "End");
// Affiche: A, String, 98, B, (nil), 1024, 402, 3.140000, End
```

**Logique :**
```c
void print_all(const char * const format, ...)
{
    va_list ap;
    unsigned int i = 0;
    char *str;
    char *sep = "";
    
    if (format == NULL)
        return;
    
    va_start(ap, format);
    
    while (format[i])
    {
        switch (format[i])
        {
            case 'c':
                printf("%s%c", sep, va_arg(ap, int));
                sep = ", ";
                break;
            case 'i':
                printf("%s%d", sep, va_arg(ap, int));
                sep = ", ";
                break;
            case 'f':
                printf("%s%f", sep, va_arg(ap, double));
                sep = ", ";
                break;
            case 's':
                str = va_arg(ap, char *);
                printf("%s%s", sep, (str == NULL) ? "(nil)" : str);
                sep = ", ";
                break;
            default:
                i++;
                continue;
        }
        i++;
    }
    
    printf("\n");
    va_end(ap);
}
```

**Commandes clés :** `switch`, promotion de types (`int` pour `char`, `double` pour `float`), gestion du séparateur

**🔴 Points ULTRA importants :**

| ⚠️ Type | ❌ FAUX | ✅ CORRECT |
|---|---|---|
| char | `va_arg(ap, char)` | `va_arg(ap, int)` |
| float | `va_arg(ap, float)` | `va_arg(ap, double)` |

---

## 🔨 Compilation et tests

### Compilation simple

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o variadic_test
```

### Avec tous les flags recommandés

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 -D_GNU_SOURCE *.c -o variadic_test
```

### Exécution

```bash
./variadic_test
```

### Vérifier les fuites mémoire avec Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all ./variadic_test
```

**Résultat attendu :**
```
All heap blocks were freed -- no leaks are possible
```

---

## ⚠️ Pièges courants

### ❌ Piège 1 : Oublier `va_end()`

```c
void bad_function(int n, ...)
{
    va_list ap;
    va_start(ap, n);
    // Traitement...
    // ❌ OUBLI DE va_end(ap) !
}
```

**Solution :**
```c
void good_function(int n, ...)
{
    va_list ap;
    va_start(ap, n);
    // Traitement...
    va_end(ap);  // ✅ TOUJOURS ajouter !
}
```

---

### ❌ Piège 2 : Mauvais type dans `va_arg()`

```c
char c = va_arg(ap, char);      // ❌ char promu en int !
float f = va_arg(ap, float);    // ❌ float promu en double !
```

**Solution :**
```c
char c = (char)va_arg(ap, int);
float f = (float)va_arg(ap, double);
```

---

### ❌ Piège 3 : Ne pas vérifier `NULL` pour les strings

```c
char *str = va_arg(ap, char *);
printf("%s\n", str);  // ❌ Si str == NULL → SEGFAULT !
```

**Solution :**
```c
char *str = va_arg(ap, char *);
if (str == NULL)
    printf("(nil)\n");
else
    printf("%s\n", str);
```

---

### ❌ Piège 4 : Appeler `va_arg()` trop de fois

```c
void bad_function(int n, ...)
{
    va_list ap;
    va_start(ap, n);
    for (int i = 0; i < n + 5; i++)  // ❌ TROP d'appels !
        int x = va_arg(ap, int);
    va_end(ap);
}
```

**Résultat :** Comportement indéfini, valeurs aléatoires, crash possible.

---

### ❌ Piège 5 : Utiliser `va_start()` deux fois sans `va_end()`

```c
va_list ap;
va_start(ap, n);
// Traitement...
va_start(ap, n);  // ❌ Sans va_end() avant !
```

**Solution :**
```c
va_list ap;
va_start(ap, n);
// Traitement...
va_end(ap);
va_start(ap, n);  // ✅ OK maintenant
// Traitement...
va_end(ap);
```

---

## 📚 Résumé des points clés

### Les 4 étapes obligatoires

1. **Déclarer** : `va_list ap;`
2. **Initialiser** : `va_start(ap, last_param);`
3. **Récupérer** : `va_arg(ap, type);` (répéter)
4. **Terminer** : `va_end(ap);`

### Checklist avant de commiter

- ✅ Toujours avoir AU MOINS 1 paramètre fixe
- ✅ Connaître le type exact de chaque argument
- ✅ Appeler `va_end()` avant TOUT `return`
- ✅ Vérifier `NULL` pour les pointeurs
- ✅ Respecter les promotions de types
- ✅ Tester avec valgrind
- ✅ Compiler avec `-Wall -Werror -Wextra -pedantic`

---

## 📖 Ressources

### Documentation officielle

- [stdarg.h - GNU C Library](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [va_list, va_start, va_arg, va_end - cppreference](https://en.cppreference.com/w/c/variadic)

### Tutoriels en ligne

- [Variadic Functions in C - GeeksforGeeks](https://www.geeksforgeeks.org/variadic-functions-in-c/)
- [Understanding Variadic Functions - Learn C](https://www.learn-c.org/en/Variadic_Functions)

### Livres recommandés

- **"The C Programming Language"** par Kernighan & Ritchie (K&R) - Chapitre 7.3
- **"C: A Reference Manual"** par Harbison & Steele - Section 9.2

### Man pages

```bash
man stdarg
man va_start
man va_arg
man va_end
man va_copy  # Bonus : copier une va_list
```

---

## 👨‍💻 Liens GitHub

📂 **Tous les exercices :** [holbertonschool-low_level_programming/variadic_functions](https://github.com/maxim880000/holbertonschool-low_level_programming/tree/main/variadic_functions)

- `0-sum_them_all.c` - Somme des arguments
- `1-print_numbers.c` - Affiche les nombres
- `2-print_strings.c` - Affiche les strings
- `3-print_all.c` - Affiche tout type

---

## ✍️ Auteur

- [@maxim880000](https://github.com/maxim880000) - Implémentation et travail initial

---

<div align="center">

### 🚀 Maintenant, tu sais créer tes propres fonctions variadiques comme un pro !

**N'oublie pas :** Comprendre les fonctions variadiques, c'est avoir une clé magique pour créer des fonctions ultra-flexibles et génériques. 🔑✨

**Happy Coding ! 💻**

</div>