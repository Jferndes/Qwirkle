#include "H_menu.h"

int menu_principal()
{
    int choix;
    do
    {
        printf("******* Menu principal *********\n");
        printf("Introduire votre choix :\n");
        printf("-%d JOUER\n",JOUER);
        printf("-%d regle du jeux\n",REGLE_DU_JEUX);
        printf("-%d credit\n",CREDIT);
        printf("-%d QUITTER \n",QUITTER);

        scanf("%d",&choix);
    }
    while(choix!=JOUER
            && choix !=REGLE_DU_JEUX
            && choix != CREDIT
            && choix != QUITTER
         );
    return choix;
}


int jouer()
{
    int choix;
    do
    {
        printf("******* choisissez votre mode *********\n");
        printf("Introduire votre choix :\n");
        printf("-%d NORMAL\n",NORMAL);
        printf("-%d DEGRADE\n",DEGRADE);
        printf("-%d RETOUR\n",RETOUR);

        scanf("%d",&choix);
    }
    while(choix!=NORMAL
            && choix !=DEGRADE
            && choix != RETOUR
         );
    return choix;
}

int normal()
{


    return 0;
}



int degrade()
{


    return 0;
}



int choix_nombre_joueur()
{

    int choix;


    do
    {

        printf("******* choisissez le nombre de joueur *********\n");
        printf("Introduire votre choix :\n");
        printf("-%d 2 JOUEUR\n",DEUX_JOUEUR);
        printf("-%d 3 JOUEUR\n",TROIS_JOUEUR);
        printf("-%d 4 JOUEUR\n",QUATRE_JOUEUR);

        scanf("%d",&choix);
    }
    while(choix!=DEUX_JOUEUR
            && choix !=TROIS_JOUEUR
            && choix != QUATRE_JOUEUR
         );
    return choix;

}


void menu()
{

    //déclaration des variables

    int choix;

    do
    {
        choix = menu_principal();
        switch(choix)
        {
        case(JOUER):

            do
            {
                choix = jouer();
                switch(choix)
                {
                case(NORMAL):
                    choix_nombre_joueur();
                    break;


                case(DEGRADE):
                    choix_nombre_joueur();
                    break;

                case(RETOUR):
                    printf("\n\n [RETOUR AU MENU PRECEDENT] \n\n");
                    break;
                default :
                    break;
                }
            }
            while(choix!=RETOUR);
            break;

        case(REGLE_DU_JEUX):
            break;

        case(CREDIT):
            break;

        case(QUITTER):
            printf("\n\n [Au revoir] \n\n");
            break;
        default :
            break;
        }
    }
    while(choix != QUITTER);

}
