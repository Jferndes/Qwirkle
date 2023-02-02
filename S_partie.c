#include "H_partie.h"
#include "H_plateau.h"


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

int rechercher_tuile_occupe(TUILE* main)
{

    int i;
    for(i=0; i<6; i++)
    {
        if(strcmp(main[i].couleur,"\0"))
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

bool validite_pos_tuile_plateau(int ligne, int colonne, TUILE tuile, JEU* partie)
{
    /*
    //Cas toutes les cases adjacente sont vides (Ne pas faire en bordure ou dans les coins)
    if(!strcmp("\0", partie->plateau[ligne][colonne+1].couleur) && !strcmp("\0", partie->plateau[ligne][colonne-1].couleur) && !strcmp("\0", partie->plateau[ligne-1][colonne].couleur) && !strcmp("\0", partie->plateau[ligne+1][colonne].couleur))
    {
        printf("\n");
        printf("La position cible ne respect pas les regles : ");
        Couleur(ROUGE,BLANC);
        printf("Il n'y a aucune tuile adjacente");
        Couleur(BLANC,NOIR);
        printf("\n\n");

        return false;
    }
    */

    /**pour test*/
    printf("forme tuile plateau : %s\n",partie->plateau[ligne-1][colonne].forme);
    printf("forme tuile plateau : %s\n",tuile.forme);
    printf("comparaison : %d\n",strcmp(tuile.forme, partie->plateau[ligne-1][colonne].forme));
    printf("\n");
    /** fin test */

    //Cas Gauche de la pos cible : Vérification de la couleur (Ne pas faire si colonne = 0)
    if(colonne != 0)
    {
        if(strcmp(tuile.couleur, partie->plateau[ligne][colonne-1].couleur) && strcmp(partie->plateau[ligne][colonne-1].couleur, "\0"))
        {
            printf("\n");
            printf("La position cible ne respect pas les regles : ");
            Couleur(ROUGE,BLANC);
            printf("La tuile adjacente de gauche n'a pas la meme couleur'");
            Couleur(BLANC,NOIR);
            printf("\n\n");

            return false;
        }
    }


    //Cas Droite de la pos cible : Vérification de la couleur (Ne pas faire si colonne = 26)
    if(colonne != 26)
    {
        if(strcmp(tuile.couleur, partie->plateau[ligne][colonne+1].couleur) && strcmp(partie->plateau[ligne][colonne+1].couleur, "\0"))
        {
            printf("\n");
            printf("La position cible ne respect pas les regles : ");
            Couleur(ROUGE,BLANC);
            printf("La tuile adjacente de droite n'a pas la meme couleur");
            Couleur(BLANC,NOIR);
            printf("\n\n");

            return false;
        }
    }

    //Cas Haut de la pos cible : Vérification de la forme (Ne pas faire si ligne = 0)
    if(ligne != 0)
    {
        if(strcmp(tuile.forme, partie->plateau[ligne-1][colonne].forme) && strcmp(partie->plateau[ligne-1][colonne].forme, " \0"))
        {
            printf("\n");
            printf("La position cible ne respect pas les regles : ");
            Couleur(ROUGE,BLANC);
            printf("La tuile adjacente au-dessus n'a pas la meme forme");
            Couleur(BLANC,NOIR);
            printf("\n\n");

            return false;
        }
    }


    //Cas Bas de la pos cible : Vérification de la forme (Ne pas faire si ligne = 12)
    if(ligne != 12)
    {
        if(strcmp(tuile.forme, partie->plateau[ligne+1][colonne].forme) && strcmp(partie->plateau[ligne+1][colonne].forme, " \0"))
        {
            printf("\n");
            printf("La position cible ne respect pas les regles : ");
            Couleur(ROUGE,BLANC);
            printf("La tuile adjacente en-dessous n'a pas la meme forme");
            Couleur(BLANC,NOIR);
            printf("\n\n");

            return false;
        }
    }

    return true;
}






void poser_une_tuile(TUILE* main, JEU* partie)
{
    int pos;
    int codeascii;
    int nbtentative;
    char ligne;
    char colonne;

    /*Verification de la main du joueur*/
    if(rechercher_tuile_occupe(main) == -1)
    {
        printf("Votre main est vide. Vous ne pouvez pas poser de tuile\n");
    }
    else
    {
        /*Boucle de contrôle position tuile*/
        nbtentative = 0;
        do
        {
            if(nbtentative != 0)
            {
                printf("Vous n'avez pas de tuile ici\n\n");
            }
            printf("Choisir une tuile dans la main et donner sa position\n");
            scanf("%d",&pos);
            nbtentative ++;
        }
        while(!strcmp(main[pos-1].forme,"\0") || pos < 1 || pos > 6); // la position est une tuile non-vide  et comprise entre 1 et 6

        printf("\n");
        printf("Vous allez placer la tuile :");
        affichage_tuile_plateau(main[pos-1], NOIR);
        printf("\n");


        codeascii = 97;
        fflush(stdin);
        printf("Choisir la postion dans le plateau (sous la forme lettre et chiffre)\n");

        /*Boucle de contrôle position tuile*/
        nbtentative = 0;
        do
        {
            if(nbtentative != 0)
            {
                printf("Cette position n'est pas possible\n\n");
            }
            printf("ligne : ");
            scanf("%c",&ligne);
            fflush(stdin);
            nbtentative ++;
        }
        while(ligne<97 || ligne>109); //La ligne est comprise entre les lettres 'a' (code ascii 97) et 'l' (code ascii 109)

        nbtentative = 0;
        do
        {
            if(nbtentative != 0)
            {
                printf("Cette position n'est pas possible\n\n");
            }
            printf("colonne : ");
            scanf("%c", &colonne);
            fflush(stdin);
            nbtentative ++;
        }
        while(colonne<97 || colonne>123); //La colonne est comprise entre les lettres 'a' (code ascii 97) et 'z' (code ascii 123)



        /*copie sur le plateau et retrait de la tuile dans la main*/
        if(validite_pos_tuile_plateau(ligne-codeascii,colonne-codeascii,main[pos-1], partie) == true)
        {
            copie_tuile(&main[pos-1], &partie->plateau[ligne-codeascii][colonne-codeascii]);
            strcpy(main[pos-1].couleur,"\0");
            strcpy(main[pos-1].forme,"\0");
        }
        else
        {
            printf("erreur\n\n");
        }
    }
}






