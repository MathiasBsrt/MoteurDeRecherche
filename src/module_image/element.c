#include "element.h"
#include <stdio.h>

void affiche_ELEMENT(ELEMENT e){
    printf("Catégorie : %c et identifiant : %d", e.categorie, e.id);
}

ELEMENT saisir_ELEMENT(){
  ELEMENT e;
   //do{
        printf("Saisir la catégorie (Wagon : W, Wagon restaurant : R, Locomotive  : L) à ajouter \n");
        scanf(" %c",&e.categorie);
   //}while(e.categorie != 'W' | e.categorie != 'R' | e.categorie != 'L');

    printf("Saisir l'identifiant de l'element (entier positif) \n");
    scanf("%d",&e.id);
   
    //affiche_ELEMENT(e);
    return e;
}

void affecter_ELEMENT(ELEMENT e1, ELEMENT e2){
    e2.categorie = e1.categorie;
    e2.id = e1.id;

}
// retourne 0 si e1 et e2 sont égaux
// retourne 1 si e1> e2 (basé sur l'id)
//retourne -1 si e1<e2 (basé sur l'id)
int compareELEMENT(ELEMENT e1, ELEMENT e2){
    if(e1.categorie == e2.categorie && e1.id == e2.id){
        return 0;
    }
    else if(e1.id>e2.id){
        return 1;
    }
    else{
        return -1;
    }
}



