#include "Qwirkle.h"
#include "menu.h"
#include "partie.h"
#include "plateau.h"


#include <stdio.h>



int main()
{
    TUILE pioche[MAX_SIZE_TAB];

    chargement_pioche_normal(pioche);

    affichage_liste_tuile(pioche,PIOCHE_NORMAL);


    printf("************************MELANGE***************************\n");

    melanger_pioche_normal(pioche);

    affichage_liste_tuile(pioche,PIOCHE_NORMAL);

    return EXIT_SUCCESS;

}
