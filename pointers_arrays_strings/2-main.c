#include <stdio.h>

/* Teste la fonction _strchr qui cherche un caractère dans une chaîne */

 /**
  * main - point d'entrée du programme
  *
  * Return: toujours 0
  */
int main(void)
{
    char *s = "hello"; /* Chaîne de départ */
    char *f;           /* Pointeur pour stocker le résultat */

    /* Cherche le caractère 'l' dans la chaîne s */
    f = _strchr(s, 'l');

    /* Si le caractère est trouvé, affiche la sous-chaîne à partir de ce caractère */
    if (f != NULL)
    {
        printf("%s\n", f);
    }

    /* Retourne 0 pour indiquer succès */
    return (0);
}
