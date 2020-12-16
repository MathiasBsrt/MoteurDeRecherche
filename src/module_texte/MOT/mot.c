#include "mot.h"

void affiche_MOT(MOT e)
{
    printf("\nmot : %s\tnombre d'occurrence : %d\n",e.mot, e.nbr_occurrence);
}

void saisir_MOT(MOT *e)
{
    printf("entrer un mot");
    scanf("%s",e->mot);
}

MOT affecter_MOT(char word[MAX_WORD])
{
    MOT retour;
    strcpy(retour.mot,word);
    retour.nbr_occurrence=0;
    return retour;
}

int compare_MOT(MOT a,MOT b)
{
    return(!strcmp(a.mot,b.mot));
}

int compare_MOT_avec_occ(MOT a,MOT b)
{
    return (!strcmp(a.mot,b.mot) && a.nbr_occurrence==b.nbr_occurrence);
}
