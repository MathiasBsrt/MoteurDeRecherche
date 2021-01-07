#include "moteur.h"

int comparaison(Descripteur d1, Descripteur d2, int seuil){
    int totalValeurs = 40000; //défini par test pour RGB, vari en fonction de la taille de l'image ?
    //Méthode de comparaison : intersection des 2 histogrammes (cf cahier des charges) => comment faire l'intersection des 2 tableaux ? revient à une différence ?
    // voir ici : https://openclassrooms.com/forum/sujet/intersection-de-2-tableaux

    //SI ils sont sctriement identique par id
    if(d1.id == d2.id){
        return 0;
    }
    
    //On compare l'histogramme
    // On calcul le pourcentage de difference

    //On fait la différence entre les 2 histogrammes => donne un tableau avec les valeurs d'écarts
    int histoDiff[tailleHistogramme];
    int diff = 0; // Différence entre les deux histogrammes
    for (int i = 0; i < tailleHistogramme; i++)
    {
        histoDiff[i] = abs(d1.histogramme[i] - d1.histogramme[i]);
    }
    
    //Si pourcentage == 0 : égal
    if(diff==0){
        return 0;
    }
    else if(diff<seuil){
        return 1;
    }
    else{
        return 2;
    }

}

int main(int argc, char const *argv[])
{
    PILE p;
    charger_PILE_Desc(&p,"base_descripteur_image");
    
    //On envoie 2 descriteurs pour les comaprer et tester

    return 0;
}
