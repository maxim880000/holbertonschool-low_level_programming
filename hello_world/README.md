
# Projet : hello_world

Bienvenue dans le dossier **hello_world** du projet Holberton School !

## Sommaire

1. [Présentation](#présentation)
2. [Liste des fichiers](#liste-des-fichiers)
3. [Explications détaillées](#explications-détaillées)
4. [Commandes utilisées](#commandes-utilisées)
5. [Auteur](#auteur)

---

## Présentation

Ce dossier contient les premiers exercices de programmation en langage C. L'objectif est de se familiariser avec la compilation, l'édition de liens, le préprocesseur, l'assembleur, et l'écriture de programmes simples en C.

---

## Liste des fichiers

| Fichier         | Description |
|-----------------|-------------|
| 0-preprocessor  | Script bash : lance le préprocesseur C |
| 1-compiler      | Script bash : compile le code C en fichier objet (.o) |
| 2-assembler     | Script bash : génère le code assembleur (.s) |
| 3-name          | Script bash : compile et nomme l'exécutable |
| 4-puts.c        | Programme C : affiche une phrase avec puts |
| 5-printf.c      | Programme C : affiche une phrase avec printf |
| 6-size.c        | Programme C : affiche la taille des types |
| main.c          | Programme C : affiche "Hello, World!" |
| main.s          | Code assembleur généré |
| c               | Fichier généré par le préprocesseur |
| cisfun          | Exécutable généré |

---

## Explications détaillées

### 0-preprocessor
Script bash qui exécute le préprocesseur C sur le fichier contenu dans la variable d'environnement `$CFILE` :
```bash
gcc -E "$CFILE" -o c
```
- `-E` : exécute uniquement le préprocesseur (remplace les macros, inclut les headers, etc.)
- `-o c` : écrit le résultat dans le fichier `c`.

### 1-compiler
Script bash qui compile le fichier C en fichier objet :
```bash
gcc -c "$CFILE"
```
- `-c` : compile sans lier, produit un fichier `.o`.

### 2-assembler
Script bash qui génère le code assembleur :
```bash
gcc -S "$CFILE"
```
- `-S` : génère un fichier assembleur `.s`.

### 3-name
Script bash qui compile et crée un exécutable nommé `cisfun` :
```bash
gcc "$CFILE" -o cisfun
```
- `-o cisfun` : nomme l'exécutable généré.

### 4-puts.c
Programme C qui affiche une phrase avec la fonction `puts` :
```c
#include <stdio.h>

int main(void)
{
	puts("\"Programming is like building a multilingual puzzle");
	return (0);
}
```
- Utilise `puts` pour afficher une chaîne de caractères.

### 5-printf.c
Programme C qui affiche une phrase avec la fonction `printf` :
```c
#include <stdio.h>

int main(void)
{
	printf("with proper grammar, but the outcome is a piece of art,\n");
	return (0);
}
```
- Utilise `printf` pour afficher une chaîne formatée.

### 6-size.c
Programme C qui affiche la taille de différents types de données :
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
- Utilise `sizeof` pour obtenir la taille des types.

### main.c
Programme C qui affiche "Hello, World!" :
```c
#include <stdio.h>

int main(void)
{
	puts("Hello, World!");
	return (0);
}
```

### main.s
Fichier assembleur généré par la commande `gcc -S main.c`.

### c
Fichier généré par le préprocesseur (texte intermédiaire).

### cisfun
Exécutable généré par la compilation.

---

## Commandes utilisées

- **gcc** : compilateur C utilisé pour toutes les étapes (préprocessing, compilation, assemblage, édition de liens).
- **puts** : fonction standard C pour afficher une chaîne de caractères.
- **printf** : fonction standard C pour afficher du texte formaté.
- **sizeof** : opérateur C pour obtenir la taille d'un type.

---

## Auteur

- [maxim880000](https://github.com/maxim880000)

---

*Projet réalisé dans le cadre du cursus Holberton School.*
