#include "H_plateau.h"

void affichage_tuile(TUILE tuile)
{
    printf("%s|%s",tuile.couleur, tuile.forme);
}

void affichage_liste_tuile(TUILE* liste_tuile, int nb)
{
    int i;
    for(i =0; i< nb; i++ )
    {
        affichage_tuile(liste_tuile[i]);
    }
}

void affichage_main_joueur(JOUEUR player)
{
    affichage_liste_tuile(player.main,6);
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

void initialiser_plateau(JEU* partie)
{
    int i;
    int j;

    for(i=0; i<MAX_SIZE_TAB_PLATEAU_HORIZONTAL; i++)
    {
        for(j=0; j<MAX_SIZE_TAB_PLATEAU_VERTICAL; j++)
        {
            strcpy(partie->plateau[i][j].couleur,"\0");
            strcpy(partie->plateau[i][j].forme,"\0");
        }
    }
}
void affichage_tuile_plateau(TUILE tuile, int couleur_fond)
{

    Couleur(conversion_couleur(tuile),couleur_fond);
    printf(" %c ",tuile.forme[0]);
    Couleur(15,0);
}

void affichage_plateau(JEU partie)
{
    int i;
    int j;
    int k;
    int codeascii;

    /* Affichage première ligne grise avec suite de lettres alphabétique */
    Couleur(BLANC, GRIS_SOMBRE);
    printf("   ");
    for(k = 0, codeascii = 97; k<MAX_SIZE_TAB_PLATEAU_VERTICAL; k++)
    {
        printf(" %c ", k+codeascii);
    }
    printf("   ");
    printf("\n");

    for(i=0, k=0; i<MAX_SIZE_TAB_PLATEAU_HORIZONTAL; i++, k++)
    {
        for(j=0; j<MAX_SIZE_TAB_PLATEAU_VERTICAL; j++)
        {

            /* Affichage de la première colonne grise avec suite de lettre */
            if(j == 0)
            {
                Couleur(BLANC, GRIS_SOMBRE);
                printf(" %c ",k+codeascii);
            }

            /* Affichage des tuiles du plateau */
            if(i%2 == 0)
            {
                if(j%2 == 0)
                {
                    Couleur(BLANC, GRIS_CLAIR);
                    affichage_tuile_plateau(partie.plateau[i][j],GRIS_CLAIR);
                }
                else
                {
                    affichage_tuile_plateau(partie.plateau[i][j],NOIR);
                }
            }
            else if(j%2 == 0)
            {
                Couleur(BLANC, NOIR);
                affichage_tuile_plateau(partie.plateau[i][j],NOIR);
            }
            else
            {
                affichage_tuile_plateau(partie.plateau[i][j],GRIS_CLAIR);
            }
        }

        /* Affichage de la dernière colonne grise */
        Couleur(BLANC, GRIS_SOMBRE);
        printf("   \n");
    }

    /* Affichage de la dernière ligne grise */
    printf("   ");
    for(k = 0; k < MAX_SIZE_TAB_PLATEAU_VERTICAL+1; k++)
    {
        printf("   ");
    }
    Couleur(BLANC, NOIR);
}



