#include "pile_dynamique.h"

/**
 * @file pile_dynamique.c
 * @author Baptiste POMARELLE
 * @brief Les fonctions relatives a la pile de Descripteurs (et de leurs occurences) et a la pile de descripteurs
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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
        Cellule *parcours = p;
        printf("\n\n\t AFFICHAGE DES DescripteurS ET LEURS OCCURENCES\n");
        do
        {
            affiche_Descripteur(parcours->elt);
            parcours = parcours->suivant;
        } while (parcours != NULL);
        printf("\n");
    }
}

PILE emPILE(PILE p, Descripteur elt)
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

PILE dePILE(PILE p, Descripteur *elt)
{
    if (PILE_estVide(p))
        fprintf(stderr, "La pile est deja vide");
    else
    {
        if (p->suivant == NULL)
        {
            *elt = p->elt;
            p = NULL;
        }
        else
        {
            Cellule *parcour = p;
            Cellule *marqueur;
            while (parcour->suivant != NULL)
                parcour = parcour->suivant;
            *elt = parcour->elt;
            marqueur = parcour;
            parcour = p;
            while (parcour->suivant != marqueur)
                parcour = parcour->suivant;
            parcour->suivant = NULL;
            free(marqueur);
        }
    }

    return p;
}


int charger_PILE_Desc(PILE *p, char *save_descripteurs_textes)
{   
    int id = 0;
    FILE *f = fopen("base_descripteur_image", "r");
    if (f)
    {
        Descripteur tmp;
        int val;
        while (fscanf(f,"%d",&val) != EOF)
        {
            tmp.id = val;
            for (int i = 0; i < tailleHistogramme; i++)
            {
                fscanf(f,"%d",&val);
                tmp.histogramme[i] = val;
            }
            
            emPILE(*p, tmp);
            id = tmp.id;

        }
        fclose(f);
    }

    return id;
}

