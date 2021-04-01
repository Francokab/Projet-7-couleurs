#include <stdio.h>
#include "7ColorsEngine.h"
#define tour_max 100



void affichage(char joueur1,char joueur2){
  printf("\033[H\033[2J");
  float nb_joueur1=0;
  float nb_joueur2=0;
  float pc_joueur1=0;
  float pc_joueur2=0;
  for (int i = 0; i < taillem; i++){ // 
		for (int j = 0; j < taillem; j++){
      printf("%c", monde[i][j]); // on affiche la couleur 
      if (monde[i][j]==joueur1){
        nb_joueur1+=1; // on récupère l'occupation du joueur 1 sur le plateau
      }
      else if(monde[i][j]==joueur2){
        nb_joueur2+=1; // on récupère l'occupation du joueur 2 sur le plateau
      }
      }
    printf("\n");// on saute une ligne
  }
  printf("\n");
  pc_joueur1=nb_joueur1*100/(taillem*taillem);
  pc_joueur2=nb_joueur2*100/(taillem*taillem);
  printf("le joueur 1 occupe %f pourcents et le joueur 2 occupe %f pourcents\n",pc_joueur1,pc_joueur2);
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
  scanf(" %c %c",&joueur1,&joueur2);
  initialisation(joueur1,joueur2);
  affichage(joueur1,joueur2); // on affiche le monde 
  char couleur_tour;
  int tour = 1;
	int compa;
  int couleur_j1=0;
  int couleur_j2=0;
  while (tour<=tour_max){ // première condition (temporelle) : on se fixe un nombre de tour limité
		compa = 0;
    printf("tour %d \n",tour);
    if((tour % 2) == 1){ // si le tour est impair, le joueur 1 joue
			while (!compa){ // on vérfie que la couleur soit bien une des couleurs du plateau
      	printf(" joueur 1 %c, indiquer la couleur que vous voulez récupérer\n",joueur1);
      	scanf(" %c", &couleur_tour);
				for (int i = 0; i < nb_coul; i++){ // on compare pour toute la liste de couleur
					 compa += (1 && (couleur_tour == couleur[i]));
				}
			}
      majCoup(couleur_tour, joueur1);
      affichage(joueur1,joueur2);
    }
    else{ // si le tour est pair, le joueur 2 joue
			while (!compa){ // on vérfie que la couleur soit bien une des couleurs du plateau
				printf(" joueur 2 %c, indiquer la couleur que vous voulez récupérer\n",joueur2);
      	scanf(" %c", &couleur_tour);
				for (int i = 0; i < nb_coul; i++){ // on compare pour toute la liste de couleur
					 compa += (1 && (couleur_tour == couleur[i]));
				}
			}
      majCoup(couleur_tour, joueur2);
      affichage(joueur1,joueur2);
    }
		tour++;
  }
  return 0;
}