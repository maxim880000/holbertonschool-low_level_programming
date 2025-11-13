![C - argc/argv](https://image.noelshack.com/fichiers/2025/46/4/1763039033-gemini-generated-image-nrt3smnrt3smnrt3.jpg)

# ⚙️ argv & argc - Langage C ⚙️

> **Analyse complète et détaillée du fonctionnement de `argc` et `argv` en C. On dissèque le fonctionnement en examinant les fonctions, bibliothèques et logiques de chaque programme Holberton School.**

---

## 🎯 Les Concepts Fondamentaux

### 🔢 `int argc` (Argument Count)

Un **compteur** qui indique le nombre total d'arguments passés au programme.

- **Propriété clé** : Sa valeur est **toujours ≥ 1**, car `argv[0]` (le nom du programme) est toujours inclus
- `argc` compte TOUT : le nom du programme + tous les arguments

#### Fonctionnement Détaillé :

Quand vous lancez un programme en ligne de commande :
```bash
./program arg1 arg2 arg3
```

Le système d'exploitation **divise** cette commande en **arguments séparés** et les envoie au programme :

1. **Premier argument (argv[0])** = le nom du programme lui-même (`./program`)
2. **Deuxième argument (argv[1])** = `arg1`
3. **Troisième argument (argv[2])** = `arg2`
4. **Quatrième argument (argv[3])** = `arg3`

Et `argc` compte tout cela : **argc = 4**

#### Comment ça marche dans le code :

```c
int main(int argc, char *argv[])
{
    // argc reçoit le nombre d'arguments automatiquement
    // C'est le système d'exploitation qui passe cette valeur
}
```

---

### 📜 `char *argv[]` (Argument Vector)

Un **tableau de pointeurs vers des chaînes de caractères** contenant tous les arguments.

- `argv` = **tableau** (collection d'éléments)
- `char *` = **pointeur vers une chaîne de caractères**
- `argv[]` = chaque case du tableau contient un pointeur vers une chaîne

#### Structure Détaillée :

```
argv[0] ──→ "./program"  (pointeur vers la chaîne "program")
argv[1] ──→ "arg1"       (pointeur vers la chaîne "arg1")
argv[2] ──→ "arg2"       (pointeur vers la chaîne "arg2")
argv[3] ──→ "arg3"       (pointeur vers la chaîne "arg3")
argv[4] ──→ NULL         (fin du tableau - toujours NULL)
```

#### Pourquoi des pointeurs ?

En C, les chaînes de caractères sont des **tableaux de caractères** :

```c
argv[0] est un pointeur vers :  './','p','r','o','g','r','a','m','\0'
                                  ↑
                             début de la chaîne
```

Chaque chaîne se termine par `'\0'` (caractère nul), qui marque la fin.

#### Accéder aux éléments :

```c
printf("%s\n", argv[0]);        // Affiche toute la chaîne
printf("%c\n", argv[0][0]);     // Affiche le 1er caractère ('.')
printf("%c\n", argv[0][1]);     // Affiche le 2e caractère ('/')
printf("%c\n", argv[0][2]);     // Affiche le 3e caractère ('p')
```

---

## 🚀 Logique de Travail - Étape par Étape

### Comment le Système d'Exploitation Envoie les Arguments

**Étape 1 : Vous tapez la commande**
```bash
$ ./3-mul 5 10
```

**Étape 2 : Le système d'exploitation divise cette chaîne**
```
Chaîne complète : "./3-mul 5 10"
        ↓ (division par les espaces)
Arguments séparés :
- "./3-mul"
- "5"
- "10"
```

**Étape 3 : Le système crée un tableau avec ces arguments**
```
argc = 3
argv[0] = "./3-mul"
argv[1] = "5"
argv[2] = "10"
argv[3] = NULL (toujours à la fin)
```

**Étape 4 : Le système appelle votre fonction main()**
```c
int main(int argc, char *argv[])
// argc reçoit 3
// argv reçoit l'adresse du tableau
```

---

### Flux d'Exécution Complet

```
┌─────────────────────────────────────────────────┐
│  Commande : ./program hello world               │
└─────────────────────────────────────────────────┘
                      ↓
┌─────────────────────────────────────────────────┐
│  Système d'exploitation parse la commande       │
│  • Trouve les espaces                           │
│  • Divise en arguments                          │
│  • Crée le tableau argv[]                       │
└─────────────────────────────────────────────────┘
                      ↓
┌─────────────────────────────────────────────────┐
│  Tableau créé en mémoire :                      │
│  argv[0] = "./program"                          │
│  argv[1] = "hello"                              │
│  argv[2] = "world"                              │
│  argv[3] = NULL                                 │
│  argc = 3                                       │
└─────────────────────────────────────────────────┘
                      ↓
┌─────────────────────────────────────────────────┐
│  main() est appelée avec argc et argv            │
│  Le programme reçoit ces valeurs                │
│  et peut les utiliser                           │
└─────────────────────────────────────────────────┘
```

---

## 🚀 Analyse Détaillée des Programmes

### 📄 0-whatsmyname.c

**Mission** 🎯 : Afficher le nom du programme

#### Code :
```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%s\n", argv[0]);
    (void)argc;
    return (0);
}
```

#### Logique de Travail Détaillée :

**Étape 1 : Réception des arguments**
```
Le système d'exploitation envoie :
- argc = 1 (juste le nom du programme)
- argv[0] = "./0-whatsmyname"
```

**Étape 2 : Accès à argv[0]**
```c
argv[0]  // C'est un pointeur vers la chaîne "./0-whatsmyname"
```

**Étape 3 : printf() affiche la chaîne**
```c
printf("%s\n", argv[0]);
// %s = formateur pour chaîne de caractères
// \n = saut de ligne
```

**Étape 4 : Suppression du warning**
```c
(void)argc;  // argc n'est pas utilisée, donc on la "cast" en void
             // Cela dit au compilateur : "J'ai volontairement ignoré argc"
```

#### Résultat :
```bash
$ ./0-whatsmyname
./0-whatsmyname

$ /path/to/0-whatsmyname
/path/to/0-whatsmyname
```

---

### 📄 1-args.c

**Mission** 🎯 : Afficher le nombre d'arguments utiles (sans le nom du programme)

#### Code :
```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d\n", argc - 1);
    (void)argv;
    return (0);
}
```

#### Logique de Travail Détaillée :

**Étape 1 : Réception des arguments**
```bash
$ ./1-args hello world secret
```

Le système envoie :
```
argc = 4  (./1-args, hello, world, secret)
argv[0] = "./1-args"
argv[1] = "hello"
argv[2] = "world"
argv[3] = "secret"
argv[4] = NULL
```

**Étape 2 : Calcul du nombre d'arguments utiles**
```
argc - 1 = 4 - 1 = 3

Pourquoi ? Parce qu'on exclut argv[0] (le nom du programme)
Les arguments "utiles" sont : hello, world, secret = 3 arguments
```

**Étape 3 : Affichage**
```c
printf("%d\n", argc - 1);
// %d = formateur pour entier
// \n = saut de ligne
```

#### Résultat :
```bash
$ ./1-args hello world secret
3
```

---

### 📄 2-args.c

**Mission** 🎯 : Afficher tous les arguments, un par ligne

#### Code :
```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
    return (0);
}
```

#### Logique de Travail Détaillée :

**Étape 1 : Réception des arguments**
```bash
$ ./2-args hello world
```

Le système envoie :
```
argc = 3
argv[0] = "./2-args"
argv[1] = "hello"
argv[2] = "world"
argv[3] = NULL
```

**Étape 2 : Boucle FOR - Itération 1**
```
i = 0
Condition : 0 < 3 ? OUI
Exécution : printf("%s\n", argv[0])
Résultat : affiche "./2-args"
i++ → i devient 1
```

**Étape 3 : Boucle FOR - Itération 2**
```
i = 1
Condition : 1 < 3 ? OUI
Exécution : printf("%s\n", argv[1])
Résultat : affiche "hello"
i++ → i devient 2
```

**Étape 4 : Boucle FOR - Itération 3**
```
i = 2
Condition : 2 < 3 ? OUI
Exécution : printf("%s\n", argv[2])
Résultat : affiche "world"
i++ → i devient 3
```

**Étape 5 : Boucle FOR - Vérification finale**
```
i = 3
Condition : 3 < 3 ? NON
Sortie de la boucle
```

#### Résultat :
```bash
$ ./2-args hello world
./2-args
hello
world
```

---

### 📄 3-mul.c

**Mission** 🎯 : Multiplier deux nombres passés en argument

#### Code :
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b;

    if (argc != 3)
    {
        printf("Error\n");
        return (1);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("%d\n", a * b);
    return (0);
}
```

#### Logique de Travail Détaillée :

**Scénario 1 : Utilisation correcte**
```bash
$ ./3-mul 5 10
```

**Étape 1 : Réception des arguments**
```
argc = 3
argv[0] = "./3-mul"
argv[1] = "5"       ← pointeur vers la chaîne "5"
argv[2] = "10"      ← pointeur vers la chaîne "10"
argv[3] = NULL
```

**Étape 2 : Validation - Vérifier argc**
```c
if (argc != 3)  // argc est 3, donc la condition est FAUSSE
                // On n'entre pas dans le if, on continue
```

**Étape 3 : Conversion de chaîne en nombre avec atoi()**
```c
a = atoi(argv[1]);
// argv[1] pointe vers "5"
// atoi() lit la chaîne "5" et la convertit en nombre entier 5
// a reçoit la valeur 5

b = atoi(argv[2]);
// argv[2] pointe vers "10"
// atoi() lit la chaîne "10" et la convertit en nombre entier 10
// b reçoit la valeur 10
```

**Étape 4 : Calcul et affichage**
```c
printf("%d\n", a * b);
// a * b = 5 * 10 = 50
// Affiche : 50
```

**Résultat** :
```bash
$ ./3-mul 5 10
50
```

---

**Scénario 2 : Mauvais nombre d'arguments**
```bash
$ ./3-mul 5
```

**Étape 1 : Réception des arguments**
```
argc = 2  ← seulement 2 arguments au lieu de 3
argv[0] = "./3-mul"
argv[1] = "5"
argv[2] = NULL
```

**Étape 2 : Validation - Vérifier argc**
```c
if (argc != 3)  // argc est 2, donc la condition est VRAIE
                // On entre dans le if
{
    printf("Error\n");  // Affiche "Error"
    return (1);         // Quitte le programme avec code d'erreur 1
}
```

**Résultat** :
```bash
$ ./3-mul 5
Error
```

#### Nouvelles Fonctions :
- **`atoi()`** = **A**SCII **To** **I**nteger : convertit une chaîne en nombre
  - `atoi("42")` → `42` (nombre entier)
  - `atoi("hello")` → `0` (pas de chiffres au début)
  - `atoi("123abc")` → `123` (lit jusqu'au premier non-chiffre)

---

### 📄 4-add.c

**Mission** 🎯 : Additionner tous les nombres passés en arguments

#### Code :
```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int i, j, sum = 0;

    if (argc == 1)
    {
        printf("0\n");
        return (0);
    }
    for (i = 1; i < argc; i++)
    {
        for (j = 0; argv[i][j] != '\0'; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                printf("Error\n");
                return (1);
            }
        }
        sum += atoi(argv[i]);
    }
    printf("%d\n", sum);
    return (0);
}
```

#### Logique de Travail Détaillée :

**Scénario 1 : Utilisation correcte**
```bash
$ ./4-add 5 10 15
```

**Étape 1 : Réception des arguments**
```
argc = 4
argv[0] = "./4-add"
argv[1] = "5"
argv[2] = "10"
argv[3] = "15"
argv[4] = NULL
sum = 0 (initialisé)
```

**Étape 2 : Vérifier si argc == 1**
```c
if (argc == 1)  // argc est 4, donc FAUX
                // On passe à la suite
