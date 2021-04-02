#include <stdio.h>
#include "7ColorsEngine.h"
#define tour_max 100

int main() {
  joueur joueur1 = *createJoueur(1);
  joueur joueur2 = *createJoueur(2);
  initialisation(joueur1, joueur2);
  printf("Jeu par Infogrames Entertainment ©\n");
  affichage(&joueur1, &joueur2); // on affiche le monde
  char couleur_tour;
  int tour = 1;
  int compa;
  int couleur_j1 = 0;
  int couleur_j2 = 0;
  while (joueur1.pourcentage <= 50 && joueur2.pourcentage<=50) { // condtions de victoire : avoir plus de 50% du territoire pour gagner
    compa = 0;
    printf("tour %d \n", tour);
    if ((tour % 2) == 1) { // si le tour est impair, le joueur 1 joue
      while (!compa) { // on vérfie que la couleur soit bien une des couleurs du plateau
        printf(" joueur 1 %c, indiquer la couleur que vous voulez récupérer\n", joueur1.Symbole);
        scanf(" %c", &couleur_tour);
        for (int i = 0; i < nb_coul; i++) { // on compare pour toute la liste de couleur
          compa += (1 && (couleur_tour == couleur[i]));
        }
      }
      majCoup(couleur_tour, joueur1);
      affichage(&joueur1, &joueur2);
    }
    else { // si le tour est pair, le joueur 2 joue
      while (!compa) { // on vérfie que la couleur soit bien une des couleurs du plateau
        printf(" joueur 2 %c, indiquer la couleur que vous voulez récupérer\n", joueur2.Symbole);
        scanf(" %c", &couleur_tour);
        for (int i = 0; i < nb_coul; i++) { // on compare pour toute la liste de couleur
          compa += (1 && (couleur_tour == couleur[i]));
        }
      }
      majCoup(couleur_tour, joueur2);
      affichage(&joueur1, &joueur2);
    }
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