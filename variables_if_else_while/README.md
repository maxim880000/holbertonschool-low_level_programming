# 🔀 Variables, If, Else, While - Structures de contrôle en C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Débutant-green?style=for-the-badge" alt="Débutant"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Concepts clés](#-concepts-clés)
4. [Fichiers du projet](#-fichiers-du-projet)
5. [Détail des fichiers](#-détail-des-fichiers)
6. [Compilation et exécution](#-compilation-et-exécution)
7. [Ressources](#-ressources)

---

## 📝 Description

Ce projet introduit les **structures de contrôle fondamentales** en langage C : les variables, les conditions (`if`, `else if`, `else`) et les boucles (`while`, `for`). Ces concepts sont la base de toute logique algorithmique et permettent de contrôler le flux d'exécution d'un programme.

Vous apprendrez également à utiliser la génération de nombres aléatoires avec `srand()` et `rand()`, ainsi que la manipulation de caractères via la table ASCII.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Déclarer et utiliser des variables de différents types
- ✅ Utiliser les opérateurs arithmétiques, logiques et relationnels
- ✅ Utiliser les structures conditionnelles `if`, `else if`, `else`
- ✅ Utiliser les boucles `while` et `for`
- ✅ Utiliser `putchar` pour afficher des caractères
- ✅ Comprendre la table ASCII et manipuler les caractères
- ✅ Générer des nombres aléatoires avec `srand()` et `rand()`

---

## 💡 Concepts clés

### Les variables en C

Une variable est un espace mémoire nommé qui stocke une valeur.

```c
int age = 25;           /* Entier */
char letter = 'A';      /* Caractère */
float price = 19.99;    /* Nombre à virgule */
```

### Les opérateurs

| Type | Opérateurs | Exemple |
|------|------------|---------|
| Arithmétiques | `+`, `-`, `*`, `/`, `%` | `a + b`, `10 % 3` |
| Relationnels | `==`, `!=`, `<`, `>`, `<=`, `>=` | `a == b` |
| Logiques | `&&`, `\|\|`, `!` | `a && b` |
| Affectation | `=`, `+=`, `-=`, `*=`, `/=` | `a += 5` |

### Les structures conditionnelles

```c
if (condition)
{
    /* Exécuté si condition est vraie */
}
else if (autre_condition)
{
    /* Exécuté si autre_condition est vraie */
}
else
{
    /* Exécuté sinon */
}
```

### Les boucles

#### Boucle `while`
```c
while (condition)
{
    /* Répété tant que condition est vraie */
}
```

#### Boucle `for`
```c
for (initialisation; condition; incrémentation)
{
    /* Répété tant que condition est vraie */
}
```

### La table ASCII

Les caractères sont représentés par des nombres. Par exemple :
- `'a'` = 97, `'z'` = 122
- `'A'` = 65, `'Z'` = 90
- `'0'` = 48, `'9'` = 57

```c
char c = 'a';
putchar(c);      /* Affiche 'a' */
putchar(c + 1);  /* Affiche 'b' */
```

### Génération de nombres aléatoires

```c
#include <stdlib.h>
#include <time.h>

srand(time(0));              /* Initialise le générateur */
int n = rand();              /* Génère un nombre aléatoire */
int n_range = rand() % 100;  /* Nombre entre 0 et 99 */
```

---

## 📂 Fichiers du projet

| Fichier | Description |
|---------|-------------|
| `0-positive_or_negative.c` | Détermine si un nombre aléatoire est positif, négatif ou nul |
| `1-last_digit.c` | Affiche le dernier chiffre d'un nombre aléatoire |
| `2-print_alphabet.c` | Affiche l'alphabet en minuscules |
| `3-print_alphabets.c` | Affiche l'alphabet en minuscules puis en majuscules |
| `4-print_alphabt.c` | Affiche l'alphabet sauf 'q' et 'e' |
| `5-print_numbers.c` | Affiche les chiffres de 0 à 9 |
| `6-print_numberz.c` | Affiche les chiffres de 0 à 9 avec `putchar` uniquement |
| `7-print_tebahpla.c` | Affiche l'alphabet en minuscules à l'envers |
| `8-print_base16.c` | Affiche les chiffres hexadécimaux (0-9 et a-f) |
| `9-print_comb.c` | Affiche toutes les combinaisons de chiffres uniques |

---

## 📄 Détail des fichiers

### 0-positive_or_negative.c

```c
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;

    if (n > 0)
        printf("%d is positive\n", n);
    else if (n == 0)
        printf("%d is zero\n", n);
    else
        printf("%d is negative\n", n);

    return (0);
}
```

**Explication** :
- `srand(time(0))` : initialise le générateur aléatoire avec le temps actuel
- `rand() - RAND_MAX / 2` : génère un nombre qui peut être positif ou négatif
- Structure `if/else if/else` pour tester les 3 cas

---

### 1-last_digit.c

```c
int main(void)
{
    int n, last_digit;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    last_digit = n % 10;  /* Modulo pour extraire le dernier chiffre */

    printf("Last digit of %d is %d ", n, last_digit);

    if (last_digit > 5)
        printf("and is greater than 5\n");
    else if (last_digit == 0)
        printf("and is 0\n");
    else
        printf("and is less than 6 and not 0\n");

    return (0);
}
```

**Explication** :
- L'opérateur `%` (modulo) retourne le reste de la division
- `n % 10` donne toujours le dernier chiffre d'un nombre

---

### 2-print_alphabet.c

```c
int main(void)
{
    char letter;

    for (letter = 'a'; letter <= 'z'; letter++)
        putchar(letter);

    putchar('\n');
    return (0);
}
```

**Explication** :
- On utilise le fait que les lettres sont consécutives dans la table ASCII
- `letter++` passe à la lettre suivante

**Sortie** : `abcdefghijklmnopqrstuvwxyz`

---

### 4-print_alphabt.c

```c
int main(void)
{
    char letter;

    for (letter = 'a'; letter <= 'z'; letter++)
    {
        if (letter != 'e' && letter != 'q')
            putchar(letter);
    }
    putchar('\n');
    return (0);
}
```

**Explication** : Utilise l'opérateur logique `&&` pour exclure 'e' et 'q'.

---

### 6-print_numberz.c

```c
int main(void)
{
    int n;

    for (n = 0; n < 10; n++)
        putchar(n + '0');  /* Convertit le chiffre en caractère ASCII */

    putchar('\n');
    return (0);
}
```

**Explication** :
- `'0'` vaut 48 en ASCII
- `n + '0'` convertit un entier (0-9) en son caractère correspondant
- `0 + '0'` = 48 = `'0'`, `1 + '0'` = 49 = `'1'`, etc.

---

### 8-print_base16.c

```c
int main(void)
{
    int n;
    char letter;

    /* Affiche 0-9 */
    for (n = 0; n < 10; n++)
        putchar(n + '0');

    /* Affiche a-f */
    for (letter = 'a'; letter <= 'f'; letter++)
        putchar(letter);

    putchar('\n');
    return (0);
}
```

**Explication** : Affiche les 16 symboles de la base hexadécimale.

**Sortie** : `0123456789abcdef`

---

### 9-print_comb.c

```c
int main(void)
{
    int n;

    for (n = 0; n < 10; n++)
    {
        putchar(n + '0');
        if (n != 9)
        {
            putchar(',');
            putchar(' ');
        }
    }
    putchar('\n');
    return (0);
}
```

**Explication** :
- Affiche les chiffres séparés par `, `
- La condition `n != 9` évite la virgule après le dernier chiffre

**Sortie** : `0, 1, 2, 3, 4, 5, 6, 7, 8, 9`

---

## 🔧 Compilation et exécution

```bash
# Compiler un fichier
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-positive_or_negative.c -o positive

# Exécuter
./positive

# Exécuter plusieurs fois pour voir différents résultats
./positive
./positive
./positive
```

---

## 📊 Diagramme de flux - Structure if/else

```
        ┌─────────────────┐
        │     Début       │
        └────────┬────────┘
                 │
        ┌────────▼────────┐
        │   Condition ?   │
        └────────┬────────┘
                 │
        ┌────────┴────────┐
        │                 │
   ┌────▼────┐       ┌────▼────┐
   │  VRAI   │       │  FAUX   │
   │ (bloc   │       │ (else)  │
   │   if)   │       │         │
   └────┬────┘       └────┬────┘
        │                 │
        └────────┬────────┘
                 │
        ┌────────▼────────┐
        │      Fin        │
        └─────────────────┘
```

---

## 📚 Ressources

- [ASCII Table](https://www.asciitable.com/)
- [C Operators - GeeksforGeeks](https://www.geeksforgeeks.org/operators-in-c/)
- [Control Flow - cppreference](https://en.cppreference.com/w/c/language/statements)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« La logique vous mènera de A à B. L'imagination vous mènera partout. »</i><br>
  — Albert Einstein
</p>