```

**Étape 3 : Boucle principale - VALIDATION DOUBLE BOUCLE**

**Itération i = 1 :**
```
Première boucle interne (j) - Vérifier les caractères de argv[1] ("5")

j = 0
argv[1][0] = '5' (le caractère '5')
isdigit('5') ? OUI - c'est un chiffre ✓
j = 1
argv[1][1] = '\0' (fin de la chaîne)
Condition : argv[1][1] != '\0' ? NON
Sortie de la boucle interne

Tout est validé, on fait l'addition :
sum += atoi(argv[1])
sum = 0 + atoi("5") = 0 + 5 = 5
```

**Itération i = 2 :**
```
Première boucle interne (j) - Vérifier les caractères de argv[2] ("10")

j = 0
argv[2][0] = '1'
isdigit('1') ? OUI ✓
j = 1
argv[2][1] = '0'
isdigit('0') ? OUI ✓
j = 2
argv[2][2] = '\0' (fin)
Condition : argv[2][2] != '\0' ? NON
Sortie de la boucle interne

Tout est validé :
sum += atoi(argv[2])
sum = 5 + atoi("10") = 5 + 10 = 15
```

**Itération i = 3 :**
```
Même logique pour argv[3] ("15")

sum += atoi(argv[3])
sum = 15 + atoi("15") = 15 + 15 = 30
```

**Étape 4 : Sortie de la boucle principale**
```c
i = 4
Condition : 4 < 4 ? NON
Sortie de la boucle
```

**Étape 5 : Affichage du résultat**
```c
printf("%d\n", sum);  // Affiche 30
```

**Résultat** :
```bash
$ ./4-add 5 10 15
30
```

---

**Scénario 2 : Avec un caractère invalide**
```bash
$ ./4-add 5 hello 15
```

**Étape 1 : Réception des arguments**
```
argc = 4
argv[0] = "./4-add"
argv[1] = "5"
argv[2] = "hello"  ← contient des lettres
argv[3] = "15"
sum = 0
```

**Étape 2 : Validation des arguments**

**Itération i = 1 :**
```
argv[1] = "5"
j = 0
argv[1][0] = '5'
isdigit('5') ? OUI ✓
Pas d'erreur, validation réussie
sum = 5
```

**Itération i = 2 :**
```
argv[2] = "hello"

