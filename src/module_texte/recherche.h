/***
 * Moteur de recherche
 * Ce fichier regroupe les fonctins permettant le comparaison et la recherche de documents
 */
#include <stdio.h>
#include "pile/pile_dynamique.h"

/***
 * Compare 2 descripteurs de même type
 * @param Table_Index t1
 * @param Table_Index t2
 * @param double seuilSimilarité => pourcentage de similarité entre 2 mêmes cases de l'histogramme
 * @return 0 si égaux, 1 si similaires, 2 si trop différent
 */
int comparaison(Descripteur_texte t1, Descripteur_texte t2, double seuil);

/***
 * Recherche par critère
 * Cette fonction permet de rechercher des documents en fonction d'u critère donné
 * @param String mot à chercher
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParCritere(char *mot, FILE *fichiersSimilaires, double seuilSimilarite);

/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParDocument(char *cheminVersDocument, FILE *fichiersSimilaires, double seuilSimilarite);
