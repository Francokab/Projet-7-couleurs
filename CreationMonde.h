#ifndef CREATIONMONDE_H
#define CREATIONMONDE_H
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
  char *plateauSimule;
  joueur* joueur1;
  joueur* joueur2;
}monde;


extern char couleur[nb_coul];

joueur* createJoueur(int numero, int IA);
monde* createMonde(int taille_monde);
char getCell(monde* m, int i, int j);
void setCell(monde* m, int i, int j, char c);
void resetPlateauSimule(monde* m);
char getCellSimule(monde* m, int i, int j);
void setCellSimule(monde* m, int i, int j, char c);

#endif