j = 0
argv[2][0] = 'h' (le caractère 'h')
isdigit('h') ? NON - ce n'est PAS un chiffre ✗

Le programme entre dans le if :
if (!isdigit(argv[2][0]))  // true (le ! inverse NON → true)
{
    printf("Error\n");     // Affiche "Error"
    return (1);            // Quitte le programme
}
```

**Résultat** :
```bash
$ ./4-add 5 hello 15
Error
```

#### Concepts Avancés :
- **`isdigit()`** = teste si un caractère est un chiffre (0-9)
- **`!`** = NON logique (inverse le résultat) : `!true` = `false`, `!false` = `true`
- **`argv[i][j]`** = accès aux caractères d'une chaîne (double indexation)
- **`'\0'`** = caractère nul (fin d'une chaîne en C)
- **Boucles imbriquées** = une boucle dans une boucle pour valider chaque caractère

---

### 📄 100-change.c (BONUS)

**Mission** 🎯 : Rendre la monnaie avec le minimum de pièces (Algorithme Glouton)

#### Code :
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int cents, count = 0;

    if (argc != 2)
    {
        printf("Error\n");
        return (1);
    }
    cents = atoi(argv[1]);
    if (cents < 0)
    {
        printf("0\n");
        return (0);
    }
    count += cents / 25;        // Pièces de 25 cents
    cents = cents % 25;
    count += cents / 10;        // Pièces de 10 cents
    cents = cents % 10;
    count += cents / 5;         // Pièces de 5 cents
    cents = cents % 5;
    count += cents / 2;         // Pièces de 2 cents
    cents = cents % 2;
    count += cents;             // Pièces de 1 cent
    printf("%d\n", count);
    return (0);
}
```

