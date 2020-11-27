#include <stdio.h> 
#include <stdlib.h> 
#include "pile_dynamique.h"
#include "descripteur.h"



/***
 * Cette fonction permet de créer le descripteur d'un fichier
 * donné et le stocker dans le fichier base_descripteur
 */

void creationDescripteur(int taille, char *chemin[]){
    //lire fichier pointé par le chemin
    //quantification de chaque pixel de l'image
    //Creer l'histograme
    //Creer variable descripteur et le remplir

    FILE *image;
    PILE *p;
    int lignes;
    int colonnes;
    int nbComposantes;
    int histo[tailleHistogramme];

    image = fopen(*chemin,"r");
    p = chargerPile();
    
    //Lecture des propriétés de l'image
    scanf("%d",&lignes);
    scanf("%d", &colonnes);
    scanf("%d", &nbComposantes);

    int matriceImageBrut[lignes*nbComposantes][colonnes*nbComposantes]; // Contient les matrices de chaque composante
    int matriceImageQuant[lignes][colonnes]; //Matrice après quantification de la version brut   

    //Lecture du fichier image

    lire_image(lignes,colonnes, matriceImageBrut, image);

    // Pour une image rgb on a 3 matrices : matrice R, matrice G et matrice B
    //Pour une image niveau de gris : un seule matrice
    //On cree une une matrice commune à ses 3 matrices en faisant une quantification pour chaque pixel
    quantification(*matriceImageBrut, *matriceImageQuant);
    
    //Creation du descripteur
    Descripteur *newDesc;
    newDesc->id = 0;

    creationHistogramme(matriceImageQuant,newDesc); // doit créer l'histo et remplir l'attribut histogramme du descripteur
    
    SauvegardeDescripteur(newDesc, *chemin,&p);
}

/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
SauvegardeDescripteur(Descripteur *nouveau,char *cheminVersFichier[], PILE *p){
    //On 
    p = emPILE(p, *nouveau);
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
    PILE p;
    return p;
}

/***
 * Cette fonction permet de sauvegarder la pile passée en paramètre
 * dans le fichier base_descripteur_image.
 * La pile spécifiée écrase l'ancienne
 */
void sauvegarderPile(PILE p){

}

int* lire_image(int lignes, int colonnes, int *matriceImage, FILE *image){
	int val = 0;
	 for (int i = 0; i < lignes; i++)
        {
            for (int j = 0; j < colonnes; j++)
            {
                scanf("%d",&val);
                /*
                * Passer un tableau 2D en paramètre : https://codes-sources.commentcamarche.net/faq/918-passer-un-tableau-a-2-dimensions-a-une-fonction
                */
				matriceImage[(int unsigned)((i*colonnes)+i)] = val;
            }
        
            
        }
	return 0;
}


