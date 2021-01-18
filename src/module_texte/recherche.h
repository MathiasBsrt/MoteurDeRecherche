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
 * Cette fonction permet de rechercher des documents en fonction d'un critère donné
 * @param String mot à chercher
 * @param Strin[] resultats de la recherche, sous forme de chemin des documents
 * @param double seuilSimilarité 
 */
void rechercheParCritere(char *mot, char *fichiersSimilaires[], int *nbF, double seuilSimilarite);
/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParDocument(char *cheminVersDocument, char *fichiersSimilaires[], int *nbF, double seuilSimilarite);
Table_Index rechercheMot(Table_Index a, char *mot);
Descripteur_texte* getDescripteur_Texte(int id, PILE_descripteur_texte *p);
void getChemin(int id, char chemin[]);
