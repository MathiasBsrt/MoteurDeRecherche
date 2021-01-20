/***
 * Moteur de recherche
 * Ce fichier regroupe les fonctins permettant le comparaison_image et la recherche de documents
 */
#include <stdio.h>
//#include "../pile_dynamique.h"
#include "../controle_descripteur.h"
/***
 * Compare 2 descripteurs de même type
 * @param Descripteur d1
 * @param Desripteur d2
 * @param double seuilSimilarité => pourcentage de similarité entre 2 mêmes cases de l'histogramme
 * @return 0 si égaux, 1 si similaires, 2 si trop différent
 */
int comparaison_image(Descripteur d1, Descripteur d2, double seuil);

/***
 * Recherche par critère
 * Cette fonction permet de rechercher des documents en fonction d'u critère donné
 * @param RGB couleurDominante
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParCritere_img(RGB couleurDominante, FILE *fichiersSimilaires, int seuilSimilarite);

/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParDocument_RGB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite);

void rechercheParDocument_NB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite);

void id_to_chemin(int id,int NB_RGB,char* chemin);

int chemin_to_id(char* chemin, int nb_RGB);
