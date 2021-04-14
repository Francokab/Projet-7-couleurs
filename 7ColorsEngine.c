#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "7ColorsEngine.h"
#include "Color.h"
#include "CreationMonde.h"

void initialisation(monde* m, joueur* joueur1, joueur* joueur2) {
  m->joueur1 = joueur1;
  m->joueur2 = joueur2;
  setCell(m, m->taille_monde-1, 0, m->joueur1->Symbole); // placement du premier joueur
  setCell(m, 0, m->taille_monde-1, m->joueur2->Symbole); // placement du deuxième joueur
  for (int i = 0; i < m->taille_monde; i++) { //
    for (int j = 0; j < m->taille_monde; j++) {
      if ((i != m->taille_monde - 1 || j != 0) && (i != 0 || j != m->taille_monde - 1)) { // on ne change pas les cases des joueurs
        setCell(m, i, j, couleur[rand() % nb_coul]); // on remplace la case aléatoirement par une des couleurs
      }
    }
  }
  resetPlateauSimulé(m);
}

void affichage(monde* m, int Affichage_type) {
  if (Affichage_type){
    printf("\033[H\033[2J"); // on clear le screen
    printf(" Jeu par Infogrames Entertainment ©\a\n");
  }
  m->joueur1->nbCase = 0;
  m->joueur2->nbCase = 0;
  m->joueur1->pourcentage = 0;
  m->joueur2->pourcentage = 0;
  for (int i = 0; i < m->taille_monde; i++) { //
    for (int j = 0; j < m->taille_monde; j++) {
      if (Affichage_type) {
        colorize(getCell(m, i, j)); // on affiche la couleur
      }
      if (getCell(m, i, j) == m->joueur1->Symbole) {
        m->joueur1->nbCase += 1; // on récupère l'occupation du joueur 1 sur le plateau
      }
      else if (getCell(m, i, j) == m->joueur2->Symbole) {
        m->joueur2->nbCase += 1; // on récupère l'occupation du joueur 2 sur le plateau
      }
    }
    if (Affichage_type){
      printf("\n");// on saute une ligne
    }
  }
  if (Affichage_type){
    printf("\n");
  }
  m->joueur1->pourcentage = (float)m->joueur1->nbCase * 100 / (m->taille_monde * m->taille_monde);
  m->joueur2->pourcentage = (float)m->joueur2->nbCase * 100 / (m->taille_monde * m->taille_monde);
  if (Affichage_type){
    printf("le joueur 1 occupe %f pourcents et le joueur 2 occupe %f pourcents\n", m->joueur1->pourcentage, m->joueur2->pourcentage);
  }
}

