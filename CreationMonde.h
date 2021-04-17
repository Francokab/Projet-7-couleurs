#ifndef CREATIONMONDE_H
#define CREATIONMONDE_H
#define nb_coul 7 //nombre de couleur différente

typedef struct joueur { //représente un joueur
  char Symbole; // le symbole que le joueur utilise pour son affichage
  int numero; // joueur 1 ou 2 (utilisé seulement pour l'affichage)
  int nbCase; // nombre de case qu'à le joueur à une certain moment
  float pourcentage; // le pourcentage des cases que le joueur a
  int IA; // 0 si le joueur est humain, 1 si aléatoire, 2 si glouton
} joueur;

typedef struct monde{ // représente le monde
  int taille_monde; //taille du plateau de jeu carré
  char *plateau; // tableau contenant toute les cases du plateau
  char *plateauSimule; // plateau que l'on peut modifier sans affecter le vrai
  joueur* joueur1; // les deux joueur qui sont dans le monde (pas utilisé très souvent)
  joueur* joueur2;
}monde;


extern char couleur[nb_coul]; // dit les symboles de chaque couleur

joueur* createJoueur(int numero, int IA); //créer un joueur
monde* createMonde(int taille_monde); //crée le monde
void freeMonde(monde* m, joueur* joueur1, joueur* joueur2); // libère le monde et les joueur
char getCell(monde* m, int i, int j); //retourne la valeur d'une case du plateau
void setCell(monde* m, int i, int j, char c); // change la valeur d'une case du plateau
void resetPlateauSimule(monde* m); // copie le plateau sur le plateau simule
char getCellSimule(monde* m, int i, int j); // retourne la valeur d'une case du plateau simule
void setCellSimule(monde* m, int i, int j, char c); // change la valeur d'une case du plateau simule

#endif