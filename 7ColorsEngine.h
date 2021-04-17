#ifndef COLORSENGINE_H
#define COLORSENGINE_H
#define nb_coul 7
#include "CreationMonde.h"


void initialisation(monde* m, joueur* joueur1, joueur* joueur2); // initialise le plateau de jeu
void affichage(monde* m, int Affichage_type); // affiche le plateau de jeu et met à jour les valeur des joueurs
void majCoup(monde* m, char couleur, joueur joueur1); // joue le coup pour un certain joueur avec une certaine couleur
int prediction(monde* m, char couleur, joueur joueur1); //renvoit le nombre de case que le coup gagnerait si on le faisait (ne reset pas le plateau Simulé par default)
char predictionMax(monde* m, joueur joueur1); // fait une prediction avec chaque couleur et renvoir la meilleur
int perimetre(monde* m, joueur joueur1); // renvoit le perimetre d'un joueur
int perimetreSimule(monde* m, joueur joueur1); //comme perimetre mais sur le plateau simulé
char predictionPeri(monde* m, joueur joueur1);
char predictionMax2(monde* m, joueur joueur1); // fait une avec chaque couple de 2 coup possible
char getColor(monde* m, joueur* joueur1); // renvoit la couleur à jouer pendant se tour (demande au joueur ou faut l'IA)
void doRound(monde* m, joueur* joueur1); // joue un tour de jeux avec le joueur1
int playGame(int taille_monde, int IA1, int IA2, int Affichage_type); // joue une partie avec IA1 et IA2 l'IA du joueur 1 et 2 et Affichage_type = 1 si on veut afficher la partie. Renvoit le joueur qui a gagné (1 ou 2 ou 0 si égalité) 

#endif