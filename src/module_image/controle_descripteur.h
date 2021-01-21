#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pile_dynamique.h"
//STRUCTURES
/**
  *Structure pour une matrice rgb
  *.red .green .blue accès à la couleur voulu
*/
typedef struct RGB_t{
  int red;
  int green;
  int blue;
}RGB;


//FONCTIONS

void lancer_indexation_image();

/***
  * Cette fonction permet de quantifier un pixel d'image RGB passé en paramètre en fonction du quantificateur
  */
int quantifie_un_pixelRGB(RGB pixel);
int quantificationRGB(RGB **matriceImageRGB,int *matriceImageQuant[],int lignes,int colonnes);

int creationHistogramme(int *matriceImageQuant[],Descripteur_image *newDesc,int lignes,int colonnes); // doit créer l'histo et remplir l'attribut histogramme du Descripteur_image

/***
 * Cette fonction permet de créer le descripteur d'un fichier
 * donné et le stocker dans le fichier base_descripteur
 */

 void creationDescripteur_image(char *chemin,PILE_image * p);

/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
 PILE_image SauvegardeDescripteur_image(Descripteur_image nouveau, PILE_image p, char *nom,int RGB_ou_NB);

/***
 * Cette fonction permet de charger la pile stockée dans
 * le fichier base_descripteur_image. Dans le cas où ce
 * fichier n'existe pas, on le créera.
 *
 * Retourne une pile
 */
//PILE chargerPile();

/***
 * Cette fonction permet de sauvegarder la pile passée en paramètre
 * dans le fichier base_descripteur_image.
 * La pile spécifiée écrase l'ancienne
 */
void sauvegarderPile_image(PILE_image p,int RGB_ou_NB);

int lire_imageNB(int lignes, int colonnes, int* matriceImage[], FILE *image);
int lire_imageRGB(int lignes, int colonnes, RGB** matriceImage, FILE *image);
int quantificationNB(int **matriceImageNB,int** matriceImageQuant,int lignes,int colonnes);

void lierDescripteur_image(Descripteur_image d, char *nom, int RGB_ou_NB);

void genererDescripteur_imageDossier(char *cheminDossier,int RGB_ou_NB);
void genererDescripteur_image(char *cheminDossier,int RGB_ou_NB); 