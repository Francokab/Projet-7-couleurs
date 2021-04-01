#include <time.h>
#include <stdlib.h>
#include "7ColorsEngine.h"

char couleur[nb_coul]={'A','B','C','D','E','F','G'};
char monde[taillem][taillem];

joueur* createJoueur(){
  joueur* j=malloc(sizeof(joueur));
  char symbole;
  printf("Créer votre personnages : rentrer un caractère\n");
  scanf(" %c",&symbole);
  j->Symbole = symbole;
  j->nbCase = 0;
  j->pourcentage = 0.;
  return j;
}

void initialisation(joueur joueur1, joueur joueur2){
  srand(time(NULL)); // initialiser la fonction random
  monde[taillem-1][0]=joueur1.Symbole; // placement du premier joueur
  monde[0][taillem-1]=joueur2.Symbole; // placement du deuxième joueur
	for (int i = 0; i < taillem; i++){ // 
		for (int j = 0; j < taillem; j++){
			if ((i!= taillem-1 || j!= 0) && (i!= 0 || j != taillem-1)){ // on ne change pas les cases des joueurs
				monde[i][j]=couleur[rand()%nb_coul]; // on remplace la case aléatoirement par une des couleurs
        }
      }
  }
}

void affichage(joueur *joueur1,joueur *joueur2){
  printf("\033[H\033[2J"); // on clear le screen
  joueur1->nbCase = 0;
  joueur2->nbCase = 0;
  joueur1->pourcentage = 0;
  joueur2->pourcentage = 0;
  for (int i = 0; i < taillem; i++){ // 
		for (int j = 0; j < taillem; j++){
      printf("%c", monde[i][j]); // on affiche la couleur 
      if (monde[i][j]==joueur1->Symbole){
        joueur1->nbCase+=1; // on récupère l'occupation du joueur 1 sur le plateau
      }
      else if(monde[i][j]==joueur2->Symbole){
        joueur2->nbCase=1; // on récupère l'occupation du joueur 2 sur le plateau
      }
      }
    printf("\n");// on saute une ligne
  }
  printf("\n");
  joueur1->pourcentage=(float)joueur1->nbCase*100/(taillem*taillem);
  joueur2->pourcentage=(float)joueur2->nbCase*100/(taillem*taillem);
  printf("le joueur 1 occupe %f pourcents et le joueur 2 occupe %f pourcents\n",joueur1->pourcentage,joueur2->pourcentage);
}

void majCoup(char couleur,joueur joueur1){ // si la couleur selectionné par le joueur est adjacente à une case joueur, on la change en case joueur 
  int test = 1;
  while (test == 1){
    test = 0;
    for (int i = 0; i < taillem; i++){ // on parcourt le monde
		  for (int j = 0; j < taillem; j++){
        if (monde[i][j]==couleur){ // si la case est de la couleur sélectionné
          if(monde[i-1][j]==joueur1.Symbole && i!=0){ // si la case à gauche est de la même couleur
            monde[i][j]=joueur1.Symbole;
            test = 1;
          }
          else if(monde[i+1][j]==joueur1.Symbole && i!=taillem-1){// si la case à droite est de la même couleur
            monde[i][j]=joueur1.Symbole;
            test = 1;
          }
          else if(monde[i][j-1]==joueur1.Symbole && j!=0){// si la case au dessus est de la même couleur
            monde[i][j]=joueur1.Symbole;
            test = 1;
          }
          else if(monde[i][j+1]==joueur1.Symbole && j!=taillem-1){// si la case en dessous est de la même couleur
            monde[i][j]=joueur1.Symbole;
            test = 1;
          }
        }
      }
    }
  }  
}