void majCoup(monde* m, char couleur, joueur joueur1) { // si la couleur selectionné par le joueur est adjacente à une case joueur, on la change en case joueur
  int test = 1;
  while (test == 1) {
    test = 0;
    for (int i = 0; i < m->taille_monde; i++) { // on parcourt le monde
      for (int j = 0; j < m->taille_monde; j++) {
        if (getCell(m, i, j) == couleur) { // si la case est de la couleur sélectionné
          if (getCell(m, i - 1, j) == joueur1.Symbole && i != 0) { // si la case à gauche est de la même couleur
            setCell(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
          }
          else if (getCell(m, i + 1, j) == joueur1.Symbole && i != m->taille_monde - 1) { // si la case à droite est de la même couleur
            setCell(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
          }
          else if (getCell(m, i, j - 1) == joueur1.Symbole && j != 0) { // si la case au dessus est de la même couleur
            setCell(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
          }
          else if (getCell(m, i, j + 1) == joueur1.Symbole && j != m->taille_monde - 1) { // si la case en dessous est de la même couleur
            setCell(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
          }
        }
      }
    }
  }
}

int prediction(monde* m, char couleur, joueur joueur1) { // si la couleur selectionné par le joueur est adjacente à une case joueur, on la change en case joueur
  int nbCase = 0;
  int test = 1;
  while (test == 1) {
    test = 0;
    for (int i = 0; i < m->taille_monde; i++) { // on parcourt le monde
      for (int j = 0; j < m->taille_monde; j++) {
        if (getCellSimulé(m, i, j) == couleur) { // si la case est de la couleur sélectionné
          if (getCellSimulé(m, i - 1, j) == joueur1.Symbole && i != 0) { // si la case à gauche est de la même couleur
            setCellSimulé(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
            nbCase++;
          }
          else if (getCellSimulé(m, i + 1, j) == joueur1.Symbole && i != m->taille_monde - 1) { // si la case à droite est de la même couleur
            setCellSimulé(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
            nbCase++;
          }
          else if (getCellSimulé(m, i, j - 1) == joueur1.Symbole && j != 0) { // si la case au dessus est de la même couleur
            setCellSimulé(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
            nbCase++;
          }
          else if (getCellSimulé(m, i, j + 1) == joueur1.Symbole && j != m->taille_monde - 1) { // si la case en dessous est de la même couleur
            setCellSimulé(m, i, j, joueur1.Symbole);
            test = 1;//on reparcourt le monde
            nbCase++;
          }
        }
      }
    }
  }
  return nbCase;
}

char predictionMax(monde* m, joueur joueur1){
  char couleurMax;
  int max = 0;
  int pre;
  for (int i = 0; i<nb_coul; i++){
    resetPlateauSimulé(m);
    pre = prediction(m, couleur[i], joueur1);
    resetPlateauSimulé(m);
    if (pre > max){
      max = pre;
      couleurMax = couleur[i];
    }
  }
  return couleurMax;
}

char getColor(monde* m, joueur* joueur1){
  char couleur_tour;
  switch (joueur1->IA){
    case 0:
      printf("Joueur %d %c, indiquer la couleur que vous voulez récupérer\n", joueur1->numero, joueur1->Symbole);
      scanf(" %c", &couleur_tour);
      break;
    case 1:
      do {
        couleur_tour = couleur[rand() % nb_coul];
        resetPlateauSimulé(m);
      } while(!prediction(m, couleur_tour, *joueur1));
      break;
    case 2:
      couleur_tour = predictionMax(m, *joueur1);
    break;
  }
  return couleur_tour; 
}

void doRound(monde* m, joueur* joueur1){
  int compa = 0;
  char couleur_tour;
  while (!compa) { // on vérfie que la couleur soit bien une des couleurs du plateau
    couleur_tour = getColor(m, joueur1);
    for (int i = 0; i < nb_coul; i++) { // on compare pour toute la liste de couleur
      compa += (1 && (couleur_tour == couleur[i]));
    }
  }
  majCoup(m, couleur_tour, *joueur1);

}

int playGame(int taille_monde, int IA1, int IA2, int Affichage_type){
  monde monde1 = *createMonde(taille_monde);
  joueur joueur1 = *createJoueur(1,IA1);
  joueur joueur2 = *createJoueur(2,IA2);
  initialisation(&monde1, &joueur1, &joueur2);
  affichage(&monde1, Affichage_type); // on affiche le monde
  printf("t");
  int tour = 1;
  while (joueur1.pourcentage <= 50 && joueur2.pourcentage<=50) { // condtions de victoire : avoir plus de 50% du territoire pour gagner
    if (Affichage_type) {
      printf("Tour %d :\n", tour); // on affiche le monde
    }
    // si le tour est pair, le joueur 2 joue
    // si le tour est impair, le joueur 1 joue
    (tour % 2) ? doRound(&monde1, &joueur1) : doRound(&monde1, &joueur2);
    affichage(&monde1, Affichage_type); // on affiche le monde
    tour++;
  }
  if (joueur1.pourcentage>50){
    if (Affichage_type){
      printf("le joueur 1 a gagné\n");
    }
    return 1;
  }
  else if (joueur2.pourcentage>50){
    if (Affichage_type){
      printf("le joueur 2 a gagné\n");
    }
    return 2;
  }
  return 0;
}