#### Logique de Travail Détaillée :

**Scénario : Convertir 41 cents**
```bash
$ ./100-change 41
```

**Étape 1 : Réception des arguments**
```
argc = 2
argv[0] = "./100-change"
argv[1] = "41"
cents = atoi("41") = 41
count = 0
```

**Étape 2 : Vérification argc et validité**
```c
if (argc != 2)      // argc est 2, donc FAUX
if (cents < 0)      // cents est 41, donc FAUX
// On continue
```

**Étape 3 : Algorithme Glouton - Pièces de 25 cents**
```
count += cents / 25
// 41 / 25 = 1 (division entière)
// count = 0 + 1 = 1

cents = cents % 25
// 41 % 25 = 16 (reste de la division)
// cents = 16

État : count = 1, cents = 16
Pièces : [25]
```

**Étape 4 : Pièces de 10 cents**
```
count += cents / 10
// 16 / 10 = 1
// count = 1 + 1 = 2

cents = cents % 10
// 16 % 10 = 6
// cents = 6

État : count = 2, cents = 6
Pièces : [25, 10]
```

**Étape 5 : Pièces de 5 cents**
```
count += cents / 5
// 6 / 5 = 1
// count = 2 + 1 = 3

cents = cents % 5
// 6 % 5 = 1
// cents = 1

État : count = 3, cents = 1
Pièces : [25, 10, 5]
```

