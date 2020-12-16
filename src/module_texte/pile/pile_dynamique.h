#include "../MOT/mot.h"

typedef struct s_Cellule
{
    MOT elt;
    struct s_Cellule *suivant;
}Cellule;

typedef Cellule* PILE;

typedef struct s_Descripteur
{
    int id;
    PILE pile_mot;
    int nbr_mots_retenus;
    int nombre_mots_total;
    struct s_Descripteur* suivant;
}Descripteur_texte;

typedef Descripteur_texte* PILE_descripteur_texte;

PILE dePILE(PILE p, MOT *elt);
PILE saisir_PILE();
PILE emPILE(PILE p, MOT elt);
PILE init_pile();
void affiche_PILE(PILE p);
int PILE_estVide(PILE p);
int estDanslaPile(PILE p,char *buffer);

PILE_descripteur_texte init_PILE_desc();
int PILE_desc_estVide(PILE_descripteur_texte d);
void EMPILE_desc(PILE p, PILE_descripteur_texte *d);
void enregistre_PILE_Desc(PILE_descripteur_texte p, char *save_descripteurs_textes);
