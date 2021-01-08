#include "moteur.h"

int comparaison(Descripteur d1, Descripteur d2, double seuil){
    int totalValeurs = 40000; //défini par test pour RGB, vari en fonction de la taille de l'image ?
    //Méthode de comparaison : intersection des 2 histogrammes (cf cahier des charges) => comment faire l'intersection des 2 tableaux ? revient à une différence ?
    // voir ici : https://openclassrooms.com/forum/sujet/intersection-de-2-tableaux
    
    //Similaire si seuil% des cases sont similaire
    //Une case est similaire si l la valeur 1 et compris dans l'intervale val2-seuil; val2 +seuil

    if(d1.id == d2.id){
        return 0;
    }
    
   //Construire le tableau d'intersection
  //Une case est similaire si l la valeur 1 et compris dans l'intervale val2-seuil; val2 +seuil
  // On ajoute cette case dans le teableau d'intersection
  int nbCaseIntersection = 0;
  int val1;
  int val2;
  for (int i = 0; i < tailleHistogramme; i++)
  {
      val1 = d1.histogramme[i];
      val2 = d2.histogramme[i];
      if(val2-val2*(seuil/100) <= val1 && val1<= val2+val2*(seuil/100) ){
          nbCaseIntersection++;
      }
  }
  
  //On obtient un tableau dont al longueur et le nb de cases similaire. On peut en tirer un pourcentage de similarité (sur les 64 cases d'un histogramme)
  //On compare la similarité au seuil
  printf("\n similaire sur %d cases\n", nbCaseIntersection);
  float pourcentage = (nbCaseIntersection/tailleHistogramme)*100;
  printf("Similaire à %f pourcents\n",pourcentage);
  if(pourcentage==100){
      return 0;
  }
  else if(pourcentage>=seuil){
      return 1;
  }

   return 2;

}

/***
 * Recherche par critère
 * Cette fonction permet de rechercher des documents en fonction d'u critère donné
 * @param String couleurDominante
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParCritere(char *couleurDominante, File *fichiersSimilaires, int seuilSimilarite){

}

/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParDocument(char *cheminVersDocument, File *fichiersSimilaires, int seuilSimilarite){

}




int main(int argc, char const *argv[])
{
    PILE p;
    charger_PILE_Desc(&p,"base_descripteur_image");
    Descripteur *d;
    dePILE(p,d);
    Descripteur *d2;
    dePILE(p,d2);

    printf("\n on compare...\n");
    int res = comparaison(d,d2,1000);

    //On envoie 2 descriteurs pour les comaprer et tester

    return 0;
}
