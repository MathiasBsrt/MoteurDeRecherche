#ifndef PILE_DESC_AUDIO_H_INCLUS 

#define PILE_DESC_AUDIO_H_INCLUS

#include <stdio.h>
#include <stdlib.h>
#include "descripteur.h"

typedef struct cellule_t{
  DESC_AUDIO elem;
  struct cellule_t* suivant;
}CELLULE;
typedef CELLULE* PILE;


PILE init_PILE();
void affiche_PILE(PILE pile);
int PILE_estVide(PILE pile);
PILE emPILE(PILE pile, DESC_AUDIO elem);
PILE dePILE(PILE pile, DESC_AUDIO* elem);
//PILE saisir_PILE();

#endif