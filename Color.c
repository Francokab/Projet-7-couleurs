#include "Color.h"
#include <stdio.h>

// Fonctions pour imprimer un character avec un fond d'une certaine couleur
void black(char c){
  printf(BLKHB);
  printf(" %c ",c);
  printf(reset);
}

void red(char c){
  printf(REDHB);
  printf(" %c ",c);
  printf(reset);
}

void green(char c){
  printf(GRNHB);
  printf(" %c ",c);
  printf(reset);
}

void yellow(char c){
  printf(YELHB);
  printf(" %c ",c);
  printf(reset);
}

void blue(char c){
  printf(BLUHB);
  printf(" %c ",c);
  printf(reset);
}

void magenta(char c){
  printf(MAGHB);
  printf(" %c ",c);
  printf(reset);
}

void cyan(char c){
  printf(CYNHB);
  printf(" %c ",c);
  printf(reset);
}

void white(char c){
  printf(WHTHB);
  printf(" %c ",c);
  printf(reset);
}

// Fonction qui print un character d'une certaine couleur en fonction de quelle lettre c'est
void colorize(char c){
  switch (c){
    case 'A':
      red(c);
      break;
    case 'B':
      green(c);
      break;
    case 'C':
      yellow(c);
      break;
    case 'D':
      blue(c);
      break;
    case 'E':
      magenta(c);
      break;
    case 'F':
      cyan(c);
      break;
    case 'G':
      white(c);
      break;
    default:
      printf(" %c ",c);
      break;
  }
}
