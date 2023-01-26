#include "H_autre.h"
#include "H_menu.h"
#include "H_partie.h"
#include "H_plateau.h"


#include <stdio.h>



int main()
{
    TUILE pioche[MAX_SIZE_TAB];
    JOUEUR J1;
    int taille_pioche = 108;

    //*taille_pioche = 108;

    chargement_pioche_normal(pioche);
    melanger_pioche_normal(pioche);

    printf("******* MAIN VIDE ***********\n");
    initialiser_main(J1.main);
    affichage_liste_tuile(J1.main,6);

    printf("******* MAIN pioche ***********\n");

    remplir_main(pioche, &J1, &taille_pioche);

    affichage_liste_tuile(J1.main,6);

    return EXIT_SUCCESS;
}
