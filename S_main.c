#include "H_autre.h"
#include "H_menu.h"
#include "H_partie.h"
#include "H_plateau.h"


int main()
{

    TUILE pioche[MAX_SIZE_TAB];
    JOUEUR J1;
    int taille_pioche = 108;
    JEU partie;

    chargement_pioche_normal(pioche);
    melanger_pioche_normal(pioche);


    remplir_main(pioche, &J1, &taille_pioche);
    printf("****** MAIN J1 ******\n");
    affichage_main_joueur(J1);
    printf("\n");


    initialiser_plateau(&partie);

    printf("****** TOUR 1******\n");
    affichage_main_joueur_plateau(J1);
    printf("\n");

    poser_une_tuile(J1.main, &partie);

    printf("****** PLATEAU ******\n");
    affichage_plateau(&partie);
    printf("\n");

    affichage_main_joueur(J1);
    printf("\n");
    affichage_main_joueur_plateau(J1);
    printf("\n");

    printf("****** TOUR 2******\n");
    poser_une_tuile(J1.main, &partie);

    printf("****** PLATEAU ******\n");
    affichage_plateau(&partie);

    printf("\n");
    affichage_main_joueur_plateau(J1);
    printf("\n");

    printf("****** TOUR 3******\n");
    poser_une_tuile(J1.main, &partie);

    printf("****** PLATEAU ******\n");
    affichage_plateau(&partie);
    printf("\n");

    for(int i=0;i<300;i++)
    {
        printf("%d",i);
    }
    printf("\n");
    affichage_main_joueur_plateau(J1);
    printf("\n");

    return 0;
}
