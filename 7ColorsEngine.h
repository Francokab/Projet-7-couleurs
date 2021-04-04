#ifndef COLORSENGINE_H
#define COLORSENGINE_H
#define nb_coul 7

typedef struct joueur {
  char Symbole;
  int numero;
  int nbCase;
  float pourcentage;
  int IA;
} joueur;

typedef struct monde{
  int taille_monde;
  char *plateau;
  char *plateauSimulé;
  joueur* joueur1;
  joueur* joueur2;
}monde;


extern char couleur[nb_coul];

joueur* createJoueur(int numero, int IA);
monde* createMonde(int taille_monde);
char getCell(monde* m, int i, int j);
void setCell(monde* m, int i, int j, char c);
void resetPlateauSimulé(monde* m);
char getCellSimulé(monde* m, int i, int j);
void setCellSimulé(monde* m, int i, int j, char c);
void initialisation(monde* m, joueur* joueur1, joueur* joueur2);
void affichage(monde* m);
void majCoup(monde* m, char couleur, joueur joueur1);
int prediction(monde* m, char couleur, joueur joueur1);
char predictionMax(monde* m, joueur joueur1);
char getColor(monde* m, joueur* joueur1);
void doRound(monde* m, joueur* joueur1);

#endif