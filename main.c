
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define taillem 5
#define nb_coul 7
#define tour_max 10

char couleur[nb_coul]={'A','B','C','D','E','F','G'};
char monde[taillem][taillem];

void initialisation(char joueur1, char joueur2){
  srand(time(NULL)); // initialiser la fonction random
  monde[taillem-1][0]=joueur1; // placement du premier joueur
  monde[0][taillem-1]=joueur2; // placement du deuxième joueur
	for (int i = 0; i < taillem; i++){ // 
		for (int j = 0; j < taillem; j++){
			if ((i!= taillem-1 || j!= 0) && (i!= 0 || j != taillem-1)){ // on ne change pas les cases des joueurs
				monde[i][j]=couleur[rand()%nb_coul]; // on remplace la case aléatoirement par une des couleurs
        }
      }
  }
}

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
          if(monde[i-1][j]==joueur && i!=0){ // si la case à gauche est de la même couleur
            monde[i][j]=joueur;
            test = 1;
          }
          else if(monde[i+1][j]==joueur && i!=taillem-1){// si la case à droite est de la même couleur
            monde[i][j]=joueur;
            test = 1;
          }
          else if(monde[i][j-1]==joueur && j!=0){// si la case au dessus est de la même couleur
            monde[i][j]=joueur;
            test = 1;
          }
          else if(monde[i][j+1]==joueur && j!=taillem-1){// si la case en dessous est de la même couleur
            monde[i][j]=joueur;
            test = 1;
          }
        }
      }
    }
  }  
}


int main(){
  char joueur1;
  char joueur2;
  printf("Créer vos personnages (entré 2 caractères), le premier commence\n");
  scanf("%c %c",&joueur1,&joueur2);
  initialisation(joueur1,joueur2);
  affichage(); // on affiche le monde 
  char couleur_tour;
  int tour = 1;
	int compa;
  while (tour<tour_max){ // première condition (temporelle) : on se fixe un nombre de tour limité
		compa = 0;
    printf("tour %d \n",tour);
    if((tour % 2) == 1){ // si le tour est impair, le joueur 1 joue
			while (!compa){ // on vérfie que la couleur soit bien une des couleurs du plateau
      	printf("joueur 1 %c, indiquer la couleur que vous voulez récupérer\n",joueur1);
      	scanf(" %c", &couleur_tour);
				for (int i = 0; i < nb_coul; i++){ // on compare pour toute la liste de couleur
					 compa += (1 && (couleur_tour == couleur[i]));
				}
			}
      majCoup(couleur_tour, joueur1);
      affichage();
      tour++;
    }
    else{ // si le tour est pair, le joueur 2 joue
      printf("joueur 2 %c, indiquer la couleur que vous voulez récupérer\n",joueur2);
			while (!compa){ // on vérfie que la couleur soit bien une des couleurs du plateau
				printf("joueur 2 %c, indiquer la couleur que vous voulez récupérer\n",joueur2);
      	scanf(" %c", &couleur_tour);
				for (int i = 0; i < nb_coul; i++){ // on compare pour toute la liste de couleur
					 compa += (1 && (couleur_tour == couleur[i]));
				}
			}
      majCoup(couleur_tour, joueur2);
      affichage();
      tour++;
    }
  }

  return 0;
}


