#include "element.h"

typedef struct CEL CEL;
typedef struct CEL* PILE;

struct CEL{
    ELEMENT e;
    CEL *suivant;
};

PILE init_PILE();
void affichePILE(PILE p);
int PILE_estVide(PILE p);
PILE emPILE(PILE p, ELEMENT nouveau);
PILE dePILE(PILE p, ELEMENT * valeur);
PILE saisir_PILE();
