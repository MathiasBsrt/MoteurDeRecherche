#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
/***
  * Cette fonction permet de quantifier un pixel d'image RGB passé en paramètre en fonction du quantificateur
  */
int quantifie_un_pixelRGB(RGB pixel);
int quantificationRGB(RGB **matriceImageRGB,int *matriceImageQuant[],int lignes,int colonnes);

int creationHistogramme(int *matriceImageQuant[],Descripteur *newDesc,int lignes,int colonnes); // doit créer l'histo et remplir l'attribut histogramme du descripteur

/***
 * Cette fonction permet de créer le descripteur d'un fichier
 * donné et le stocker dans le fichier base_descripteur
 */

void creationDescripteur(char *chemin);

/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
void SauvegardeDescripteur(Descripteur nouveau,char *cheminVersFichier[], PILE p);

/***
 * Cette fonction permet de charger la pile stockée dans
 * le fichier base_descripteur_image. Dans le cas où ce
 * fichier n'existe pas, on le créera.
 *
 * Retourne une pile
 */
void chargerPile(PILE *p);

/***
 * Cette fonction permet de sauvegarder la pile passée en paramètre
 * dans le fichier base_descripteur_image.
 * La pile spécifiée écrase l'ancienne
 */
void sauvegarderPile(PILE p);

int lire_imageNB(int lignes, int colonnes, int* matriceImage[], FILE *image);
int lire_imageRGB(int lignes, int colonnes, RGB** matriceImage, FILE *image);


//TODO :liste_base_image pour lier le nom du fichier du descripteur à ce dernier
