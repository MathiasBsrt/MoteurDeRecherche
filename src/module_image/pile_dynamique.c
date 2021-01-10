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
      cel->suivant=p;
        // Cellule *parcours = p;
        // while (parcours->suivant != NULL)
        //     parcours = parcours->suivant;
        // parcours->suivant = cel;
    }
    return cel;
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
            p=NULL;
        }
        else
        {
            Cellule* marqueur=p;
            *elt = p->elt;
            p=p->suivant;
            marqueur=NULL;
            free(marqueur);
        }
    }

    return p;
}

PILE inverserPILE(PILE pile){
  PILE sub=init_pile();
  Descripteur elem;
  while(!PILE_estVide(pile)){
    pile=dePILE(pile,&elem);
    sub=emPILE(sub,elem);
  }
  return  sub;
}

PILE chargerPILE(char* cheminFichier){
  PILE pile=init_pile();
  FILE* fich=fopen(cheminFichier,"r");
  if(fich){
    Descripteur desc;
    while(fscanf(fich,"%d",&desc.id)!=EOF){
      for(int i=0;i<tailleHistogramme;i++){
        fscanf(fich,"%d",&desc.histogramme[i]);
      }
      pile=emPILE(pile,desc);
    }
  }

  return pile;
}
