#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "7ColorsEngine.h"
#include "Color.h"

char couleur[nb_coul] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
char monde[taillem][taillem];

joueur* createJoueur(int numero, int IA) {
  joueur* j = malloc(sizeof(joueur));
  char symbole;
  printf("Joueur %d, créer votre personnage : rentrer un caractère\n",numero);
  scanf(" %c", &symbole);
  j->Symbole = symbole;
  j->numero = numero;
  j->nbCase = 0;
  j->pourcentage = 0.;
  j->IA = IA;
  return j;
}

void initialisation(joueur joueur1, joueur joueur2) {
  srand(time(NULL)); // initialiser la fonction random
  monde[taillem - 1][0] = joueur1.Symbole; // placement du premier joueur
  monde[0][taillem - 1] = joueur2.Symbole; // placement du deuxième joueur
  for (int i = 0; i < taillem; i++) { //
    for (int j = 0; j < taillem; j++) {
      if ((i != taillem - 1 || j != 0) && (i != 0 || j != taillem - 1)) { // on ne change pas les cases des joueurs
        monde[i][j] = couleur[rand() % nb_coul]; // on remplace la case aléatoirement par une des couleurs
      }
    }
  }
}

void affichage(joueur *joueur1, joueur *joueur2) {
  printf("\033[H\033[2J"); // on clear le screen
  printf(" Jeu par Infogrames Entertainment ©\n");
  joueur1->nbCase = 0;
  joueur2->nbCase = 0;
  joueur1->pourcentage = 0;
  joueur2->pourcentage = 0;
  for (int i = 0; i < taillem; i++) { //
    for (int j = 0; j < taillem; j++) {
      colorize(monde[i][j]); // on affiche la couleur
      if (monde[i][j] == joueur1->Symbole) {
        joueur1->nbCase += 1; // on récupère l'occupation du joueur 1 sur le plateau
      }
      else if (monde[i][j] == joueur2->Symbole) {
        joueur2->nbCase += 1; // on récupère l'occupation du joueur 2 sur le plateau
      }
    }
    printf("\n");// on saute une ligne
  }
  printf("\n");
  joueur1->pourcentage = (float)joueur1->nbCase * 100 / (taillem * taillem);
  joueur2->pourcentage = (float)joueur2->nbCase * 100 / (taillem * taillem);
  printf("le joueur 1 occupe %f pourcents et le joueur 2 occupe %f pourcents\n", joueur1->pourcentage, joueur2->pourcentage);
}

void majCoup(char couleur, joueur joueur1) { // si la couleur selectionné par le joueur est adjacente à une case joueur, on la change en case joueur
  int test = 1;
  while (test == 1) {
    test = 0;
    for (int i = 0; i < taillem; i++) { // on parcourt le monde
      for (int j = 0; j < taillem; j++) {
        if (monde[i][j] == couleur) { // si la case est de la couleur sélectionné
          if (monde[i - 1][j] == joueur1.Symbole && i != 0) { // si la case à gauche est de la même couleur
            monde[i][j] = joueur1.Symbole;
            test = 1;//on reparcourt le monde
          }
          else if (monde[i + 1][j] == joueur1.Symbole && i != taillem - 1) { // si la case à droite est de la même couleur
            monde[i][j] = joueur1.Symbole;
            test = 1;//on reparcourt le monde
          }
          else if (monde[i][j - 1] == joueur1.Symbole && j != 0) { // si la case au dessus est de la même couleur
            monde[i][j] = joueur1.Symbole;
            test = 1;//on reparcourt le monde
          }
          else if (monde[i][j + 1] == joueur1.Symbole && j != taillem - 1) { // si la case en dessous est de la même couleur
            monde[i][j] = joueur1.Symbole;
            test = 1;//on reparcourt le monde
          }
        }
      }
    }
  }
}

char getColor(joueur* joueur1){
  char couleur_tour;
  switch (joueur1->IA){
    case 0:
      printf("Joueur %d %c, indiquer la couleur que vous voulez récupérer\n", joueur1->numero, joueur1->Symbole);
      scanf(" %c", &couleur_tour);
      break;
    case 1:
      couleur_tour = couleur[rand() % nb_coul];
      break;
  }
  return couleur_tour; 
}

void doRound(joueur* joueur1){
  int compa = 0;
  char couleur_tour;
  while (!compa) { // on vérfie que la couleur soit bien une des couleurs du plateau
    couleur_tour = getColor(joueur1);
    for (int i = 0; i < nb_coul; i++) { // on compare pour toute la liste de couleur
      compa += (1 && (couleur_tour == couleur[i]));
    }
  }
  majCoup(couleur_tour, *joueur1);

}