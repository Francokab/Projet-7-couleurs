#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "7ColorsEngine.h"
#include "Color.h"

char couleur[nb_coul] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

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

monde* createMonde(int taille_monde){
  monde* m = malloc(sizeof(monde));
  m->taille_monde = taille_monde;
  m->plateau = malloc(taille_monde*taille_monde*sizeof(char));
  m->plateauSimulé = malloc(taille_monde*taille_monde*sizeof(char));
  return m;
}

char getCell(monde* m, int i, int j){
  return m->plateau[i + j * m->taille_monde];
}

void setCell(monde* m, int i, int j, char c){
  m->plateau[i + j * m->taille_monde] = c;
}

void resetPlateauSimulé(monde* m){
  for (int i = 0; i< m->taille_monde * m->taille_monde; i++){
    m->plateauSimulé[i] = m->plateau[i];
  }
}

char getCellSimulé(monde* m, int i, int j){
  return m->plateauSimulé[i + j * m->taille_monde];
}

void setCellSimulé(monde* m, int i, int j, char c){
  m->plateauSimulé[i + j * m->taille_monde] = c;
}

void initialisation(monde* m, joueur* joueur1, joueur* joueur2) {
  srand(time(NULL)); // initialiser la fonction random
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

void affichage(monde* m) {
  printf("\033[H\033[2J"); // on clear le screen
  printf(" Jeu par Infogrames Entertainment ©\n");
  m->joueur1->nbCase = 0;
  m->joueur2->nbCase = 0;
  m->joueur1->pourcentage = 0;
  m->joueur2->pourcentage = 0;
  for (int i = 0; i < m->taille_monde; i++) { //
    for (int j = 0; j < m->taille_monde; j++) {
      colorize(getCell(m, i, j)); // on affiche la couleur
      if (getCell(m, i, j) == m->joueur1->Symbole) {
        m->joueur1->nbCase += 1; // on récupère l'occupation du joueur 1 sur le plateau
      }
      else if (getCell(m, i, j) == m->joueur2->Symbole) {
        m->joueur2->nbCase += 1; // on récupère l'occupation du joueur 2 sur le plateau
      }
    }
    printf("\n");// on saute une ligne
  }
  printf("\n");
  m->joueur1->pourcentage = (float)m->joueur1->nbCase * 100 / (m->taille_monde * m->taille_monde);
  m->joueur2->pourcentage = (float)m->joueur2->nbCase * 100 / (m->taille_monde * m->taille_monde);
  printf("le joueur 1 occupe %f pourcents et le joueur 2 occupe %f pourcents\n", m->joueur1->pourcentage, m->joueur2->pourcentage);
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