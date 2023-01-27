#ifndef H_MENU_H_INCLUDED
#define H_MENU_H_INCLUDED

#include "H_autre.h"

#define MENU_PRINCIPAL 10
#define JOUER 2
#define REGLE_DU_JEUX 3
#define CREDIT 4
#define QUITTER 0

#define MENU_MODE_DE_JEUX 5
#define NORMAL 6
#define DEGRADE 7

#define CHOIX_NOMBRE_JOUEUR 8

#define DEUX_JOUEUR 2
#define TROIS_JOUEUR 3
#define QUATRE_JOUEUR 4

#define RETOUR 1




int menu_principal();
int jouer();
int regle_du_jeux();
int credit();
int quitter();
int retour();
void menu();
int choix_nombre_joueur();

#endif // H_MENU_H_INCLUDED
