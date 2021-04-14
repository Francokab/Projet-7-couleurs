#ifndef COLORSENGINE_H
#define COLORSENGINE_H
#define nb_coul 7
#include "CreationMonde.h"


void initialisation(monde* m, joueur* joueur1, joueur* joueur2);
void affichage(monde* m, int Affichage_type);
void majCoup(monde* m, char couleur, joueur joueur1);
int prediction(monde* m, char couleur, joueur joueur1);
char predictionMax(monde* m, joueur joueur1);
char getColor(monde* m, joueur* joueur1);
void doRound(monde* m, joueur* joueur1);
int playGame(int taille_monde, int IA1, int IA2, int Affichage_type);

#endif