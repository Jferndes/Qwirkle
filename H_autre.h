#ifndef H_AUTRE_H_INCLUDED
#define H_AUTRE_H_INCLUDED

#define PIOCHE_DEGRADE 36
#define PIOCHE_NORMAL 108
#define MAX_SIZE_TAB 200
#define MAX_SIZE_TAB_MAIN 10
#define MAX_SIZE_TAB_CHAR 20
#define MAX_SIZE_TAB_PLATEAU_HORIZONTAL 26
#define MAX_SIZE_TAB_PLATEAU_VERTICAL 12

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

    TUILE plateau[MAX_SIZE_TAB_PLATEAU_VERTICAL][MAX_SIZE_TAB_PLATEAU_HORIZONTAL];
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
void copie_tuile(TUILE* tuile_source, TUILE* tuile_destination);            //Copie les caractéristiques (couleur,forme)dans une autre tuile
void permutation_tuile(TUILE* tuile_source, TUILE* tuile_destination);      //Permute les caractéristiques de deux tuiles
#endif // H_AUTRE_H_INCLUDED
/*
--- 0 : Noir
--- 1 : Bleu foncé
--- 2 : Vert foncé
--- 3 : Turquoise
--- 4 : Rouge foncé
--- 5 : Violet
--- 6 : Vert caca d'oie
--- 7 : Gris clair
--- 8 : Gris foncé
--- 9 : Bleu fluo
--- 10 : Vert fluo
--- 11 : Turquoise
--- 12 : Rouge fluo
--- 13 : Violet_2
--- 14 : Jaune
--- 15 : Blanc
*/
