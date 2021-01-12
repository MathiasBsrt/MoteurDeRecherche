#include "pile_dynamique.h"
#include "descripteur.h"

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

PILE init_PILE()
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
        CELLULE *parcours = p;
        printf("\n\n\t AFFICHAGE DES DescripteurS ET LEURS OCCURENCES\n");
        do
        {
            affiche_DESC_AUDIO(parcours->elem);
            parcours = parcours->suivant;
        } while (parcours != NULL);
        printf("\n");
    }
}

PILE emPILE(PILE p, DESC_AUDIO elt)
{
    CELLULE *cel = malloc(sizeof(CELLULE));
    cel->suivant = NULL;
    cel->elem = elt;
    if (PILE_estVide(p))
    {
        p = cel;
    }
    else
    {
      cel->suivant=p;
        // Cellule *parcours = p;
        // while (parcours->suivant != NULL)
        //     parcours = parcours->suivant;
        // parcours->suivant = cel;
    }
    return cel;
}

PILE dePILE(PILE p, DESC_AUDIO *elt)
{
    if (PILE_estVide(p))
        fprintf(stderr, "La pile est deja vide");
    else
    {
        if (p->suivant == NULL)
        {
            *elt = p->elem;
            p=NULL;
        }
        else
        {
            CELLULE* marqueur=p;
            *elt = p->elem;
            p=p->suivant;
            marqueur=NULL;
            free(marqueur);
        }
    }

    return p;
}

PILE inverserPILE(PILE pile){
  PILE sub=init_PILE();
  DESC_AUDIO elem;
  while(!PILE_estVide(pile)){
    pile=dePILE(pile,&elem);
    sub=emPILE(sub,elem);
  }
  return sub;
}
