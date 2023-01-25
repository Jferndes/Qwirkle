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
