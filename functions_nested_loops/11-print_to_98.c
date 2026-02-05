#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Affiche tous les nombres naturels de n à 98
 * @n: nombre de départ
 *
 * Description: Affiche tous les nombres de n à 98, séparés par une , et un espace
 * Les nombres sont affichés dans l'ordre croissant ou décroissant
 */
void print_to_98(int n)
{
    /* Si n est inférieur ou égal à 98, on compte vers le haut */
    if (n <= 98)
    {
        for (; n <= 98; n++)
        {
            /* Si on atteint 98, on ajoute un retour à la ligne */
            if (n == 98)
                printf("%d\n", n);
            else
                /* Sinon, on affiche le nombre suivi de ", " */
                printf("%d, ", n);
        }
    }
    else
    {
        /* Si n est supérieur à 98, on compte vers le bas */
        for (; n >= 98; n--)
        {
            if (n == 98)
                printf("%d\n", n);
            else
                printf("%d, ", n);
        }
    }
}
