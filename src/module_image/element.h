#include<stdio.h>
#include<string.h>

typedef struct ELEMENT_t{
  int valeurNb;
  char valeurC[30];
} ELEMENT;


ELEMENT saisir_ELEMENT();
void affiche_ELEMENT(ELEMENT elem);
ELEMENT affect_ELEMENT(int val,char* valC);
int compare_ELEMENT(ELEMENT elem1,ELEMENT elem2);
