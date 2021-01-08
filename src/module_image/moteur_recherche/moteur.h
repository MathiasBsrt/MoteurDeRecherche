/***
 * Moteur de recherche
 * Ce fichier regroupe les fonctins permettant le comparaison et la recherche de documents
 */
#include "../descripteur.h"
#include <stdio.h>
#include "../pile_dynamique.h"
/***
 * Compare 2 descripteurs de même type
 * @param Descripteur d1
 * @param Desripteur d2
 * @param double seuilSimilarité => pourcentage de similarité entre 2 mêmes cases de l'histogramme
 * @return 0 si égaux, 1 si similaires, 2 si trop différent
 */
int comparaison(Descripteur d1, Descripteur d2, double seuil);

/***
 * Recherche par critère
 * Cette fonction permet de rechercher des documents en fonction d'u critère donné
 * @param String couleurDominante
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParCritere(char *couleurDominante, File *fichiersSimilaires, int seuilSimilarite);

/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParDocument(char *cheminVersDocument, File *fichiersSimilaires, int seuilSimilarite);


