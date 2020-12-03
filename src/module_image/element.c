#include "element.h"

void affiche_ELEMENT(ELEMENT elem){
  printf("%s",elem.valeurC);
  printf("%d",elem.valeurNb);
}

ELEMENT saisir_ELEMENT(){
  ELEMENT elem;
  printf("Entrez la valeur numérique de l'élément");
  scanf("%d",&elem.valeurNb);
  printf("Entrez la valeur char de l'élément");
  scanf("%s",elem.valeurC);

  return elem;
}

ELEMENT affect_ELEMENT(int val,char* valC){
  ELEMENT elem;
  elem.valeurNb=val;
  strcpy(elem.valeurC, valC);
  return elem;
}

int compare_ELEMENT(ELEMENT elem1,ELEMENT elem2){
  return (elem1.valeurNb==elem2.valeurNb && (strcmp(elem1.valeurC,elem2.valeurC)==0));
}
