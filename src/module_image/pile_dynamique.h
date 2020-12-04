#include <stdio.h>
#include <stdlib.h>
#include "descripteur.h"
typedef struct cellule_t{
  Descripteur elem;
  struct cellule_t* suivant;
}CELLULE;
typedef CELLULE* PILE;


PILE init_PILE();
void affiche_PILE(PILE pile);
int PILE_estVide(PILE pile);
PILE emPILE(PILE pile,Descripteur elem);
PILE dePILE(PILE pile, Descripteur* elem);
//PILE saisir_PILE();
