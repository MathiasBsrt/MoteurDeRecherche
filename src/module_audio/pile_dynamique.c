#include "pile_dynamique.h"
#include "descripteur.h"

PILE init_PILE(){
  return NULL;
}
void affiche_PILE(PILE pile){
   CELLULE *cell=pile;
  while(cell!=NULL){
    affiche_DESC_AUDIO(cell->elem);
    cell=cell->suivant;
 }
}
int PILE_estVide(PILE pile){
  return pile==NULL;
}
PILE emPILE(PILE pile,DESC_AUDIO elem){
  CELLULE *cell=malloc(sizeof(CELLULE));
  cell->elem=elem;
  cell->suivant=NULL;
  if(PILE_estVide(pile)){
      pile=cell;
    }
    else{
    CELLULE* curseur=pile;
    while(curseur->suivant!=NULL){
      curseur=curseur->suivant;
    }
    curseur->suivant=cell;
  }
  return pile;
}
PILE dePILE(PILE p, DESC_AUDIO *elt)
{
    if (PILE_estVide(p))
        fprintf(stderr, "La pile est deja vide");
    else
    {
        if (p->suivant == NULL)
        {
            *elt=p->elem;
            p=NULL;
        }
        else
        {
            CELLULE *parcour = p;
            CELLULE *marqueur;
            while (parcour->suivant != NULL)
                parcour = parcour->suivant;
            *elt = parcour->elem;
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
// PILE saisir_PILE(){
//   int nb_valeur;
//   ELEMENT valeur;
//   PILE pile;
//   pile=init_PILE();
//   printf("Entrez jusqu'à %d valeurs une à une\n",MAX);
//   printf("Combien voulez vous entrer de valeurs dans la pile ?\n");
//   scanf("%d",&nb_valeur);
//   while(nb_valeur>MAX || nb_valeur<1){
//     printf("Valeur impossible");
//     printf("Combien voulez vous entrer de valeurs dans la pile ?\n");
//     scanf("%d",&nb_valeur);
//   }
//   for(int i=0;i<nb_valeur;i++){
//     valeur=saisir_ELEMENT();
//     pile=emPILE(pile,valeur);
//   }
//   return pile;
// }
