# 🌍 Hello, World - Introduction au Langage C

# Projet : hello_world

<p align="center">

  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>Bienvenue dans le dossier **hello_world** du projet Holberton School !

  <img src="https://img.shields.io/badge/Level-Débutant-green?style=for-the-badge" alt="Débutant"/>

</p>## Sommaire



---1. [Présentation](#présentation)

2. [Liste des fichiers](#liste-des-fichiers)

## 📖 Table des matières3. [Explications détaillées](#explications-détaillées)

4. [Commandes utilisées](#commandes-utilisées)

1. [Description](#-description)5. [Auteur](#auteur)

2. [Objectifs pédagogiques](#-objectifs-pédagogiques)

3. [La chaîne de compilation](#-la-chaîne-de-compilation)---

4. [Fichiers du projet](#-fichiers-du-projet)

5. [Compilation et exécution](#-compilation-et-exécution)## Présentation

6. [Concepts clés](#-concepts-clés)

7. [Ressources](#-ressources)Ce dossier contient les premiers exercices de programmation en langage C. L'objectif est de se familiariser avec la compilation, l'édition de liens, le préprocesseur, l'assembleur, et l'écriture de programmes simples en C.



------



## 📝 Description## Liste des fichiers



Ce projet est le **premier contact avec le langage C**. Il introduit les concepts fondamentaux de la programmation en C ainsi que le processus de compilation. Vous apprendrez comment un fichier source `.c` est transformé en programme exécutable à travers plusieurs étapes.| Fichier         | Description |

|-----------------|-------------|

Le projet couvre également les fonctions de sortie standard (`puts`, `printf`, `putchar`) et l'importance de comprendre les types de données et leurs tailles en mémoire.| 0-preprocessor  | Script bash : lance le préprocesseur C |

| 1-compiler      | Script bash : compile le code C en fichier objet (.o) |

---| 2-assembler     | Script bash : génère le code assembleur (.s) |

| 3-name          | Script bash : compile et nomme l'exécutable |

## 🎯 Objectifs pédagogiques| 4-puts.c        | Programme C : affiche une phrase avec puts |

| 5-printf.c      | Programme C : affiche une phrase avec printf |

À la fin de ce projet, vous serez capable de :| 6-size.c        | Programme C : affiche la taille des types |

| main.c          | Programme C : affiche "Hello, World!" |

- ✅ Expliquer pourquoi le C est considéré comme un langage "proche de la machine"| main.s          | Code assembleur généré |

- ✅ Comprendre les 4 étapes de la compilation (préprocesseur, compilation, assemblage, édition de liens)| c               | Fichier généré par le préprocesseur |

- ✅ Utiliser `gcc` avec différentes options| cisfun          | Exécutable généré |

- ✅ Utiliser les fonctions `puts()`, `printf()` et `putchar()`

- ✅ Comprendre la fonction `main()` et son rôle de point d'entrée---

- ✅ Utiliser `sizeof` pour connaître la taille des types

## Explications détaillées

---

### 0-preprocessor

## ⚙️ La chaîne de compilationScript bash qui exécute le préprocesseur C sur le fichier contenu dans la variable d'environnement `$CFILE` :

```bash

La compilation en C se déroule en **4 étapes distinctes** :gcc -E "$CFILE" -o c

```

```- `-E` : exécute uniquement le préprocesseur (remplace les macros, inclut les headers, etc.)

┌─────────────┐     ┌─────────────┐     ┌─────────────┐     ┌─────────────┐- `-o c` : écrit le résultat dans le fichier `c`.

│   Source    │     │ Préprocessé │     │ Assembleur  │     │   Objet     │     ┌─────────────┐

│   main.c    │ ──► │     main.i  │ ──► │   main.s    │ ──► │   main.o    │ ──► │ Exécutable  │### 1-compiler

│             │     │             │     │             │     │             │     │    a.out    │Script bash qui compile le fichier C en fichier objet :

└─────────────┘     └─────────────┘     └─────────────┘     └─────────────┘     └─────────────┘```bash

       │                   │                   │                   │                   │gcc -c "$CFILE"

    Étape 1            Étape 2             Étape 3             Étape 4```

  Préprocesseur       Compilateur        Assembleur          Linker- `-c` : compile sans lier, produit un fichier `.o`.

    gcc -E             gcc -S              gcc -c              gcc

```### 2-assembler

Script bash qui génère le code assembleur :

### Étape 1 : Préprocesseur (`gcc -E`)```bash

- Traite les directives `#include`, `#define`, `#ifdef`gcc -S "$CFILE"

- Supprime les commentaires```

- Produit un fichier `.i`- `-S` : génère un fichier assembleur `.s`.



### Étape 2 : Compilation (`gcc -S`)### 3-name

- Traduit le code C en langage assembleurScript bash qui compile et crée un exécutable nommé `cisfun` :

- Produit un fichier `.s````bash

gcc "$CFILE" -o cisfun

### Étape 3 : Assemblage (`gcc -c`)```

- Traduit l'assembleur en code machine (binaire)- `-o cisfun` : nomme l'exécutable généré.

- Produit un fichier objet `.o`

### 4-puts.c

### Étape 4 : Édition de liens (Linking)Programme C qui affiche une phrase avec la fonction `puts` :

- Lie les fichiers objets avec les bibliothèques```c

- Produit l'exécutable final#include <stdio.h>



---int main(void)

{

## 📂 Fichiers du projet	puts("\"Programming is like building a multilingual puzzle");

	return (0);

| Fichier | Description | Commande/Concept |}

|---------|-------------|------------------|```

| `0-preprocessor` | Script qui exécute le préprocesseur sur `$CFILE` | `gcc -E` |- Utilise `puts` pour afficher une chaîne de caractères.

| `1-compiler` | Script qui compile `$CFILE` sans lier | `gcc -c` |

| `2-assembler` | Script qui génère le code assembleur | `gcc -S` |### 5-printf.c

| `3-name` | Script qui compile et crée l'exécutable `cisfun` | `gcc -o` |Programme C qui affiche une phrase avec la fonction `printf` :

| `4-puts.c` | Programme utilisant `puts()` | Affichage de chaînes |```c

| `5-printf.c` | Programme utilisant `printf()` | Affichage formaté |#include <stdio.h>

| `6-size.c` | Programme affichant la taille des types | `sizeof()` |

int main(void)

---{

	printf("with proper grammar, but the outcome is a piece of art,\n");

## 📄 Détail des fichiers	return (0);

}

### 0-preprocessor```

```bash- Utilise `printf` pour afficher une chaîne formatée.

#!/bin/bash

gcc -E "$CFILE" -o c### 6-size.c

```Programme C qui affiche la taille de différents types de données :

**Explication** : Exécute uniquement le préprocesseur sur le fichier contenu dans `$CFILE` et écrit le résultat dans un fichier nommé `c`.```c

#include <stdio.h>

---

int main(void)

### 1-compiler{

```bash	printf("Size of a char: %zu byte(s)\n", sizeof(char));

#!/bin/bash	printf("Size of an int: %zu byte(s)\n", sizeof(int));

gcc -c "$CFILE"	printf("Size of a long int: %zu byte(s)\n", sizeof(long int));

```	printf("Size of a long long int: %zu byte(s)\n", sizeof(long long int));

**Explication** : Compile le fichier source sans faire l'édition de liens. Génère un fichier objet `.o`.	printf("Size of a float: %zu byte(s)\n", sizeof(float));

	return (0);

---}

```

### 2-assembler- Utilise `sizeof` pour obtenir la taille des types.

```bash

#!/bin/bash### main.c

gcc -S "$CFILE"Programme C qui affiche "Hello, World!" :

``````c

**Explication** : Génère le code assembleur à partir du fichier source. Crée un fichier `.s`.#include <stdio.h>



---int main(void)

{

### 3-name	puts("Hello, World!");

```bash	return (0);

#!/bin/bash}

gcc "$CFILE" -o cisfun```

```

**Explication** : Compile le fichier source et crée un exécutable nommé `cisfun`.### main.s

Fichier assembleur généré par la commande `gcc -S main.c`.

---

### c

### 4-puts.cFichier généré par le préprocesseur (texte intermédiaire).

```c

#include <stdio.h>### cisfun

Exécutable généré par la compilation.

int main(void)

{---

    puts("\"Programming is like building a multilingual puzzle");

    return (0);## Commandes utilisées

}

```- **gcc** : compilateur C utilisé pour toutes les étapes (préprocessing, compilation, assemblage, édition de liens).

**Explication** : Utilise `puts()` pour afficher une chaîne de caractères suivie d'un retour à la ligne automatique.- **puts** : fonction standard C pour afficher une chaîne de caractères.

- **printf** : fonction standard C pour afficher du texte formaté.

**Différence `puts` vs `printf`** :- **sizeof** : opérateur C pour obtenir la taille d'un type.

- `puts()` : ajoute automatiquement `\n` à la fin

- `printf()` : n'ajoute pas de `\n` automatiquement---



---## Auteur



### 5-printf.c- [maxim880000](https://github.com/maxim880000)

```c

#include <stdio.h>---



int main(void)*Projet réalisé dans le cadre du cursus Holberton School.*

{
    printf("with proper grammar, but the outcome is a piece of art,\n");
    return (0);
}
```
**Explication** : Utilise `printf()` pour un affichage formaté. Le `\n` doit être ajouté manuellement.

---

### 6-size.c
```c
#include <stdio.h>

int main(void)
{
    printf("Size of a char: %zu byte(s)\n", sizeof(char));
    printf("Size of an int: %zu byte(s)\n", sizeof(int));
    printf("Size of a long int: %zu byte(s)\n", sizeof(long int));
    printf("Size of a long long int: %zu byte(s)\n", sizeof(long long int));
    printf("Size of a float: %zu byte(s)\n", sizeof(float));
    return (0);
}
```
**Explication** : Affiche la taille en octets de différents types de données.

**Résultat typique (architecture 64 bits)** :
```
Size of a char: 1 byte(s)
Size of an int: 4 byte(s)
Size of a long int: 8 byte(s)
Size of a long long int: 8 byte(s)
Size of a float: 4 byte(s)
```

---

## 🔧 Compilation et exécution

### Utiliser les scripts
```bash
# Définir la variable d'environnement
export CFILE=main.c

# Exécuter le préprocesseur
./0-preprocessor

# Compiler en fichier objet
./1-compiler

# Générer l'assembleur
./2-assembler

# Créer l'exécutable
./3-name
```

### Compiler les fichiers .c directement
```bash
# Compiler avec les flags Holberton
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-puts.c -o puts_program
./puts_program

# Compiler 6-size.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 6-size.c -o size_program
./size_program
```

---

## 💡 Concepts clés

### La fonction `main()`
- Point d'entrée de tout programme C
- Signature standard : `int main(void)` ou `int main(int argc, char **argv)`
- Retourne `0` pour indiquer un succès

### Les types de données primitifs

| Type | Taille (octets) | Plage de valeurs |
|------|-----------------|------------------|
| `char` | 1 | -128 à 127 |
| `int` | 4 | -2,147,483,648 à 2,147,483,647 |
| `long` | 8 | Très grande plage |
| `float` | 4 | ~6 chiffres significatifs |
| `double` | 8 | ~15 chiffres significatifs |

### Le spécificateur `%zu`
- Utilisé avec `printf()` pour afficher des valeurs de type `size_t`
- `size_t` est le type retourné par `sizeof()`

---

## 📚 Ressources

- [Manuel GCC](https://gcc.gnu.org/onlinedocs/)
- [C Reference - cppreference.com](https://en.cppreference.com/w/c)
- [The C Programming Language - K&R](https://en.wikipedia.org/wiki/The_C_Programming_Language)

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus **Holberton School**.

---

<p align="center">
  <i>« Hello, World! » - Le premier programme de tout développeur.</i>
</p>
