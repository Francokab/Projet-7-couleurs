#include <stdio.h>
#include "7ColorsEngine.h"
#define tour_max 100


int main() {
  monde monde1 = *createMonde(40);
  joueur joueur1 = *createJoueur(1,0);
  joueur joueur2 = *createJoueur(2,2);
  initialisation(&monde1, &joueur1, &joueur2);
  affichage(&monde1); // on affiche le monde
  int tour = 1;
  while (joueur1.pourcentage <= 50 && joueur2.pourcentage<=50) { // condtions de victoire : avoir plus de 50% du territoire pour gagner
    printf("Tour %d :\n", tour);
    // si le tour est pair, le joueur 2 joue
    // si le tour est impair, le joueur 1 joue
    (tour % 2) ? doRound(&monde1, &joueur1) : doRound(&monde1, &joueur2);
    affichage(&monde1);
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