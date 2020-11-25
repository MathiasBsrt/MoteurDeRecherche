#include <stdio.h>
#include "pile_dynamique.h"

PILE init_PILE(){
   PILE p;
    p = NULL;
    return p;
}

void affichePILE(PILE p){
    printf("affichage de la pile : ");
    CEL *cellCourant;
    cellCourant = p;

    while(cellCourant!= NULL)
    {
        affiche_ELEMENT(cellCourant->e);
        cellCourant = cellCourant->suivant;
        printf(" -- ");
        

    }
    printf("\n");


    
}


/***
 * Fonction permettant de déterminer si la pile 
 * donnée est vide. 
 * Retourne 1 si la pile est pas vide, sinon 0;
 * 
 */
int PILE_estVide(PILE p){
    if(p == NULL){
        return 1;
    }
    return 0;
}

PILE emPILE(PILE p, ELEMENT nouveau){
    //affichePILE(p);
    if(PILE_estVide(p)){
        CEL *c = malloc(sizeof(CEL));
        c->e = nouveau;
        c->suivant = NULL;
        p = c;
        return p;
    }

    CEL * cellCourant;
    cellCourant = p;

    while(cellCourant->suivant != NULL)
    {
        cellCourant = cellCourant->suivant;
    }

    //Ici elementCourant sera l'élément le plus haut de la pile
    //Creation de la nouvelle celulle qui va s'empiler
    CEL * nouvelleCel = malloc(sizeof(CEL));
    nouvelleCel->e = nouveau;
    nouvelleCel->suivant = NULL;

    cellCourant->suivant = nouvelleCel;


    cellCourant->suivant = nouvelleCel;
    
    return p;
}

PILE dePILE(PILE p, ELEMENT * valeur){
    if(PILE_estVide(p)){
        return p;
    }

    CEL * cellCourant;
    CEL * cellPrecedent;
    cellCourant = p;

    //TRaitement 1 élément dans la pile 
    if(p->suivant == NULL){
        *valeur = p->e; // retour valeur depile
        p = NULL;
        return NULL;
    }

    while(cellCourant->suivant!= NULL)
    {
        cellPrecedent = cellCourant;
        cellCourant = cellCourant->suivant;
    }

    //Ici cellPrecedent sera l'élément juste avant le dernier
    //Creation de la nouvelle celulle qui va s'empiler

    *valeur = cellCourant->e; // retour valeur depile
    CEL * old;
    old = cellPrecedent->suivant;
    free(old);
    cellPrecedent->suivant = NULL;

    return p;


}

PILE saisir_PILE(){
   int nbValeurs = 0;
    PILE p;
    ELEMENT valeurAAjouter;
    
    p = init_PILE();
    printf("Combien de valeurs voulez vous rentrer \n");
    scanf("%d",&nbValeurs);

    printf("NB valeurs :%d \n", nbValeurs);

    for (int i = 0; i < nbValeurs; i++)
    {
        valeurAAjouter = saisir_ELEMENT();
        p = emPILE(p,valeurAAjouter);
    }
    return p;
    
}
