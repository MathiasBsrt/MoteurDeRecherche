#include "descripteur.h"
#include <stdio.h>

void affiche_Descripteur_image(Descripteur_image e){
    printf("identifiant : %d \n", e.id);
    printf("affiche de de l'histogramme :\n");
    for (int i = 0; i < tailleHistogramme; i++)
    {
        printf("%d : %d fois",i,e.histogramme[i]);
    }
    printf("\n");

}

