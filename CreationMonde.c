#include <stdlib.h>
#include <stdio.h>
#include "CreationMonde.h"


char couleur[nb_coul] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

joueur* createJoueur(int numero, int IA) {
  joueur* j = malloc(sizeof(joueur));  //on assigne l'espace memoire pour le joueur
  char symbole;
  // on determine le symbole utilisé par le joueur
  if (numero == 1){
    symbole = 'V';
  }
  else if (numero == 2){
    symbole = '^';
  }
  else {
    printf("Joueur %d, créer votre personnage : rentrer un caractère\n",numero);
    scanf(" %c", &symbole);
  }
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
  m->plateauSimule = malloc(taille_monde*taille_monde*sizeof(char));
  return m;
}

void freeMonde(monde* m, joueur* joueur1, joueur* joueur2){
  free(joueur1);
  free(joueur2);
  free(m->plateau);
  free(m->plateauSimule);
  free(m);
}

char getCell(monde* m, int i, int j){
  return m->plateau[i + j * m->taille_monde];
}

void setCell(monde* m, int i, int j, char c){
  m->plateau[i + j * m->taille_monde] = c;
}

void resetPlateauSimule(monde* m){
  for (int i = 0; i< m->taille_monde * m->taille_monde; i++){
    m->plateauSimule[i] = m->plateau[i];
  }
}

char getCellSimule(monde* m, int i, int j){
  return m->plateauSimule[i + j * m->taille_monde];
}

void setCellSimule(monde* m, int i, int j, char c){
  m->plateauSimule[i + j * m->taille_monde] = c;
}