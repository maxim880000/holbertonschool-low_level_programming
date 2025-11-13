<p align="center">
  <a href="https://github.com/maxim880000/holbertonschool-low_level_programming/tree/main/functions_nested_loops" rel="noopener">
 <img width=300px height=300px src="https://image.noelshack.com/fichiers/2025/46/4/1763044561-unnamed.jpg" alt="Fonctions et Nested Loops"></a>
</p>

<h3 align="center">🔄 Fonctions & Nested Loops - C Programming</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Repository](https://img.shields.io/badge/github-maxim880000-blue.svg)](https://github.com/maxim880000/holbertonschool-low_level_programming/tree/main/functions_nested_loops)
[![Language](https://img.shields.io/badge/language-C-green.svg)]()
[![School](https://img.shields.io/badge/school-Holberton-red.svg)]()

</div>

---

<p align="center"> 
Projet Holberton School - Maîtriser les fonctions, les boucles imbriquées et la manipulation de chaînes en C.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Détails des Programmes](#détails-des-programmes)
- [Logique & Explications](#logique--explications)
- [Commandes Utilisées](#commandes-utilisées)
- [Résumé Rapide](#résumé-rapide)
- [Auteur](#auteur)

---

## 🧐 About <a name = "about"></a>

Ce projet couvre **les fonctions et les boucles imbriquées en C**, deux concepts fondamentaux pour tout programmeur. L'objectif est de :

- **Créer et utiliser des fonctions** réutilisables
- **Maîtriser les boucles imbriquées** (boucle dans une boucle)
- **Comprendre le flux d'exécution** et la portée des variables
- **Manipuler des chaînes de caractères** et des nombres
- **Écrire un code propre et lisible** avec une bonne logique

Chaque programme résout un problème spécifique en utilisant des fonctions et/ou des boucles imbriquées, montrant comment les combiner efficacement.

---

## 🚀 Détails des Programmes

### 📄 0-putchar.c

**Objectif** : Créer et utiliser une fonction simple

**Logique de travail** :

1. **Définition de la fonction** `_putchar()` :
   - C'est une fonction qui affiche UN SEUL caractère
   - Elle utilise `write()` pour écrire directement sur la sortie standard
   - `write(1, &c, 1)` = écrit le caractère c à la position 1 (stdout)

2. **Dans la fonction main()** :
   - On appelle `_putchar()` 10 fois dans une boucle
   - À chaque appel, on envoie un caractère différent : 'H', 'o', 'l', 'b', 'e', 'r', 't', 'o', 'n', '\n'
   - Les caractères s'affichent un par un jusqu'à former "Holberton"

**Résultat** :
```
Holberton
```

**Commandes utilisées** :
- `write()` : affiche des données
- Boucle `for` : répète l'affichage

---

### 📄 1-alphabet.c

**Objectif** : Afficher l'alphabet avec une fonction

**Logique de travail** :

1. **Création de la fonction** `print_alphabet()` :
   - Utilise une boucle `for` de 'a' à 'z'
   - À chaque itération : `_putchar(lettre)`
   - Quand `lettre = 'a'` → affiche 'a'
   - Quand `lettre = 'b'` → affiche 'b'
   - ... jusqu'à 'z'
   - À la fin : `_putchar('\n')` pour le saut de ligne

2. **Dans main()** :
   - Appelle simplement `print_alphabet()`
   - La fonction gère toute la logique

**Flux d'exécution** :
```
for (lettre = 'a'; lettre <= 'z'; lettre++)
  ↓
lettre = 'a' → _putchar('a') → affiche 'a'
lettre = 'b' → _putchar('b') → affiche 'b'
...
lettre = 'z' → _putchar('z') → affiche 'z'
_putchar('\n') → saut de ligne
```

**Résultat** :
```
abcdefghijklmnopqrstuvwxyz
```

**Commandes utilisées** :
- Fonction `print_alphabet()`
- Boucle `for` avec caractères
- Comparaison `lettre <= 'z'`

---

### 📄 2-print_alphabet_x10.c

**Objectif** : Afficher l'alphabet 10 fois

**Logique de travail** :

1. **Création de la fonction** `print_alphabet_x10()` :
   - Utilise une **boucle externe** : `for (i = 0; i < 10; i++)`
   - Cette boucle s'exécute 10 fois

2. **À l'intérieur de la boucle externe** :
   - **Boucle interne** : `for (lettre = 'a'; lettre <= 'z'; lettre++)`
   - Affiche tout l'alphabet à chaque itération de la boucle externe

3. **Boucles imbriquées** :
   ```
   Boucle externe (i = 0 à 9)
   ├─ Boucle interne (lettre = a à z)
   │  ├─ Affiche 'a'
   │  ├─ Affiche 'b'
   │  └─ ... jusqu'à 'z'
   ├─ Boucle interne (lettre = a à z)
   │  ├─ Affiche 'a'
   │  ├─ Affiche 'b'
   │  └─ ... jusqu'à 'z'
   └─ ... répète 10 fois
   ```

**Résultat** :
```
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
... (10 fois au total)
```

**Commandes utilisées** :
- **Boucles imbriquées** : une boucle dans une boucle
- Boucle `for` externe : contrôle le nombre de fois
- Boucle `for` interne : affiche l'alphabet

---

### 📄 3-islower.c

**Objectif** : Créer une fonction qui teste si une lettre est minuscule

**Logique de travail** :

1. **Fonction** `_islower(int c)` :
   - Prend un caractère en paramètre
   - Teste : est-ce que `c >= 'a'` ET `c <= 'z'` ?
   - Si OUI : retourne 1 (vrai)
   - Si NON : retourne 0 (faux)

2. **Condition logique** :
   ```c
   if (c >= 'a' && c <= 'z')
       return (1);  // C'est une minuscule
   else
       return (0);  // Ce n'est pas une minuscule
   ```

3. **Dans main()** :
   - Teste plusieurs caractères : 'a', 'z', 'A', 'Z', '5', etc.
   - Affiche le résultat (1 ou 0)

**Exemples** :
```
'a' → 1 (minuscule)
'z' → 1 (minuscule)
'A' → 0 (majuscule, pas minuscule)
'5' → 0 (chiffre, pas minuscule)
```

**Commandes utilisées** :
- Condition `if` avec opérateur logique `&&` (ET)
- Comparaison de caractères : `>= 'a'` et `<= 'z'`
- `return` : retourne une valeur

---

### 📄 4-isalpha.c

**Objectif** : Tester si un caractère est une lettre (minuscule OU majuscule)

**Logique de travail** :

1. **Fonction** `_isalpha(int c)` :
   - Teste : est-ce une minuscule OU une majuscule ?
   - Deux conditions à vérifier :
     - Minuscule : `c >= 'a' && c <= 'z'`
     - Majuscule : `c >= 'A' && c <= 'Z'`
   - Si l'UNE DE CES deux conditions est vraie → retourne 1
   - Sinon → retourne 0

2. **Condition logique avec OU** :
   ```c
   if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
       return (1);  // C'est une lettre
   else
       return (0);  // Ce n'est pas une lettre
   ```

3. **Opérateur `||` (OU logique)** :
   - `||` signifie "OU"
   - Si AU MOINS UNE condition est vraie, le résultat est vrai

**Exemples** :
```
'a' → 1 (lettre minuscule)
'Z' → 1 (lettre majuscule)
'5' → 0 (chiffre, pas une lettre)
'!' → 0 (symbole, pas une lettre)
```

**Commandes utilisées** :
- Opérateur logique `&&` (ET)
- Opérateur logique `||` (OU)
- Combinaison de conditions

---

### 📄 5-sign.c

**Objectif** : Retourner le signe d'un nombre

**Logique de travail** :

1. **Fonction** `print_sign(int n)` :
   - Prend un nombre en paramètre
   - Teste trois cas :
     - Si `n > 0` → affiche '+' et retourne 1
     - Si `n == 0` → affiche '0' et retourne 0
     - Si `n < 0` → affiche '-' et retourne -1

2. **Conditions imbriquées (if else if else)** :
   ```c
   if (n > 0)
       return (1);
   else if (n == 0)
       return (0);
   else
       return (-1);
   ```

3. **Trois résultats possibles** :
   - +1 pour positif
   - 0 pour zéro
   - -1 pour négatif

**Exemples** :
```
5 → affiche '+' → retourne 1
0 → affiche '0' → retourne 0
-3 → affiche '-' → retourne -1
```

**Commandes utilisées** :
- `if` `else if` `else` : conditions multiples
- Comparaison : `>`, `==`, `<`

---

### 📄 6-abs.c

**Objectif** : Calculer la valeur absolue d'un nombre

**Logique de travail** :

1. **Fonction** `_abs(int n)` :
   - Prend un nombre en paramètre
   - Si `n < 0` : retourne `-n` (le rendre positif)
   - Sinon : retourne `n` tel quel

2. **Logique** :
   ```c
   if (n < 0)
       return (-n);  // Change le signe
   else
       return (n);   // Garde le signe
   ```

3. **Exemples** :
   ```
   -5 → retourne -(-5) = 5
   10 → retourne 10
   0 → retourne 0
   ```

**Mathématiquement** :
- La valeur absolue de -5 est 5
- La valeur absolue de 5 est 5
- Toujours un nombre positif (ou 0)

**Commandes utilisées** :
- Condition `if` `else`
- Opérateur unaire `-` (change le signe)

---

### 📄 7-print_last_digit.c

**Objectif** : Afficher le dernier chiffre d'un nombre

**Logique de travail** :

1. **Fonction** `print_last_digit(int n)` :
   - Prend un nombre en paramètre
   - Récupère le dernier chiffre avec le modulo : `n % 10`
   - Affiche ce chiffre
   - Retourne le chiffre

2. **Opération modulo** :
   ```
   n = 1234
   n % 10 = 4  (le reste de la division par 10)
   
   n = -567
   n % 10 = 7  (dans ce programme, on en prend la valeur absolue)
   ```

3. **Pour gérer les nombres négatifs** :
   ```c
   n = _abs(n);        // On rend le nombre positif
   dernier_chiffre = n % 10;  // On récupère le dernier chiffre
   ```

**Exemples** :
```
1234 → dernier chiffre = 4
-567 → dernier chiffre = 7 (on prend la valeur absolue)
0 → dernier chiffre = 0
```

**Commandes utilisées** :
- Opérateur modulo `%`
- Fonction `_abs()` (définie précédemment)

---

### 📄 8-24_hours.c

**Objectif** : Afficher toutes les heures du jour (00:00 à 23:59)

**Logique de travail** :

1. **Fonction** `jack_bauer()` :
   - Affiche l'heure en format HH:MM de 00:00 à 23:59

2. **Boucles imbriquées** :
   - **Boucle externe** : les heures (0 à 23)
   - **Boucle interne** : les minutes (0 à 59)

3. **Flux d'exécution** :
   ```
   h = 0
   ├─ m = 0 → affiche "00:00"
   ├─ m = 1 → affiche "00:01"
   ├─ m = 2 → affiche "00:02"
   ├─ ... jusqu'à m = 59
   
   h = 1
   ├─ m = 0 → affiche "01:00"
   ├─ m = 1 → affiche "01:01"
   └─ ...
   
   h = 23
   ├─ m = 0 → affiche "23:00"
   ├─ ... jusqu'à m = 59 → affiche "23:59"
   ```

4. **Affichage du format HH:MM** :
   ```c
   printf("%02d:%02d\n", h, m);
   // %02d = affiche le nombre avec 2 chiffres minimum, complété par des zéros
   // "05" au lieu de "5"
   ```

**Résultat** :
```
00:00
00:01
00:02
...
23:58
23:59
```

**Commandes utilisées** :
- **Boucles imbriquées**
- `printf()` avec `%02d` (formateur avec zéro)
- Condition : `h < 24` et `m < 60`

---

### 📄 9-times_table.c

**Objectif** : Afficher la table de multiplication (0×0 jusqu'à 9×9)

**Logique de travail** :

1. **Fonction** `times_table()` :
   - Affiche la table de multiplication complète

2. **Boucles imbriquées** :
   - **Boucle externe** : les lignes (0 à 9)
   - **Boucle interne** : les colonnes (0 à 9)

3. **Flux d'exécution** :
   ```
   i = 0
   ├─ j = 0 → 0 * 0 = 0 → affiche "0"
   ├─ j = 1 → 0 * 1 = 0 → affiche ", 0"
   ├─ j = 2 → 0 * 2 = 0 → affiche ", 0"
   ├─ ...
   ├─ j = 9 → 0 * 9 = 0 → affiche ", 0\n" (saut de ligne)
   
   i = 1
   ├─ j = 0 → 1 * 0 = 0 → affiche "0"
   ├─ j = 1 → 1 * 1 = 1 → affiche ", 1"
   ├─ j = 2 → 1 * 2 = 2 → affiche ", 2"
   ├─ ...
   
   i = 9
   ├─ j = 0 → 9 * 0 = 0 → affiche "0"
   ├─ j = 1 → 9 * 1 = 9 → affiche ", 9"
   ├─ ...
   ├─ j = 9 → 9 * 9 = 81 → affiche ", 81\n"
   ```

4. **Formatage spécial** :
   ```c
   // Première colonne : sans virgule
   printf("%d", i * j);
   
   // Autres colonnes : avec virgule et espace
   printf(", %d", i * j);
   
   // À la fin de chaque ligne : saut de ligne
   printf("\n");
   ```

**Résultat** :
```
0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 1, 2, 3, 4, 5, 6, 7, 8, 9
0, 2, 4, 6, 8, 10, 12, 14, 16, 18
...
0, 9, 18, 27, 36, 45, 54, 63, 72, 81
```

**Commandes utilisées** :
- **Boucles imbriquées**
- Condition `if (j == 0)` pour la première colonne
- `printf()` avec formatage spécial

---

### 📄 10-add.c

**Objectif** : Additionner deux nombres avec une fonction

**Logique de travail** :

1. **Fonction** `add(int a, int b)` :
   - Prend deux nombres en paramètres
   - Retourne leur somme : `return (a + b)`

2. **Avantages de cette fonction** :
   - Code réutilisable
   - Simplifie le code dans main()
   - Abstrait la logique de l'addition

3. **Utilisation** :
   ```c
   int resultat = add(5, 10);  // resultat = 15
   int autre = add(-3, 7);     // autre = 4
   ```

**Commandes utilisées** :
- Fonction avec paramètres
- Opérateur `+`
- `return` : retourne la valeur

---

### 📄 11-print_to_98.c

**Objectif** : Afficher tous les nombres de n jusqu'à 98

**Logique de travail** :

1. **Fonction** `print_to_98(int n)` :
   - Prend un nombre en paramètre
   - Affiche TOUS les nombres de n jusqu'à 98

2. **Deux cas** :
   - Si `n <= 98` : on compte VERS LE HAUT (n, n+1, n+2, ..., 98)
   - Si `n > 98` : on compte VERS LE BAS (n, n-1, n-2, ..., 98)

3. **Flux d'exécution (cas n = 95)** :
   ```
   n = 95
   while (n <= 98)
   ├─ affiche 95, sépare par ", "
   ├─ n++ → n = 96
   ├─ affiche 96, sépare par ", "
   ├─ n++ → n = 97
   ├─ affiche 97, sépare par ", "
   ├─ n++ → n = 98
   ├─ affiche 98, sans virgule, saut de ligne
   └─ n++ → n = 99, condition FAUSSE, sortie
   ```

4. **Flux d'exécution (cas n = 101)** :
   ```
   n = 101
   while (n >= 98)
   ├─ affiche 101, sépare par ", "
   ├─ n-- → n = 100
   ├─ affiche 100, sépare par ", "
   ├─ ... jusqu'à n = 98
   ├─ affiche 98, sans virgule, saut de ligne
   └─ n-- → n = 97, condition FAUSSE, sortie
   ```

5. **Formatage** :
   ```c
   // Pour tous les nombres sauf 98
   if (n != 98)
       printf("%d, ", n);
   
   // Pour 98
   else
       printf("%d\n", n);
   ```

**Exemples** :
```
print_to_98(50)  → affiche "50, 51, 52, ..., 98"
print_to_98(98)  → affiche "98"
print_to_98(111) → affiche "111, 110, 109, ..., 98"
```

**Commandes utilisées** :
- Boucle `while`
- Condition `if` pour formater l'affichage
- Incrémentation `++` et décrémentation `--`

---

## 💡 Logique & Explications

### Comment fonctionnent les Fonctions

Une fonction est comme une **"boîte noire"** :
- Vous lui donnez des entrées (paramètres)
- Elle fait du travail
- Elle vous donne une sortie (return)

```
Entrées → [Fonction] → Sortie
```

**Exemple** :
```c
int add(int a, int b)  // Prend 2 nombres en entrée
{
    return (a + b);    // Retourne leur somme en sortie
}
```

---

### Boucles Imbriquées - Comprendre le Flux

Une boucle imbriquée = une boucle DANS une boucle

**Visualisation** :
```
Boucle externe → i = 0
├─ Boucle interne → j = 0, 1, 2, 3, 4, 5
├─ Fin boucle interne
Boucle externe → i = 1
├─ Boucle interne → j = 0, 1, 2, 3, 4, 5
├─ Fin boucle interne
Boucle externe → i = 2
├─ Boucle interne → j = 0, 1, 2, 3, 4, 5
└─ ...
```

**Nombre total d'exécutions** = boucle externe × boucle interne
- 3 itérations externes × 6 itérations internes = 18 itérations totales

---

### Manipulation de Caractères en C

En C, les caractères sont des **nombres entiers** :
- 'a' = 97
- 'b' = 98
- 'z' = 122
- 'A' = 65
- 'Z' = 90

**Comparaisons** :
```c
'a' >= 'a' && 'a' <= 'z'  // true (c'est une minuscule)
'A' >= 'a' && 'A' <= 'z'  // false (c'est une majuscule)
```

**Itération sur les caractères** :
```c
for (char c = 'a'; c <= 'z'; c++)  // c augmente de 1 en 1
    printf("%c", c);               // Affiche 'a', 'b', 'c', ...
```

---

## 🛠️ Commandes Utilisées

| Commande | Type | Utilité | Exemple |
|----------|------|---------|---------|
| `printf()` | Fonction | Affiche du texte | `printf("Hello\n")` |
| `write()` | Fonction | Écrit des données | `write(1, &c, 1)` |
| `_putchar()` | Fonction personnalisée | Affiche un caractère | `_putchar('A')` |
| `for` | Boucle | Répète du code | `for (i = 0; i < 10; i++)` |
| `while` | Boucle | Répète tant que condition | `while (n < 98)` |
| `if` | Condition | Exécute si vrai | `if (n > 0)` |
| `else if` | Condition | Sinon si | `else if (n == 0)` |
| `else` | Condition | Sinon | `else { }` |
| `return` | Instruction | Retourne une valeur | `return (1)` |
| `&&` | Opérateur logique | ET logique | `a > 0 && b > 0` |
| `\|\|` | Opérateur logique | OU logique | `a < 0 \|\| a > 10` |
| `!` | Opérateur logique | NON logique | `!condition` |
| `%` | Opérateur | Modulo (reste) | `n % 10` |
| `>`, `<`, `==` | Opérateurs | Comparaison | `n > 5`, `n == 0` |
| `++` | Opérateur | Incrémentation | `i++` (i = i + 1) |
| `--` | Opérateur | Décrémentation | `i--` (i = i - 1) |
| `+=` | Opérateur | Addition assignée | `sum += 5` (sum = sum + 5) |

---

## 📋 Résumé Rapide

| Programme | Objectif | Concepts Clés |
|-----------|----------|---------------|
| **0-putchar.c** | Afficher "Holberton" | Fonction simple, `write()`, boucle |
| **1-alphabet.c** | Afficher l'alphabet | Fonction, boucle `for` avec caractères |
| **2-print_alphabet_x10.c** | Afficher l'alphabet 10 fois | Boucles imbriquées |
| **3-islower.c** | Tester si minuscule | Condition `if`, opérateur logique `&&` |
| **4-isalpha.c** | Tester si lettre | Opérateur logique `\|\|` |
| **5-sign.c** | Retourner le signe | `if` `else if` `else` |
| **6-abs.c** | Valeur absolue | Condition simple |
| **7-print_last_digit.c** | Dernier chiffre | Opérateur modulo `%` |
| **8-24_hours.c** | Toutes les heures (00:00-23:59) | Boucles imbriquées, `printf()` formaté |
| **9-times_table.c** | Table de multiplication | Boucles imbriquées avec formatage |
| **10-add.c** | Additionner deux nombres | Fonction avec paramètres |
| **11-print_to_98.c** | Afficher de n à 98 | Boucle `while`, conditions |

---

## ✍️ Auteur

**Maxim** - [@maxim880000](https://github.com/maxim880000)

Projet réalisé pour **Holberton School** - Apprentissage de la programmation en C

---

<div align="center">

**Bon codage, ! 🚀**

</div>