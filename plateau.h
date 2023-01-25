#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "Qwirkle.h"

/** Déclaration des fonctions */

void affichage_tuile(TUILE tuile);                              //Affiche une structure de type TUILE (couleur+forme)
void affichage_liste_tuile(TUILE* liste_tuile, int nb);         //Affiche une liste de structure de type TUILE
void affichage_main_joueur(JOUEUR player);                      //Affiche la main du joueur
void affichage_score_joueur(int score, JOUEUR player);          //Affiche le score du joueur

//Fonction de test
void affichage_joueur(JOUEUR joueur);
void affichage_liste_joueur(JOUEUR* liste_joueur, int nb);

//Fonction global
void affiche_plateau(JEU* partie);                               //Affiche le plateau du tour






#endif // PLATEAU_H_INCLUDED
