#ifndef H_PARTIE_H_INCLUDED
#define H_PARTIE_H_INCLUDED

#include "H_autre.h"

/** D�claration des fonctions */

void chargement_pioche_degrade(TUILE* pioche);                              //Chargement de la pioche d�grad� � partir d'un fichier .txt
void chargement_pioche_normal(TUILE* pioche);                               //Chargement de la pioche norlmal � partir d'un fichier .txt
void melanger_pioche_degrade(TUILE* pioche);                                //M�lange la pioche du mode d�grad�
void melanger_pioche_normal(TUILE* pioche);                                 //M�lange la pioche du mode normal
void initialiser_main(TUILE* main);                                         //Initialise une main de joueur par des tuiles vides
int rechercher_tuile_vide(TUILE* main);                                     //Recherche une tuile vide dans la main et renvoie l'index. Retourne -1 si aucune tuile vide
int rechercher_tuile_occupe(TUILE* main);                                     //Recherche une tuile occup� dans la main et renvoie l'index. Retourne -1 si aucune tuile occup�
void remplir_main(TUILE* pioche, JOUEUR* player, int* taille_pioche);       //Remplie la main d'un joueur
void piocher_une_tuile(TUILE* pioche, JOUEUR* player, int* taille_pioche);  //Pioche une tuile et la met dans la main du joueur --- Retourne
void poser_une_tuile(TUILE* main, JEU* partie);                             //Pose une tuile de la main sur le plateau (Dans la fonction doit demander la position de la tuile prise dans la main et la position o� placer la tuile dans le plateau
void poser_plusieur_tuile();
void remettre_tuile_pioche();
int compteur_point_joueur();
#endif // H_PARTIE_H_INCLUDED
