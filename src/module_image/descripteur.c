#include "descripteur.h"
#include <stdio.h>

void affiche_Descripteur(Descripteur e){
    printf("Catégorie : %c et identifiant : %d", e.categorie, e.id);
}

Descripteur saisir_Descripteur(){
  Descripteur e;
   //do{
        printf("Saisir la catégorie (Wagon : W, Wagon restaurant : R, Locomotive  : L) à ajouter \n");
        scanf(" %c",&e.categorie);
   //}while(e.categorie != 'W' | e.categorie != 'R' | e.categorie != 'L');

    printf("Saisir l'identifiant de l'Descripteur (entier positif) \n");
    scanf("%d",&e.id);
   
    //affiche_Descripteur(e);
    return e;
}

void affecter_Descripteur(Descripteur e1, Descripteur e2){
    e2.categorie = e1.categorie;
    e2.id = e1.id;

}
// retourne 0 si e1 et e2 sont égaux
// retourne 1 si e1> e2 (basé sur l'id)
//retourne -1 si e1<e2 (basé sur l'id)
int compareDescripteur(Descripteur e1, Descripteur e2){
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



