#include "H_autre.h"

TUILE saisir_tuile()
{
    TUILE tuile_saisie;
    printf("Introduire la couleur : ");
    scanf("%s",tuile_saisie.couleur);
    tuile_saisie.couleur[MAX_SIZE_TAB_CHAR-1] = '\0';
    fflush(stdin);
    printf("Introduire la forme : ");
    scanf("%s",tuile_saisie.forme);

    tuile_saisie.forme[MAX_SIZE_TAB_CHAR-1] = '\0';
    fflush(stdin);

    return tuile_saisie;
}

void saisir_liste_tuile(TUILE* liste_tuile, int nb)
{
    int i;
    for(i=0; i< nb; i++)
    {
        liste_tuile[i] = saisir_tuile();
    }
}



JOUEUR saisir_joueur()
{
    JOUEUR joueur_saisie;

    printf("\n");
    printf("Introduire le nom : ");
    scanf("%s",joueur_saisie.nom);
    joueur_saisie.nom[MAX_SIZE_TAB_CHAR-1] = '\0';
    fflush(stdin);
    printf("Introduire le score : ");
    scanf("%d",&joueur_saisie.score);
    fflush(stdin);
    printf("Introduire la main : \n");
    saisir_liste_tuile(joueur_saisie.main,6);

    return joueur_saisie;
}

void saisir_liste_joueur(JOUEUR* liste_joueur, int nb)
{
    int i;
    for(i=0; i< nb; i++)
    {
        liste_joueur[i] = saisir_joueur();
    }
}

void Couleur(int couleurDuTexte,int couleurDeFond) //fonction d'affichage de couleurs voir code couleur dans H_autre.h

{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void copie_tuile(TUILE* tuile_source, TUILE* tuile_destination)
{
    strcpy(tuile_destination->couleur, tuile_source->couleur);
    strcpy(tuile_destination->forme, tuile_source->forme);
}

void permutation_tuile(TUILE* tuile_source, TUILE* tuile_destination)
{
    TUILE tmp;

    copie_tuile(tuile_source,&tmp);
    copie_tuile(tuile_destination,tuile_source);
    copie_tuile(&tmp,tuile_destination);
}
