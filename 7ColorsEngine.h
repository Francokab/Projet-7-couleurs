#ifndef COLORSENGINE_H
#define COLORSENGINE_H
#define taillem 20
#define nb_coul 7

typedef struct joueur {
  char Symbole;
  int nbCase;
  float pourcentage;
} joueur;

extern char couleur[nb_coul];
extern char monde[taillem][taillem];

joueur* createJoueur(int numero);
void initialisation(joueur joueur1, joueur joueur2);
void affichage(joueur* joueur1, joueur* joueur2);
void majCoup(char couleur, joueur joueur1);

#endif