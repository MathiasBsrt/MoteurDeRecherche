#include "descripteur.h"
#include <stdio.h>

void affiche_Descripteur(Descripteur e){
    printf("identifiant : %d \n", e.id);
    printf("affiche de de l'histogramme :\n");
    for (int i = 0; i < tailleHistogramme; i++)
    {
        printf("%d : %d fois",i,e.histogramme[i]);
    }
    printf("\n");
    
}

// retourne 0 si e1 et e2 sont égaux
// retourne 1 si e1> e2 (basé sur l'id)
//retourne -1 si e1<e2 (basé sur l'id)
int compareDescripteur(Descripteur e1, Descripteur e2){
   /* if(e1.categorie == e2.categorie && e1.id == e2.id){
        return 0;
    }
    else if(e1.id>e2.id){
        return 1;
    }
    else{
        return -1;
    }*/
    return 0;
}



