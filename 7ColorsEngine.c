#include "7ColorsEngine.h"
#include <time.h>
#define taillem 5
#define nb_coul 7

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