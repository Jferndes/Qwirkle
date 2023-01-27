#ifndef H_PLATEAU_H_INCLUDED
#define H_PLATEAU_H_INCLUDED

#include "H_autre.h"

/** Déclaration des fonctions */

void affichage_tuile(TUILE tuile);                              //Affiche une structure de type TUILE (couleur+forme)
void affichage_liste_tuile(TUILE* liste_tuile, int nb);         //Affiche une liste de structure de type TUILE
void affichage_main_joueur(JOUEUR player);                      //Affiche la main du joueur
void affichage_score_joueur(int score, JOUEUR player);          //Affiche le score du joueur
void affichage_tuile_plateau(TUILE tuile, int couleur_fond);

//Fonction de test
void affichage_joueur(JOUEUR joueur);
void affichage_liste_joueur(JOUEUR* liste_joueur, int nb);

//Fonction global
void initialiser_plateau(JEU* partie);                              //Initialise un plateau vide
void affichage_plateau(JEU partie);                                 //Affiche le plateau du tour






#endif // H_PLATEAU_H_INCLUDED
