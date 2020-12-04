#include "../MOT/mot.h"

typedef struct s_Cellule
{
    MOT elt;
    struct s_Cellule *suivant;
}Cellule;

typedef Cellule* PILE;

PILE dePILE(PILE p, MOT *elt);
PILE saisir_PILE();
PILE emPILE(PILE p, MOT elt);
PILE init_pile();
void affiche_PILE(PILE p);
int PILE_estVide(PILE p);
int estDanslaPile(PILE p,char *buffer);