#define tailleHistogramme 64
#define quantificateur 2
#include <stdlib.h>
#include <stdio.h> 

typedef struct Descripteur_t{
    int id;
    int histogramme[tailleHistogramme];
}Descripteur;

void affiche_Descripteur(Descripteur e);
Descripteur saisir_Descripteur();
void affecter_Descripteur(Descripteur e1, Descripteur e2);
int compareDescripteur(Descripteur e1, Descripteur e2);