**Étape 6 : Pièces de 2 cents**
```
count += cents / 2
// 1 / 2 = 0
// count = 3 + 0 = 3

cents = cents % 2
// 1 % 2 = 1
// cents = 1

État : count = 3, cents = 1
Pièces : [25, 10, 5]
```

**Étape 7 : Pièces de 1 cent**
```
count += cents
// count = 3 + 1 = 4

État final : count = 4, cents = 0
Pièces : [25, 10, 5, 1]
```

**Étape 8 : Affichage**
```c
printf("%d\n", count);  // Affiche 4
```

**Résultat** :
```bash
$ ./100-change 41
4

// Explication : 25 + 10 + 5 + 1 = 41 avec 4 pièces (le minimum)
```

#### Opérateurs Utilisés :
- **`/`** = division entière (quotient) : `41 / 25 = 1`
- **`%`** = modulo (reste de la division) : `41 % 25 = 16`

#### Logique (Algorithme Glouton) :
L'algorithme glouton ("greedy") prend toujours la **plus grosse pièce possible**, puis calcule le reste avec les pièces suivantes. C'est le moyen le plus efficace de rendre la monnaie.

---

## 💡 Astuces & Erreurs Courantes

### ⚠️ Erreur #1 : Oublier que argc compte le nom du programme

```bash
./program arg1 arg2
```

- ❌ FAUX : `argc = 2`
- ✅ CORRECT : `argc = 3` (program, arg1, arg2)

**Pourquoi ?** Le système d'exploitation compte TOUJOURS `argv[0]` dans `argc`.

---

### ⚠️ Erreur #2 : Accéder à argv[argc]

`argv[argc]` est TOUJOURS NULL. Ne pas essayer d'afficher cette valeur !

```c
// ❌ DANGER : Segmentation Fault!
printf("%s\n", argv[argc]);
// Pourquoi ? argv[argc] pointe vers NULL, et %s essaie de lire à partir de NULL
// C'est une adresse invalide → crash du programme
```

---

### ⚠️ Erreur #3 : atoi() ne valide pas

```c
atoi("123abc")  // Renvoie 123, pas une erreur !
atoi("hello")   // Renvoie 0
atoi("")        // Renvoie 0
```

