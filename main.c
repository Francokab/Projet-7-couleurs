
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define taillem 30
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

void majCoup(char couleur, char joueur){ // si la couleur selectionné pa
  int test = 1;
  while (test == 1){
    test = 0;
    for (int i = 0; i < taillem; i++){
		  for (int j = 0; j < taillem; j++){
        if (monde[i][j]==couleur){
          if(monde[i-1][j]==joueur || monde[i][j+1]==joueur || monde[i+1][j]==joueur || monde[i][j-1]==joueur){
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
  affichage();
  char symbole_joueur;
  char couleur_tour;
  scanf("%d", symbole_joueur);
  scanf("%d", couleur_tour)
  majCoup(couleur_tour, char joueur)
  return 0;
}



