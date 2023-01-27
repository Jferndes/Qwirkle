#ifndef H_AUTRE_H_INCLUDED
#define H_AUTRE_H_INCLUDED

#define PIOCHE_DEGRADE 36
#define PIOCHE_NORMAL 108
#define MAX_SIZE_TAB 200
#define MAX_SIZE_TAB_MAIN 10
#define MAX_SIZE_TAB_CHAR 20
#define MAX_SIZE_TAB_PLATEAU_HORIZONTAL 12
#define MAX_SIZE_TAB_PLATEAU_VERTICAL 26

#define ROUGE 4
#define BLEU 1
#define VERT 10
#define JAUNE 6
#define ORANGE 14
#define VIOLET 5
#define GRIS_CLAIR 7
#define GRIS_SOMBRE 8
#define NOIR 0
#define BLANC 15

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

/** Déclaration des Variables */

struct tuile
{

    char forme[MAX_SIZE_TAB_CHAR];
    char couleur[MAX_SIZE_TAB_CHAR];

};
typedef struct tuile TUILE;

struct joueur
{

    char nom[MAX_SIZE_TAB_CHAR];
    TUILE main[MAX_SIZE_TAB_MAIN];
    int score;

};
typedef struct joueur JOUEUR;


struct jeu
{

    TUILE plateau[MAX_SIZE_TAB_PLATEAU_HORIZONTAL][MAX_SIZE_TAB_PLATEAU_VERTICAL];
    short nb_joueur;
    short num_joueur;
    short tour;

};
typedef struct jeu JEU;

/** Déclaration des fonctions */

TUILE saisir_tuile();                                                       //Saisie d'une tuile (utilisé pour les premier test)
void saisir_liste_tuile(TUILE* liste_tuile,int nb);                         //Saisie d'une liste de tuile
JOUEUR saisir_joueur();                                                     //Saisie d'un joueur (utilisé pour les premier test)
void saisir_liste_joueur(JOUEUR * liste_tuile,int nb);                      //Saisie d'une liste de tuile
void Couleur(int couleurDuTexte,int couleurDeFond);                         //Change la couleur du fond de texte et du texte. Voir code Couleur plus bas. Ne pas oublier de remettre les paramètres normamaux après utilisation.
int conversion_couleur(TUILE tuile);
void copie_tuile(TUILE* tuile_source, TUILE* tuile_destination);            //Copie les caractéristiques (couleur,forme)dans une autre tuile
void permutation_tuile(TUILE* tuile_source, TUILE* tuile_destination);      //Permute les caractéristiques de deux tuiles
#endif // H_AUTRE_H_INCLUDED
/*
--- 0 : Noir
--- 1 : Bleu foncé
--- 2 : Vert foncé
--- 3 : Turquoise
--- 4 : Rouge
--- 5 : Violet
--- 6 : jaune
--- 7 : Gris clair
--- 8 : Gris foncé
--- 9 : Bleu fluo
--- 10 : Vert fluo
--- 11 : Cyan
--- 12 : Rose fluo
--- 13 : Magenta
--- 14 : beige
--- 15 : Blanc
*/
