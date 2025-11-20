# 🎯 C - Function Pointers

<div align="center">

![Holberton School Logo](https://www.holbertonschool.com/holberton-logo.png)

### Master Function Pointers in C - Advanced Pointer Techniques

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![Language](https://img.shields.io/badge/language-C-blue.svg)]()
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)
[![GitHub](https://img.shields.io/badge/GitHub-holbertonschool--low__level__programming-black.svg)](https://github.com/maxim880000/holbertonschool-low_level_programming/tree/main/function_pointers)

**Les pointeurs de fonction sont la clé vers une programmation flexible, modulaire et réutilisable ! 🔑**

[📚 Documentation](#-table-des-matières) • [🎯 Objectifs](#-objectifs-dapprentissage) • [💻 Projets](#-projets-du-programme) • [🚀 Ressources](#-ressources)

</div>

---

## 📋 Table des matières

1. [À propos](#-à-propos)
2. [Objectifs d'apprentissage](#-objectifs-dapprentissage)
3. [Concept fondamental](#-concept-fondamental)
4. [Syntaxe et vocabulaire](#-syntaxe-et-vocabulaire)
5. [Projets du programme](#-projets-du-programme)
6. [Compilation et tests](#-compilation-et-tests)
7. [Pièges courants](#-pièges-courants)
8. [Bonnes pratiques](#-bonnes-pratiques)
9. [Ressources](#-ressources)

---

## 🎨 À propos

Les **pointeurs de fonction** sont une des concepts les plus puissants du C, mais aussi les plus intimidants au premier abord. Ce projet te montre comment :

- **Déclarer et utiliser** des pointeurs vers des fonctions
- **Passer des fonctions** comme arguments à d'autres fonctions
- **Créer des callbacks** pour exécuter du code conditionnel
- **Implémenter des patterns** comme le pattern Strategy ou Observer
- **Construire une calculatrice modulaire** avec function pointers et structures

**Après ce projet, tu comprendras pourquoi les function pointers sont essentiels dans le C ! 💪**

---

## 🎓 Objectifs d'apprentissage

À la fin de ce projet, tu seras capable de :

✅ **Déclarer** un pointeur vers une fonction  
✅ **Pointer vers** une fonction et l'appeler via le pointeur  
✅ **Passer des fonctions** comme arguments à d'autres fonctions (callbacks)  
✅ **Créer des fonctions génériques** qui acceptent différentes fonctions  
✅ **Utiliser les function pointers** avec des tableaux  
✅ **Combiner** function pointers et structures pour des patterns avancés  
✅ **Implémenter** une calculatrice modulaire avec switch sur function pointers  
✅ **Éviter** les pièges courants des pointeurs de fonction  
✅ **Comprendre** les avantages et les cas d'usage des function pointers  

---

## 💡 Concept fondamental

### Qu'est-ce qu'un pointeur de fonction ?

Un **pointeur de fonction** est une variable qui stocke l'adresse mémoire d'une fonction. C'est comme un pointeur normal, mais au lieu de pointer vers une donnée, il pointe vers du code.

### Analogie simple

```
Pointeur normal :        int *ptr = &variable;    // pointe vers une int
Pointeur de fonction :   void (*fptr)() = &fonction;  // pointe vers une fonction
```

### Pourquoi c'est utile ?

| Cas d'usage | Exemple |
|---|---|
| **Callbacks** | Appeler une fonction différente selon une condition |
| **Génériques** | Créer une fonction qui s'adapte à différentes opérations |
| **Patterns de design** | Strategy, Observer, Command patterns |
| **Plugins** | Charger du code dynamiquement |
| **Array de fonctions** | Dispatcher sur différentes fonctions |

---

## 🔧 Syntaxe et vocabulaire

### Déclarer un pointeur de fonction

**Syntaxe générale :**

```c
type_retour (*nom_pointeur)(type_param1, type_param2, ...);
```

**Exemples concrets :**

```c
// Pointeur vers une fonction qui retourne void et prend un char * en paramètre
void (*print_function)(char *);

// Pointeur vers une fonction qui retourne int et prend deux int
int (*operation)(int, int);

// Pointeur vers une fonction qui retourne int et prend un int
int (*callback)(int);

// Tableau de pointeurs vers des fonctions
void (*functions_array[])(int) = { func1, func2, func3 };
```

### Initialiser un pointeur de fonction

**Trois façons (équivalentes) :**

```c
// Manière 1 : avec l'adresse (& optionnel en C)
void (*fptr)(int) = &my_function;

// Manière 2 : sans l'adresse (C accepte implicitement)
void (*fptr)(int) = my_function;

// Manière 3 : assigner après la déclaration
void (*fptr)(int);
fptr = my_function;
```

### Appeler une fonction via un pointeur

**Trois façons (équivalentes) :**

```c
// Manière 1 : déréférence explicite
(*fptr)(argument);

// Manière 2 : syntaxe directe (C l'accepte)
fptr(argument);

// Manière 3 : avec le & optionnel
(*&fptr)(argument);  // Plus rare et inutile
```

---

## 📦 Projets du programme

### **Exercice 0 : Function Pointer - What's my name**

**Fichier :** `0-print_name.c`

**En-tête :** `function_pointers.h`

**Prototype :**
```c
void print_name(char *name, void (*f)(char *));
```

**Description :** Affiche un nom en utilisant une fonction passée en paramètre.

**Comportement :**
- Prend un `name` (chaîne de caractères) et un pointeur vers une fonction `f`
- La fonction `f` prend un `char *` en paramètre et retourne `void`
- Appelle `f` avec `name` en argument
- Si `name` ou `f` est `NULL`, ne fais rien

**Cas d'usage :** Passer différentes fonctions pour formater l'affichage du nom.

**Exemple :**

```c
void print_name_as_is(char *name)
{
	printf("Name: %s\n", name);
}

void print_name_uppercase(char *name)
{
	unsigned int i;
	
	printf("Name: ");
	i = 0;
	while (name[i])
	{
		if (name[i] >= 'a' && name[i] <= 'z')
			printf("%c", name[i] - 32);
		else
			printf("%c", name[i]);
		i++;
	}
	printf("\n");
}

int main(void)
{
	print_name("Bob", print_name_as_is);
	// Affiche: Name: Bob
	
	print_name("Bob", print_name_uppercase);
	// Affiche: Name: BOB
	
	return (0);
}
```

**Logique à implémenter :**

```c
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	
	f(name);
}
```

**Commandes/Fonctions utilisées :**
- Vérification `NULL`
- Appel de fonction via pointeur : `f(name);`
- Pas d'allocation mémoire (pas de `malloc`)

**Concepts clés :** Callback simple, fonction en paramètre, null checks

---

### **Exercice 1 : Array Iterator**

**Fichier :** `1-array_iterator.c`

**En-tête :** `function_pointers.h`

**Prototype :**
```c
void array_iterator(int *array, size_t size, void (*action)(int));
```

**Description :** Applique une fonction à chaque élément d'un tableau.

**Comportement :**
- `array` : pointeur vers un tableau d'entiers
- `size` : nombre d'éléments dans le tableau
- `action` : pointeur vers une fonction qui prend un `int` et retourne `void`
- Appelle `action` pour chaque élément du tableau dans l'ordre
- Si `array` ou `action` est `NULL`, ne fais rien

**Cas d'usage :** Pattern de programmation fonctionnelle (map/foreach).

**Exemple :**

```c
void print_element(int element)
{
	printf("%d\n", element);
}

void multiply_by_2(int element)
{
	printf("%d\n", element * 2);
}

void print_hex(int element)
{
	printf("0x%x\n", element);
}

int main(void)
{
	int tab[5] = {0, 98, 402, 1024, 4034};
	
	array_iterator(tab, 5, &print_element);
	// Affiche:
	// 0
	// 98
	// 402
	// 1024
	// 4034
	
	printf("\n--- Multiplied by 2 ---\n");
	array_iterator(tab, 5, &multiply_by_2);
	// Affiche:
	// 0
	// 196
	// 804
	// 2048
	// 8068
	
	printf("\n--- Hexadecimal ---\n");
	array_iterator(tab, 5, &print_hex);
	// Affiche:
	// 0x0
	// 0x62
	// 0x192
	// 0x400
	// 0xfbe
	
	return (0);
}
```

**Logique à implémenter :**

```c
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;
	
	if (array == NULL || action == NULL)
		return;
	
	i = 0;
	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
```

**Commandes/Fonctions utilisées :**
- Boucle `while` ou `for`
- `size_t` pour la taille (type non-signé)
- Appel de `action(array[i])`
- Vérifications `NULL`

**Concepts clés :** Pattern itérateur, fonction appliquée à tous les éléments

---

### **Exercice 2 : Int Index**

**Fichier :** `2-int_index.c`

**En-tête :** `function_pointers.h`

**Prototype :**
```c
int int_index(int *array, int size, int (*cmp)(int));
```

**Description :** Cherche le premier élément du tableau qui satisfait une fonction de comparaison.

**Comportement :**
- `array` : pointeur vers un tableau d'entiers
- `size` : nombre d'éléments (peut être négatif, considéré comme 0)
- `cmp` : pointeur vers une fonction qui prend un `int` et retourne `int`
  - Si la fonction retourne une valeur **non-nulle**, l'élément est "trouvé"
  - Si elle retourne `0`, continuer la recherche
- Retourne l'**index** du premier élément satisfaisant `cmp`
- Retourne `-1` si aucun élément ne satisfait ou si `array`/`cmp` est `NULL`

**Cas d'usage :** Recherche conditionnelle dans un tableau.

**Exemple :**

```c
int is_98(int element)
{
	return (element == 98);
}

int is_strictly_positive(int element)
{
	return (element > 0);
}

int is_divisible_by_2_and_gt_0(int element)
{
	return (element > 0 && element % 2 == 0);
}

int main(void)
{
	int tab[5] = {10, 9, 8, 7, 6};
	
	printf("Index of 98: %d\n", int_index(tab, 5, is_98));
	// Affiche: -1
	
	printf("Index of first positive: %d\n", int_index(tab, 5, is_strictly_positive));
	// Affiche: 0 (tab[0] = 10)
	
	printf("Index of first even and positive: %d\n", 
		   int_index(tab, 5, is_divisible_by_2_and_gt_0));
	// Affiche: 0 (tab[0] = 10)
	
	int tab2[4] = {0, -5, 3, 2};
	printf("Index (tab2): %d\n", int_index(tab2, 4, is_strictly_positive));
	// Affiche: 2 (tab2[2] = 3)
	
	return (0);
}
```

**Logique à implémenter :**

```c
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	
	if (array == NULL || cmp == NULL)
		return (-1);
	
	i = 0;
	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}
	
	return (-1);
}
```

**Commandes/Fonctions utilisées :**
- Boucle `while`
- Condition `if (cmp(array[i]) != 0)`
- Retour d'index ou `-1`
- Gestion du `size` négatif (implicite avec la condition `i < size`)

**Concepts clés :** Pattern de recherche, fonction de condition/prédicat

---

### **Exercice 3 : Calculatrice avec Function Pointers**

**Fichiers :** `3-main.c`, `3-op_functions.c`, `3-get_op_func.c`, `3-calc.h`

**Description :** Implémenter une calculatrice simple qui utilise function pointers et une structure pour dispatcher les opérations.

#### **3-calc.h - Structure et prototypes**

```c
#ifndef CALC_H
#define CALC_H

/**
 * struct op - Opération et sa fonction correspondante
 * @op: Le symbole de l'opération
 * @f: Pointeur vers la fonction
 */
typedef struct op
{
	char *op;
	int (*f)(int, int);
} op_t;

/* Prototypes */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif /* CALC_H */
```

#### **3-op_functions.c - Implémentation des opérations**

```c
#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

int op_add(int a, int b)
{
	return (a + b);
}

int op_sub(int a, int b)
{
	return (a - b);
}

int op_mul(int a, int b)
{
	return (a * b);
}

int op_div(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "Error: Division by zero\n");
		exit(100);
	}
	return (a / b);
}

int op_mod(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "Error: Division by zero\n");
		exit(100);
	}
	return (a % b);
}
```

**Logique :** Chaque fonction est une implémentation d'une opération mathématique simple.

**Commandes utilisées :** Retours, opérateurs arithmétiques, gestion des erreurs

---

#### **3-get_op_func.c - Dispatcher sur la bonne fonction**

```c
#include "3-calc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * get_op_func - Retourne la fonction correspondante à l'opération
 * @s: String de l'opération
 *
 * Return: Pointeur vers la fonction correspondante ou NULL
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
```

**Logique clé :**

```
1. Créer un tableau de structures op_t
2. Chaque structure contient :
   - op: le symbole ("+", "-", "*", etc.)
   - f: un pointeur vers la fonction correspondante
3. Boucler sur le tableau
4. Comparer s avec ops[i].op
5. Si égal, retourner ops[i].f (le pointeur vers la fonction)
6. Si aucune correspondance, retourner NULL
```

**Commandes utilisées :** `strcmp()`, tableau de structures, pointeurs de fonction, boucle

---

#### **3-main.c - Programme principal**

```c
#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

int main(int argc, char **argv)
{
	int a, b;
	char *op;
	int (*result)(int, int);

	if (argc != 4)
	{
		printf("Usage: ./calc num1 operator num2\n");
		exit(98);
	}

	a = atoi(argv[1]);
	op = argv[2];
	b = atoi(argv[3]);

	result = get_op_func(op);

	if (result == NULL)
	{
		printf("Error: invalid operator. Use: +, -, *, /, %%\n");
		exit(99);
	}

	printf("%d\n", result(a, b));

	return (0);
}
```

**Logique du programme :**

```
1. Vérifier qu'il y a exactement 4 arguments (programme + 3 params)
2. Convertir argv[1] en entier (premier nombre)
3. Stocker argv[2] (l'opération)
4. Convertir argv[3] en entier (deuxième nombre)
5. Appeler get_op_func(op) pour obtenir le pointeur vers la fonction
6. Vérifier que le pointeur n'est pas NULL
7. Appeler la fonction : result(a, b)
8. Afficher le résultat
```

**Exemple d'exécution :**

```bash
$ gcc 3-main.c 3-op_functions.c 3-get_op_func.c -o calc

$ ./calc 98 + 1024
1122

$ ./calc 1024 / 10
102

$ ./calc 1024 '%' 10
4

$ ./calc 1024 '-' 10
1014

$ ./calc 98 "?"
Error: invalid operator. Use: +, -, *, /, %
```

**Commandes utilisées :** `atoi()`, `strcmp()`, `printf()`, `exit()`, `argc`/`argv`

**Concepts clés :** Dispatcher pattern, array de structures, gestion d'erreurs

---

## 🔨 Compilation et tests

### Compiler chaque exercice

```bash
# Exercice 0
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-print_name.c -o 0-print_name

# Exercice 1
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-array_iterator.c -o 1-array_iterator

# Exercice 2
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-int_index.c -o 2-int_index

# Exercice 3 (Calculatrice)
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-op_functions.c 3-get_op_func.c -o calc
```

### Compiler avec tous les fichiers

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 *.c -o function_pointers_test
```

### Avec des flags avancés

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -D_GNU_SOURCE -fPIC -c *.c
```

### Vérifier avec Valgrind (pas de fuites mémoire)

```bash
valgrind --leak-check=full --show-leak-kinds=all ./calc 100 '+' 200
```

**Résultat attendu :**
```
All heap blocks were freed -- no leaks are possible
```

---

## ⚠️ Pièges courants

### ❌ Piège 1 : Oublier les parenthèses dans la déclaration

```c
// ❌ FAUX - déclare une fonction, pas un pointeur
void (*f)(int);  // ✅ C'est correct
void *f(int);    // ❌ C'est une fonction qui retourne void*

// ❌ FAUX
void f*(int);    // Syntaxe incorrecte
```

**Solution :**
```c
// ✅ CORRECT
void (*fptr)(int);  // Pointeur vers une fonction
```

---

### ❌ Piège 2 : Ne pas vérifier NULL

```c
// ❌ CRASH potentiel
void print_name(char *name, void (*f)(char *))
{
	f(name);  // Si f est NULL → SEGFAULT
}

// ✅ SÉCURISÉ
void print_name(char *name, void (*f)(char *))
{
	if (f == NULL)
		return;
	f(name);
}
```

---

### ❌ Piège 3 : Confondre appel direct et via pointeur

```c
void my_function(int x)
{
	printf("%d\n", x);
}

// Appel direct
my_function(42);  // ✅ Correct

// Via pointeur
void (*fptr)(int) = my_function;
(*fptr)(42);      // ✅ Correct
fptr(42);         // ✅ Aussi correct en C

// ❌ FAUX
*fptr(42);        // Déréférence le résultat, pas le pointeur
```

---

### ❌ Piège 4 : Mauvaise signature de fonction

```c
int add(int a, int b)
{
	return (a + b);
}

// ❌ FAUX - les signatures ne correspondent pas
int (*fptr)(char, char) = add;  // add prend 2 int, pas 2 char

// ✅ CORRECT - les signatures correspondent
int (*fptr)(int, int) = add;
```

---

### ❌ Piège 5 : Oublier & en passant le pointeur (rare mais possible)

```c
void process(void (*func)(int))
{
	func(42);
}

void my_func(int x)
{
	printf("%d\n", x);
}

// Les deux fonctionnent en C (conversion implicite)
process(my_func);      // ✅ OK
process(&my_func);     // ✅ OK aussi

// Mais en C++ strict, il faut le &
```

---

### ❌ Piège 6 : Division par zéro

```c
// ❌ FAUX - pas de vérification
int op_div(int a, int b)
{
	return (a / b);  // Si b == 0 → Erreur !
}

// ✅ CORRECT
int op_div(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "Error: Division by zero\n");
		exit(100);
	}
	return (a / b);
}
```

---

### ❌ Piège 7 : Retour incohérent de fonction

```c
// ❌ FAUX - on retourne NULL mais on attend int (*)(int, int)
int (*get_op_func(char *s))(int, int)
{
	// ...
	return (0);  // C'est un int, pas un pointeur !
}

// ✅ CORRECT
int (*get_op_func(char *s))(int, int)
{
	// ...
	return (NULL);  // C'est un pointeur NULL
}
```

---

## ✅ Bonnes pratiques

### 1. Toujours initialiser les pointeurs à NULL

```c
int (*fptr)(int) = NULL;

if (fptr != NULL)
	fptr(42);
```

### 2. Vérifier les paramètres NULL en début de fonction

```c
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || action == NULL)
		return;
	
	// Reste du code...
}
```

### 3. Utiliser des types de retour cohérents

```c
// ✅ BON - type clair
typedef int (*op_func_t)(int, int);

// Ou
int (*fptr)(int, int) = op_add;
```

### 4. Documenter les pointeurs de fonction

```c
/**
 * array_iterator - Applique une fonction à chaque élément
 * @array: Pointeur vers le tableau
 * @size: Nombre d'éléments
 * @action: Pointeur vers la fonction à appliquer
 *          La fonction prend un int et retourne void
 */
void array_iterator(int *array, size_t size, void (*action)(int));
```

### 5. Utiliser des structures pour les tableaux de fonctions

```c
// ❌ Confus
void (*funcs[5])(int);

// ✅ Clair
typedef struct
{
	char *name;
	void (*function)(int);
} operation_t;

operation_t operations[5] = {
	{"print", print_element},
	{"double", multiply_by_2},
};
```

### 6. Tester NULL avant d'appeler

```c
int (*cmp)(int) = get_op_func(op);

if (cmp == NULL)
{
	printf("Error: invalid operator\n");
	return;
}

printf("%d\n", cmp(a, b));
```

### 7. Utiliser des flags de compilation stricts

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o program
```

### 8. Compiler sans warnings

```bash
# Vérifier qu'il n'y a aucun warning
gcc -Wconversion -Wshadow -Wunreachable-code *.c -o program
```

---

## 📚 Résumé des concepts

### Déclaration et initialisation

| Cas | Syntaxe | Exemple |
|---|---|---|
| Pointer simple | `type (*name)(params);` | `int (*fptr)(int);` |
| Initialiser | `(*fptr) = function;` | `fptr = my_func;` |
| Appeler | `(*fptr)(args);` ou `fptr(args);` | `(*fptr)(42);` |
| Tableau | `type (*array[n])(params);` | `int (*ops[5])(int);` |
| Struct | `typedef struct { fn_ptr f; }` | `op_t` |

### Patterns courants

#### Pattern 1 : Callback simple

```c
void execute_with_callback(void (*callback)(int))
{
	if (callback == NULL)
		return;
	callback(42);
}
```

#### Pattern 2 : Dispatcher sur fonction

```c
int (*get_operation(char *op))(int, int)
{
	if (strcmp(op, "+") == 0)
		return (op_add);
	if (strcmp(op, "-") == 0)
		return (op_sub);
	return (NULL);
}
```

#### Pattern 3 : Array de callbacks

```c
void (*handlers[3])(int) = {
	print_element,
	multiply_by_2,
	print_hex
};

for (int i = 0; i < 3; i++)
	handlers[i](42);
```

#### Pattern 4 : Struct + function pointer array

```c
typedef struct
{
	char *name;
	int (*func)(int, int);
} operation_t;

operation_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{NULL, NULL}
};
```

---

## 🔍 Cas d'usage réels

### 1. Gestionnaire de signaux

```c
#include <signal.h>

void signal_handler(int sig)
{
	printf("Signal %d reçu\n", sig);
}

int main(void)
{
	signal(SIGINT, signal_handler);
	// ...
}
```

### 2. Callbacks pour la gestion d'événements

```c
void on_button_click(void (*callback)(void))
{
	if (callback)
		callback();
}
```

### 3. Fonctions génériques de tri

```c
int compare_ascending(int a, int b) { return (a - b); }
int compare_descending(int a, int b) { return (b - a); }

void sort_with_comparator(int *array, int size, 
						  int (*cmp)(int, int))
{
	// Utiliser cmp pour trier
}
```

---

## 📖 Ressources

### Documentation officielle

-