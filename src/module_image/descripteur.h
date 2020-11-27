#include <stdlib.h>

typedef struct ELEMENT_t{
    char categorie;
    unsigned int id;
}ELEMENT;

void affiche_ELEMENT(ELEMENT e);
ELEMENT saisir_ELEMENT();
void affecter_ELEMENT(ELEMENT e1, ELEMENT e2);
int compareELEMENT(ELEMENT e1, ELEMENT e2);