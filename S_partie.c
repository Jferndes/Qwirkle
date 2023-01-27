#include "H_partie.h"

void chargement_pioche_degrade(TUILE* pioche)
{
    FILE* fichier = NULL;
    char chaine[MAX_SIZE_TAB_CHAR]="\0";
    int i = 0;
    char * strToken = NULL;


    fichier = fopen("pioche_degrade.txt", "r");

    if (fichier != NULL)
    {
        while (fgets(chaine, MAX_SIZE_TAB_CHAR, fichier) != NULL) // Lecture fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {

            strToken = strtok(chaine, ";");         //Decoupage de la chaine jusqu'au ';'
            strcpy(pioche[i].couleur,strToken);     //copie dans la zone couleur
            strToken = strtok ( NULL, ";");         //lecture de la chaine suivante

            strcpy(pioche[i].forme,strToken);       //copie dans la zone forme
            i++;
        }
        fclose(fichier);
    }

    else
    {
        printf("Erreur de l'ouverture du fichier");
        exit(-1);
    }
}

void chargement_pioche_normal(TUILE* pioche)
{
    FILE* fichier = NULL;
    char chaine[MAX_SIZE_TAB_CHAR]="\0";
    int i = 0;
    char * strToken = NULL;


    fichier = fopen("pioche_normal.txt", "r");

    if (fichier != NULL)
    {
        while (fgets(chaine, MAX_SIZE_TAB_CHAR, fichier) != NULL) //Lecture fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {

            strToken = strtok(chaine, ";");         //Decoupage de la chaine jusqu'au ';'
            strcpy(pioche[i].couleur,strToken);     //Copie dans la zone couleur
            strToken = strtok ( NULL, ";");         //Lecture de la chaine suivante

            strcpy(pioche[i].forme,strToken);       //Copie dans la zone forme
            i++;
        }
        fclose(fichier);
    }

    else
    {
        printf("Erreur de l'ouverture du fichier");
        exit(-1);
    }
}


void melanger_pioche_degrade(TUILE* pioche)
{
    int i;
    int j;
    int k;

    for(i=0; i<1000; i++)
    {
        j=rand()%36;        //Donne un nombre entre 0 et 36

        do
        {
            k=rand()%36;    //Donne un nombre entre 0 et 36 différent de j
        }
        while(j==k);

        permutation_tuile(&pioche[j],&pioche[k]);

    }
}

void melanger_pioche_normal(TUILE* pioche)
{
    int i;
    int j;
    int k;

    for(i=0; i<1000; i++)
    {
        j=rand()%108;        //Donne un nombre entre 0 et 108

        do
        {
            k=rand()%108;    //Donne un nombre entre 0 et 108 différent de j
        }
        while(j==k);

        permutation_tuile(&pioche[j],&pioche[k]);

    }
}

void initialiser_main(TUILE* main)
{
    int i;
    for(i=0; i<6; i++)
    {
        strcpy(main[i].couleur,"\0");
        strcpy(main[i].forme,"\0");
    }
}

int rechercher_tuile_vide(TUILE* main)
{

    int i;
    for(i=0; i<6; i++)
    {
        if(!strcmp(main[i].couleur,"\0"))
        {
            return i;
        }
    }

    return -1;
}

void piocher_une_tuile(TUILE* pioche, JOUEUR* player, int* taille_pioche)
{
    int i;

    if(taille_pioche == 0)
    {
        printf("La pioche est vide\n");
    }
    else
    {
        i = rechercher_tuile_vide(player->main);        //Recherche de case vide dans la main

        if(i == -1)
        {
            printf("Votre main est pleine\n");
        }
        else
        {
            copie_tuile(&pioche[*taille_pioche-1],&player->main[i]);
            *taille_pioche -= 1 ;
        }
    }
}

void remplir_main(TUILE* pioche, JOUEUR* player, int* taille_pioche)
{
    int i;

    for(i=0; i<6; i++)
    {
        piocher_une_tuile(pioche, player, taille_pioche);
    }
}

void poser_une_tuile(TUILE* main, JEU* partie)
{
    int pos;
    int ligne;
    int colonne;

    printf("Choisir une tuile dans la main et donner sa position\n");
    scanf("%d",&pos);

    if(rechercher_tuile_vide(main) != pos)
    {
        printf("Choisir la postion dans le plateau (sous la forme 'n°ligne' 'n°colonne')\n");
        scanf("%d %d", &ligne, &colonne);

        copie_tuile(&main[pos-1], &partie->plateau[ligne-1][colonne-1]);
    }
    else
    {
        printf("Vous n'avez pas de tuile ici\n");
    }
}






