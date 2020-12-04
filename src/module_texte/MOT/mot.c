#include "mot.h"

void affiche_MOT(MOT e)
{
    printf("\n%s\n",e.mot);
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
    return retour;
}

int compare_MOT(MOT a,MOT b)
{
    return(!strcmp(a.mot,b.mot));
}
