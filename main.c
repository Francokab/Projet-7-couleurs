
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define taillem 5
#define nb_coul 7

char couleur[nb_coul]={'A','B','C','D','E','F','G'};
char monde[taillem][taillem];

void affichage(){
  for (int i = 0; i < taillem; i++){ // 
		for (int j = 0; j < taillem; j++){
      printf("%c", monde[i][j]); // on affiche la couleur 
      }
    printf("\n");// on saute une ligne
  }
}

void majCoup(char couleur, char joueur){ // si la couleur selectionné par le joueur est adjacente à une case joueur, on la change en case joueur 
  int test = 1;
  while (test == 1){
    test = 0;
    for (int i = 0; i < taillem; i++){ // on parcourt le monde
		  for (int j = 0; j < taillem; j++){
        if (monde[i][j]==couleur){ // si la case est de la couleur sélectionné
          if(monde[i-1][j]==joueur && i!=0){
            monde[i][j]=joueur;
            test = 1;
          }
          else if(monde[i+1][j]==joueur && i!=taillem-1){
            monde[i][j]=joueur;
            test = 1;
          }
          else if(monde[i][j-1]==joueur && j!=0){
            monde[i][j]=joueur;
            test = 1;
          }
          else if(monde[i][j+1]==joueur && j!=taillem-1){
            monde[i][j]=joueur;
            test = 1;
          }
        }
      }
    }
  }  
}

int main(){
  srand(time(NULL)); // initialiser la fonction random
  monde[taillem-1][0]='v'; // placement du premier joueur
  monde[0][taillem-1]='^'; // placement du deuxième joueur
	for (int i = 0; i < taillem; i++){ // 
		for (int j = 0; j < taillem; j++){
			if ((i!= taillem-1 || j!= 0) && (i!= 0 || j != taillem-1)){ // on ne change pas les cases des joueurs
				monde[i][j]=couleur[rand()%nb_coul]; // on remplace la case aléatoirement par une des couleurs
        }
      }
  }
  affichage(); // on affiche ml emonde 
  char symbole_joueur;
  char couleur_tour;
  printf("indiquer le joueur et la couleur de la forme joueur couleur\n");
  scanf("%c %c", &symbole_joueur, &couleur_tour);
  majCoup(couleur_tour, symbole_joueur);
  affichage();
  return 0;
}



