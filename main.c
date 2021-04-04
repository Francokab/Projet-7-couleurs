#include <stdio.h>
#include "7ColorsEngine.h"
#define tour_max 100


int main() {
  joueur joueur1 = *createJoueur(1,0);
  joueur joueur2 = *createJoueur(2,0);
  initialisation(joueur1, joueur2);
  affichage(&joueur1, &joueur2); // on affiche le monde
  int tour = 1;
  while (joueur1.pourcentage <= 50 && joueur2.pourcentage<=50) { // condtions de victoire : avoir plus de 50% du territoire pour gagner
    printf("Tour %d :\n", tour);
    // si le tour est pair, le joueur 2 joue
    // si le tour est impair, le joueur 1 joue
    (tour % 2) ? doRound(&joueur1) : doRound(&joueur2);
    affichage(&joueur1, &joueur2);
    tour++;
  }
  if (joueur1.pourcentage>50){
    printf("le joueur 1 à gagné\n");
  }
  else if (joueur2.pourcentage>50){
    printf("le joueur 2 à gagné\n");
  }
  return 0;
}