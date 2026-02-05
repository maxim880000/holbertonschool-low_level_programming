# 🎯 Pointers, Arrays & Strings - Le cœur du langage C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Level-Intermédiaire-orange?style=for-the-badge" alt="Intermédiaire"/>
</p>

---

## 📖 Table des matières

1. [Description](#-description)
2. [Objectifs pédagogiques](#-objectifs-pédagogiques)
3. [Les pointeurs expliqués](#-les-pointeurs-expliqués)
4. [Les tableaux en C](#-les-tableaux-en-c)
5. [Les chaînes de caractères](#-les-chaînes-de-caractères)
6. [Manipulation mémoire](#-manipulation-mémoire)
7. [Fichiers du projet](#-fichiers-du-projet)
8. [Détail des fichiers](#-détail-des-fichiers)
9. [Compilation et exécution](#-compilation-et-exécution)
10. [Ressources](#-ressources)

---

## 📝 Description

Ce projet est **fondamental** dans l'apprentissage du C. Les pointeurs, les tableaux et les chaînes de caractères sont les piliers de la programmation bas niveau. Comprendre ces concepts est essentiel pour :

- Manipuler efficacement la mémoire
- Créer des structures de données complexes
- Interagir avec le système d'exploitation
- Écrire du code performant

Ce directory regroupe plusieurs projets sur ces thèmes, avec des exercices allant de la manipulation basique aux fonctions de la bibliothèque standard.

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, vous serez capable de :

- ✅ Comprendre ce qu'est un **pointeur** et comment l'utiliser
- ✅ Utiliser les opérateurs `&` (adresse) et `*` (déréférencement)
- ✅ Comprendre la relation entre **tableaux et pointeurs**
- ✅ Manipuler des **chaînes de caractères**
- ✅ Implémenter des fonctions de la **libc** (`strlen`, `strcpy`, `strcat`, etc.)
- ✅ Utiliser les fonctions de manipulation **mémoire** (`memset`, `memcpy`)
- ✅ Comprendre l'**arithmétique des pointeurs**

---

## 🔍 Les pointeurs expliqués

### Qu'est-ce qu'un pointeur ?

Un **pointeur** est une variable qui contient l'**adresse mémoire** d'une autre variable.

```
┌─────────────────────────────────────────────────────────┐
│                    MÉMOIRE RAM                          │
├─────────────────────────────────────────────────────────┤
│  Adresse  │  Contenu   │  Variable                      │
├───────────┼────────────┼────────────────────────────────┤
│  0x1000   │    42      │  int n = 42;                   │
│  0x1004   │  0x1000    │  int *ptr = &n;                │
└───────────┴────────────┴────────────────────────────────┘

      n          ptr
    ┌────┐     ┌────────┐
    │ 42 │ ◄── │ 0x1000 │
    └────┘     └────────┘
    0x1000       0x1004
```

### Les opérateurs essentiels

| Opérateur | Nom | Description | Exemple |
|-----------|-----|-------------|---------|
| `&` | Adresse de | Retourne l'adresse d'une variable | `&n` → `0x1000` |
| `*` | Déréférencement | Accède à la valeur pointée | `*ptr` → `42` |

### Exemple pratique

```c
int n = 42;
int *ptr = &n;    /* ptr contient l'adresse de n */

printf("n = %d\n", n);           /* 42 */
printf("&n = %p\n", &n);         /* 0x1000 (exemple) */
printf("ptr = %p\n", ptr);       /* 0x1000 */
printf("*ptr = %d\n", *ptr);     /* 42 */

*ptr = 100;       /* Modifie n via le pointeur */
printf("n = %d\n", n);           /* 100 */
```

### Pourquoi utiliser des pointeurs ?

1. **Modifier une variable dans une fonction**
2. **Éviter de copier de grandes quantités de données**
3. **Allouer de la mémoire dynamiquement**
4. **Créer des structures de données complexes**

---

## 📊 Les tableaux en C

### Déclaration et initialisation

```c
int arr[5] = {10, 20, 30, 40, 50};

/* En mémoire :
   arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
   ┌────┐  ┌────┐  ┌────┐  ┌────┐  ┌────┐
   │ 10 │  │ 20 │  │ 30 │  │ 40 │  │ 50 │
   └────┘  └────┘  └────┘  └────┘  └────┘
   0x100   0x104   0x108   0x10C   0x110
*/
```

### Relation tableau-pointeur

Le nom d'un tableau est un **pointeur vers son premier élément** :

```c
int arr[5] = {10, 20, 30, 40, 50};

arr      == &arr[0]    /* Même adresse */
*arr     == arr[0]     /* Même valeur (10) */
*(arr+1) == arr[1]     /* 20 */
*(arr+i) == arr[i]     /* Équivalence générale */
```

### Arithmétique des pointeurs

```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;

p + 1    /* Pointe vers arr[1] (avance de sizeof(int) = 4 octets) */
p + 2    /* Pointe vers arr[2] */
p[3]     /* Équivalent à *(p + 3) = arr[3] = 40 */
```

---

## 📜 Les chaînes de caractères

### Représentation en mémoire

Une chaîne en C est un **tableau de `char` terminé par `\0`** (caractère nul).

```c
char str[] = "Hello";

/* En mémoire :
   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   │ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │ '\0'│
   └─────┴─────┴─────┴─────┴─────┴─────┘
     [0]   [1]   [2]   [3]   [4]   [5]
     72    101   108   108   111    0    (ASCII)
*/
```

### Déclaration de chaînes

```c
char str1[] = "Hello";        /* Tableau modifiable */
char *str2 = "Hello";         /* Pointeur vers constante (non modifiable) */
char str3[10] = "Hello";      /* Tableau avec espace supplémentaire */
```

### Parcours d'une chaîne

```c
/* Méthode 1 : avec index */
int i = 0;
while (str[i] != '\0')
{
    printf("%c", str[i]);
    i++;
}

/* Méthode 2 : avec pointeur */
char *p = str;
while (*p != '\0')
{
    printf("%c", *p);
    p++;
}
```

---

## 💾 Manipulation mémoire

### memset - Remplir une zone mémoire

```c
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;

    return (s);
}
```

**Usage** : `_memset(buffer, 'X', 10);` → Remplit les 10 premiers octets avec 'X'

### memcpy - Copier une zone mémoire

```c
char *_memcpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];

    return (dest);
}
```

---

## 📂 Fichiers du projet

### Manipulation de base

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-reset_to_98.c` | Modifie une valeur via pointeur | `void reset_to_98(int *n)` |
| `1-swap.c` | Échange deux entiers | `void swap_int(int *a, int *b)` |
| `2-strlen.c` | Longueur d'une chaîne | `int _strlen(char *s)` |
| `3-puts.c` | Affiche une chaîne | `void _puts(char *str)` |
| `4-print_rev.c` | Affiche une chaîne à l'envers | `void print_rev(char *s)` |
| `5-rev_string.c` | Inverse une chaîne en place | `void rev_string(char *s)` |

### Fonctions de chaînes (style libc)

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-strcat.c` | Concatène deux chaînes | `char *_strcat(char *dest, char *src)` |
| `1-strncat.c` | Concatène n caractères | `char *_strncat(char *dest, char *src, int n)` |
| `2-strncpy.c` | Copie n caractères | `char *_strncpy(char *dest, char *src, int n)` |
| `3-strcmp.c` | Compare deux chaînes | `int _strcmp(char *s1, char *s2)` |
| `9-strcpy.c` | Copie une chaîne | `char *_strcpy(char *dest, char *src)` |

### Fonctions avancées

| Fichier | Description | Prototype |
|---------|-------------|-----------|
| `0-memset.c` | Remplit une zone mémoire | `char *_memset(char *s, char b, unsigned int n)` |
| `1-memcpy.c` | Copie une zone mémoire | `char *_memcpy(char *dest, char *src, unsigned int n)` |
| `2-strchr.c` | Cherche un caractère | `char *_strchr(char *s, char c)` |
| `3-strspn.c` | Longueur du préfixe | `unsigned int _strspn(char *s, char *accept)` |
| `4-strpbrk.c` | Cherche un caractère parmi | `char *_strpbrk(char *s, char *accept)` |
| `5-strstr.c` | Cherche une sous-chaîne | `char *_strstr(char *haystack, char *needle)` |
| `100-atoi.c` | Convertit chaîne → entier | `int _atoi(char *s)` |
| `7-leet.c` | Encode en leet speak | `char *leet(char *str)` |

---

## 📄 Détail des fichiers

### 0-reset_to_98.c

```c
void reset_to_98(int *n)
{
    *n = 98;
}
```

**Explication** : Le pointeur `n` permet de modifier la variable originale.

```c
int x = 42;
reset_to_98(&x);  /* x vaut maintenant 98 */
```

---

### 1-swap.c

```c
void swap_int(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
```

**Visualisation** :
```
Avant:  a → 10    b → 20
        temp = *a = 10
        *a = *b → a = 20
        *b = temp → b = 10
Après:  a → 20    b → 10
```

---

### 2-strlen.c

```c
int _strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')
        i++;

    return (i);
}
```

**Explication** : Compte les caractères jusqu'au terminateur `\0`.

---

### 5-rev_string.c

```c
void rev_string(char *s)
{
    int start = 0;
    int end = 0;
    char temp;

    /* Trouver la fin de la chaîne */
    while (s[end] != '\0')
        end++;
    end--;

    /* Échanger les caractères */
    while (start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
}
```

**Technique des deux pointeurs** :
```
"Hello" → start=0, end=4
Étape 1: "oellH" → swap H et o
Étape 2: "olleH" → swap e et l
Résultat: "olleH"
```

---

### 0-strcat.c

```c
char *_strcat(char *dest, char *src)
{
    int l_dest = 0;
    int l_src = 0;

    /* Trouver la fin de dest */
    while (dest[l_dest] != '\0')
        l_dest++;

    /* Copier src à la fin de dest */
    while (src[l_src] != '\0')
    {
        dest[l_dest] = src[l_src];
        l_dest++;
        l_src++;
    }

    dest[l_dest] = '\0';
    return (dest);
}
```

**Visualisation** :
```
dest: "Hello"     src: " World"
      H e l l o \0         W o r l d \0

Résultat: "Hello World"
          H e l l o   W o r l d \0
```

---

### 100-atoi.c

```c
int _atoi(char *s)
{
    int i = 0;
    int sign = 1;
    unsigned int result = 0;
    int number_found = 0;

    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            number_found = 1;
            result = (result * 10) + (s[i] - '0');
        }
        else if (number_found == 1)
            break;
        else if (s[i] == '-')
            sign *= -1;

        i++;
    }

    return (result * sign);
}
```

**Conversion chiffre → entier** :
- `'5' - '0'` = `53 - 48` = `5` (valeur numérique)
- `result * 10 + nouveau_chiffre` → construit le nombre

---

### 7-leet.c

```c
char *leet(char *str)
{
    int a, b;
    char letters[] = "aAeEoOtTlL";
    char codes[] = "4433007711";

    for (a = 0; str[a] != '\0'; a++)
    {
        for (b = 0; letters[b] != '\0'; b++)
        {
            if (str[a] == letters[b])
            {
                str[a] = codes[b];
                break;
            }
        }
    }
    return (str);
}
```

**Correspondances leet** :
```
a/A → 4    e/E → 3    o/O → 0    t/T → 7    l/L → 1
```

**Exemple** : `"Hello"` → `"H3110"`

---

## 🔧 Compilation et exécution

```bash
# Compiler un fichier avec un main de test
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-strlen.c -o strlen_test
./strlen_test

# Compiler strcat
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-strcat.c -o strcat_test
./strcat_test
```

---

## 📊 Diagramme - Pointeurs et mémoire

```
┌─────────────────────────────────────────────────────────────────┐
│                         STACK (Pile)                            │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│   ┌─────────────┐                                               │
│   │ int n = 42  │ ← Variable locale                             │
│   │ Addr: 0x100 │                                               │
│   └─────────────┘                                               │
│         ▲                                                       │
│         │ (pointe vers)                                         │
│   ┌─────────────┐                                               │
│   │ int *p      │ ← Pointeur                                    │
│   │ Val: 0x100  │                                               │
│   │ Addr: 0x108 │                                               │
│   └─────────────┘                                               │
│                                                                 │
│   *p = 42       (déréférencement : accède à la valeur)          │
│   &n = 0x100    (adresse de n)                                  │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

## 💡 Pièges courants

| Piège | Description | Solution |
|-------|-------------|----------|
| Pointeur non initialisé | `int *p; *p = 5;` → Crash ! | Toujours initialiser |
| Oublier `\0` | Copie de chaîne sans terminateur | Toujours ajouter `\0` |
| Buffer overflow | Écrire au-delà de la taille | Vérifier les limites |
| Modifier une constante | `char *s = "hello"; s[0] = 'H';` | Utiliser `char s[]` |

---

## 📚 Ressources

- [Pointers in C - GeeksforGeeks](https://www.geeksforgeeks.org/pointers-in-c-and-c-set-1-introduction-arithmetic-and-array/)
- [String functions - cppreference](https://en.cppreference.com/w/c/string/byte)
- [Memory manipulation - tutorialspoint](https://www.tutorialspoint.com/c_standard_library/string_h.htm)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Comprendre les pointeurs, c'est comprendre le C. »</i>
</p>
