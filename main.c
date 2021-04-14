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
    printf("x");
    int a = playGame(6,2,2,1);
    printf("Partie %d : Victoire joueur %d", i, a);
    switch (a){
      case 1:
        WinJ1++;
        printf("a");
        break;
      case 2:
        WinJ2++;
        printf("b");
        break;
    }
    printf("%d %d", WinJ1, WinJ2);
    printf("z\n");
  }
  printf("le joueur 1 a gagné %d fois, le joueur 2 a gagné %d fois.", WinJ1, WinJ2);
  return 0;
}