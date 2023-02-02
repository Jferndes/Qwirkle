#include "H_autre.h"
#include "H_menu.h"
#include "H_partie.h"
#include "H_plateau.h"


int main()
{
    int i;
    TUILE pioche[MAX_SIZE_TAB];
    JOUEUR J1;
    int taille_pioche = 108;
    JEU partie;

    chargement_pioche_normal(pioche);
    melanger_pioche_normal(pioche);


    remplir_main(pioche, &J1, &taille_pioche);

    initialiser_plateau(&partie);
    affichage_plateau(&partie);

    for(i = 0; i<7; i++)
    {
        printf("****** TOUR %d******\n",i+1);
        affichage_main_joueur_plateau(J1);
        printf("\n");

        poser_une_tuile(J1.main, &partie);
        printf("****** PLATEAU ******\n");
        affichage_plateau(&partie);
        printf("\n\n");
    }

    return 0;
}
