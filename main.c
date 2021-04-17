#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "7ColorsEngine.h"
#include "CreationMonde.h"
#define tour_max 100



//L'IA ne sait pas quoi faire si il n'a pas de mouvement possible
//à regler d'urgence

int main() {
  srand(time(0)); // initialiser la fonction random
  int WinJ1 = 0;
  int WinJ2 = 0;
  for (int i = 0; i<100; i = i+1){
    int a = playGame(30,2,2,0);
    printf("Partie %d : Victoire %d\n", i, a);
    switch (a){
      case 1:
        WinJ1++;
        break;
      case 2:
        WinJ2++;
        break;
    }
  }
  printf("le joueur 1 a gagné %d fois, le joueur 2 a gagné %d fois.", WinJ1, WinJ2);
  return 0;
}