#include <stdio.h> 
#include <stdlib.h> 
#include "pile_dynamique.h"

/***
 * Cette fonction permet de créer le descripteur d'un fichier
 * donné et le stocker dans le fichier base_descripteur
 */

void creationDescripteur(int taille, char *chemin[]){
    //lire fichier pointé par le chemin

    //quantification de chaque pixel de l'image

    //Creer l'histograme

    //Creer variable descripteur et le remplir

    FILE* image;
    int lignes;
    int colonnes;
    int matriceImage[][];
    
    image = fopen(*chemin,"r");
    scanf("%d",&lignes);
    scanf("%d", &colonnes);
    lire_image(lignes,colonnes,matriceImage);

    SauvegardeDescripteur(descripteur, cheminVersFichier);
}

/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
SauvegardeDescripteur(Descripteur decripteur,char *cheminVersFichier[]){
    //On empile
    p = emPILE(p);
    sauvegarderPile(p);
    
}
/***
 * Cette fonction permet de charger la pile stockée dans
 * le fichier base_descripteur_image. Dans le cas où ce 
 * fichier n'existe pas, on le créera.
 * 
 * Retourne une pile
 */
PILE chargerPile(){
    
}

/***
 * Cette fonction permet de sauvegarder la pile passée en paramètre
 * dans le fichier base_descripteur_image.
 * La pile spécifiée écrase l'ancienne
 */
void sauvegarderPile(PILE p){

}

int lire_image(int lignes, int colonnes, int *matriceImage[][]){
	int val = 0;
	 for (int i = 0; i < lignes; i++)
        {
            for (int j = 0; j < colonnes; j++)
            {
                scanf("%d",&val);
				*matriceImage[i][j] = val;
                
            }
        
            
        }
	return 0;
}