**Solution** : Utiliser `isdigit()` pour valider chaque caractère avant de convertir.

---

### ✅ Astuce #1 : (void) pour ignorer une variable

Si vous n'utilisez pas une variable, le compilateur vous avertit. Utilisez `(void)` :

```c
(void)argc;  // Dit au compilateur : "C'est intentionnel, j'ignore cette variable"
```

---

### ✅ Astuce #2 : return (0) vs return (1)

- `return (0)` = succès (le programme s'est bien passé)
- `return (1)` = erreur (quelque chose s'est mal passé)
- `return (2)` ou plus = d'autres codes d'erreur personnalisés

Le code de retour est utilisé par le système d'exploitation et d'autres programmes pour savoir si le vôtre a réussi.

---

### ✅ Astuce #3 : Boucler correctement sur argv

```c
// Option 1 : Avec argc (recommandé)
for (i = 0; i < argc; i++)
    printf("%s\n", argv[i]);

// Option 2 : Avec NULL (aussi valide)
for (i = 0; argv[i] != NULL; i++)
    printf("%s\n", argv[i]);
```

Les deux méthodes fonctionnent, mais utiliser `argc` est plus courant.

---

### ✅ Astuce #4 : Vérifier les arguments avant de les utiliser

```c
if (argc < 3)
{
    printf("Usage: %s <arg1> <arg2>\n", argv[0]);
    return (1);
}
```

Toujours **valider le nombre d'arguments** avant de les utiliser pour éviter les crashes.

---

### ✅ Astuce #5 : Comprendre la différence entre argv[i] et argv[i][j]

```c
argv[i]      // Pointe vers la chaîne complète
printf("%s", argv[i]);   // Affiche toute la chaîne

argv[i][j]   // Pointe vers un caractère spécifique
printf("%c", argv[i][j]); // Affiche un seul caractère
```

---

## 🔥 Cas Réel d'Utilisation

### Exemple 1 : Script de Compilation

```bash
$ gcc -Wall -Wextra -g program.c -o program

argc = 6
argv[0] = "gcc"
argv[1] = "-Wall"
argv[2] = "-Wextra"
argv[3] = "-g"
argv[4] = "program.c"
argv[5] = "-o"
argv[6] = "program"
```

---

### Exemple 2 : Ligne de Commande Classique

```bash
$ ls -la /home/user/documents

argc = 4
argv[0] = "ls"
argv[1] = "-la"         (option)
argv[2] = "/home/user/documents"  (argument)
```

---

### Exemple 3 : Recherche dans des Fichiers

```bash
$ grep "hello" file1.txt file2.txt file3.txt

argc = 5
argv[0] = "grep"
argv[1] = "hello"       (ce qu'on cherche)
argv[2] = "file1.txt"   (premier fichier)
argv[3] = "file2.txt"   (deuxième fichier)
argv[4] = "file3.txt"   (troisième fichier)
```

---

## 📋 Résumé Rapide

| Concept | Signification | Exemple |
|---------|---------------|---------|
| `argc` | Nombre total d'arguments | `argc = 3` pour `./prog arg1 arg2` |
| `argv[0]` | Nom du programme | `"./prog"` ou `"prog"` |
| `argv[1]` | 1er argument | `"arg1"` |
| `argv[i]` | i-ème argument | `argv[2]` = `"arg2"` |
| `argv[i][j]` | j-ème caractère de argv[i] | `argv[1][0]` = 1er caractère de arg1 |
| `argv[argc]` | ⚠️ TOUJOURS NULL | Ne pas utiliser ! |
| `atoi()` | Convertir texte → nombre | `atoi("42")` = `42` |
| `isdigit()` | Vérifier si c'est un chiffre | `isdigit('5')` = `1` (vrai) |
| `return (0)` | Succès | Le programme a marché |
| `return (1)` | Erreur | Il y a eu un problème |

---

## 📚 Bibliothèques Utilisées

- **`<stdio.h>`** :