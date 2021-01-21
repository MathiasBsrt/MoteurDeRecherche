/***
 * Moteur de recherche
 * Ce fichier regroupe les fonctins permettant le comparaison et la recherche de documents
 */
#include <stdio.h>
//#include "../pile_dynamique.h"
#include "../controle_descripteur.h"
#define SEUIL_DOMINANTE 30
#define SEUIL_RGB 70
#define SEUIL_NB 85

/***
 * Compare 2 descripteurs de même type
 * @param Descripteur d1
 * @param Desripteur d2
 * @param double seuilSimilarité => pourcentage de similarité entre 2 mêmes cases de l'histogramme
 * @return 0 si égaux, 1 si similaires, 2 si trop différent et le pourcentage
 */
int comparaison_image(Descripteur_image d1, Descripteur_image d2, double seuil,int RGB_ou_NB, double* pourcentage);

/***
 * Recherche par critère
 * Cette fonction permet de rechercher des documents en fonction d'u critère donné
 * @param RGB couleurDominante
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParCritere_image(RGB couleurDominante, FILE *fichiersSimilaires, int seuilSimilarite);

/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParDocument_RGB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite);

void rechercheParDocument_NB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite);

void id_to_chemin_image(int id,int NB_RGB,char* chemin);

int chemin_to_id_image(char* chemin, int nb_RGB);
