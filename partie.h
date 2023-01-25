#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include "Qwirkle.h"


/** Déclaration des fonctions */

void piocher_une_tuile(TUILE* pioche, JOUEUR player);           //Pioche une tuile et la met dans la main du joueur
void poser_une_tuile(TUILE* main);                 //Pose une tuile de la main sur le plateau (Dans la fonction doit demander la position de la tuile prise dans la main et la position où placer la tuile dans le plateau
void poser_plusieur_tuile();
void remettre_tuile_pioche();
int compteur_point_joueur();
void melanger_pioche_degrade(TUILE* pioche);
void melanger_pioche_normal(TUILE* pioche);
void chargement_pioche_normal(TUILE* pioche);
void chargement_pioche_degrade(TUILE* pioche);

#endif // PARTIE_H_INCLUDED
