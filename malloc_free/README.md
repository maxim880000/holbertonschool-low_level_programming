..L

3 : 
int **grid ?
Parce que tu veux un pointeur vers un tableau de pointeurs vers int.
Tu peux le lire comme :
→ “grid” est un tableau dont chaque case contient l’adresse d’un autre tableau (une ligne).

logique que g eu :
Vérifier les dimensions → si width ou height ≤ 0 → on ne peut pas créer de tableau → return NULL.

Allouer le tableau principal → on réserve de la mémoire pour toutes les lignes (un tableau de pointeurs).

Allouer chaque ligne → pour chaque pointeur, on réserve la mémoire nécessaire à une ligne complète d’entiers.

Gérer les erreurs d’allocation → si une ligne échoue, on libère toutes les précédentes pour éviter les fuites mémoire.

Initialiser tout à 0 → on met chaque case à zéro pour que le tableau soit propre dès le départ.

Retourner le tableau → si tout va bien, on renvoie le pointeur vers le tableau 2D.

