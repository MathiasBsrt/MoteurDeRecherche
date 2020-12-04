#include "pile_dynamique.h"

PILE init_pile()
{
    PILE p;
    p = NULL;
    return p;
}

int PILE_estVide(PILE p)
{
    return (p == NULL);
}

void affiche_PILE(PILE p)
{
    if (PILE_estVide(p))
        fprintf(stderr, "La pile est vide\n");

    else
    {
        Cellule *parcour = p;
        printf("\n\n\t AFFICHAGE PILE\n");
        do
        {
            affiche_MOT(parcour->elt);
            parcour = parcour->suivant;
        } while (parcour != NULL);
        printf("\n");
    }
}

PILE emPILE(PILE p, MOT elt)
{
    Cellule *cel = malloc(sizeof(Cellule));
    cel->suivant = NULL;
    cel->elt = elt;
    if (PILE_estVide(p))
    {
        p = cel;
    }
    else
    {
        Cellule *parcours = p;
        while (parcours->suivant != NULL)
            parcours = parcours->suivant;
        parcours->suivant = cel;
    }
    return p;
}

PILE dePILE(PILE p, MOT *elt)
{
    if (PILE_estVide(p))
        fprintf(stderr, "La pile est deja vide");
    else
    {
        if (p->suivant == NULL)
        {
            *elt=p->elt;
            p=NULL;
        }
        else
        {
            Cellule *parcour = p;
            Cellule *marqueur;
            while (parcour->suivant != NULL)
                parcour = parcour->suivant;
            *elt = parcour->elt;
            marqueur=parcour;
            parcour=p;
            while(parcour->suivant!=marqueur)
                parcour = parcour->suivant;
            parcour->suivant=NULL;
            free(marqueur);
        }
    }
    
    return p;
}

PILE saisir_PILE()
{
    PILE p = init_pile();
    MOT tmp;
    int nombre_a_ajouter;
    printf("Entrer le nombre de valeur a ajouter ? ");
    do
    {
        scanf("%d", &nombre_a_ajouter);
    } while (nombre_a_ajouter < 1);
    printf("///\tDebut entree utilisateur\t///\n");
    for (int i = 0; i < nombre_a_ajouter; i++)
    {
        saisir_MOT(&tmp);
        p = emPILE(p, tmp);
    }

    return p;
}

int estDanslaPile(PILE p,char *buffer)
{
    if(!PILE_estVide(p))
    {
        int test=0;
        Cellule *parcours=p;
        while(parcours && !test)
        {
            test=compare_MOT(parcours->elt,affecter_MOT(buffer));
            parcours=parcours->suivant;
        }
        return test;
    }
}