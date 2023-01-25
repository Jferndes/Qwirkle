#include "H_plateau.h"

void affichage_tuile(TUILE tuile)
{

    printf("%s|%s",tuile.couleur, tuile.forme);
    printf("\n");

}

void affichage_liste_tuile(TUILE* liste_tuile, int nb)
{
    int i;
    for(i =0; i< nb; i++ )
    {
        affichage_tuile(liste_tuile[i]);
    }
}

void affichage_joueur(JOUEUR joueur)
{
    printf("nom : %s\n",joueur.nom);
    printf("score : %d\n",joueur.score);

    printf("Main du joueur :\n");
    affichage_liste_tuile(joueur.main,6);
}

void affichage_liste_joueur(JOUEUR* liste_joueur,int nb)
{

    int i;
    for(i =0; i< nb; i++ )
    {
        printf("*****************************\n");
        affichage_joueur(liste_joueur[i]);

    }

}

void affichage_main_joueur(JOUEUR player){

    affichage_liste_tuile(player.main,6);
}
