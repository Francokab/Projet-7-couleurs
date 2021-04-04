#ifndef COLORSENGINE_H
#define COLORSENGINE_H
#define taillem 40
#define nb_coul 7

typedef struct joueur {
  char Symbole;
  int numero;
  int nbCase;
  float pourcentage;
  int IA;
} joueur;


extern char couleur[nb_coul];
extern char monde[taillem][taillem];

joueur* createJoueur(int numero, int IA);
void initialisation(joueur joueur1, joueur joueur2);
void affichage(joueur* joueur1, joueur* joueur2);
void majCoup(char couleur, joueur joueur1);
char getColor(joueur* joueur1);
void doRound(joueur* joueur1);

#endif