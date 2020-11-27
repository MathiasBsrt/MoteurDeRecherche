#include "descripteur.h"

typedef struct CEL CEL;
typedef struct CEL* PILE;

struct CEL{
    Descripteur e;
    CEL *suivant;
};

PILE init_PILE();
void affichePILE(PILE p);
int PILE_estVide(PILE p);
PILE emPILE(PILE p, Descripteur nouveau);
PILE dePILE(PILE p, Descripteur * valeur);
PILE saisir_PILE();
