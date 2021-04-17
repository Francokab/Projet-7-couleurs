#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "7ColorsEngine.h"
#include "CreationMonde.h"
#define tour_max 100
#define taille_m 30
#define nbPartie 100
#define IAJoueur1 2
#define IAJoueur2 3
#define Affichage 1

// IA = 0 : humain
// IA = 1 : aléatoire
// IA = 2 : glouton
// IA = 3 : gloutonPrevoyant
// IA = 4 : hégémonique (marche mal et peut se bloquer)
// Affichage = 1 : affiche la Partie
// Si vous avait un joueur humain il est conseiller de jouer avec afficahge

int main() {
  srand(time(0)); // initialiser la fonction random
  int WinJ1 = 0;
  int WinJ2 = 0;
  int WinJ0 = 0;
  for (int i = 0; i<nbPartie; i = i+1){
    int a = playGame(taille_m,IAJoueur1,IAJoueur2,Affichage);
    printf("Partie %d : Victoire %d\n", i, a);
    switch (a){
      case 0:
        WinJ0++;
        break;
      case 1:
        WinJ1++;
        break;
      case 2:
        WinJ2++;
        break;
    }
  }
  printf("le joueur 1 a gagné %d fois, le joueur 2 a gagné %d fois, et il y a eu %d égalité", WinJ1, WinJ2, WinJ0);
  return 0;
}
