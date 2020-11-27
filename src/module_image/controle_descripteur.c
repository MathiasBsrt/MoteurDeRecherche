#include "controle_descripteur.h"

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
    PILE *p; //La pile de descripteurs
    Descripteur *newDesc;  //Le desctipeur à ajouter 

    int lignes;
    int colonnes;
    int nbComposantes;
    int histo[tailleHistogramme]; //l'histogramme du futur descripteur

    p = NULL;
    newDesc = NULL;
    image = fopen(*chemin,"r");    
    //Lecture des propriétés de l'image
    scanf("%d",&lignes);
    scanf("%d", &colonnes);
    scanf("%d", &nbComposantes);

    int matriceImageBrut[lignes*nbComposantes][colonnes*nbComposantes]; // Contient les matrices de chaque composante
    int matriceImageQuant[lignes][colonnes]; //Matrice après quantification de la version brut   

    //Lecture du fichier image

    lire_image(lignes,colonnes, *matriceImageBrut, image);
    fclose(image);

    // Pour une image rgb on a 3 matrices : matrice R, matrice G et matrice B
    //Pour une image niveau de gris : un seule matrice
    //On cree une une matrice commune à ses 3 matrices en faisant une quantification pour chaque pixel
    
    //TODO : quantification(*matriceImageBrut, *matriceImageQuant);

    //TODO : creationHistogramme(matriceImageQuant,newDesc); // doit créer l'histo et remplir l'attribut histogramme du descripteur

    chargerPile(p);
    SauvegardeDescripteur(newDesc, chemin,*p);
    sauvegarderPile(*p);
}

/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
void SauvegardeDescripteur(Descripteur *nouveau,char *cheminVersFichier[], PILE p){
    nouveau->id = p->e.id++;
    p = emPILE(p,*nouveau);    
}
/***
 * Cette fonction permet de charger la pile stockée dans
 * le fichier base_descripteur_image. Dans le cas où ce 
 * fichier n'existe pas, on le créera.
 * 
 * Retourne une pile
 */
void chargerPile(PILE *p){
    Descripteur d;
    FILE *fichierPile;
    *p = init_PILE();
    fichierPile = fopen("base_descripteur_image","r");
    //Condition si le fichier n'existe pas
    if(fichierPile == NULL){
        char commande[1000] ;
        strcpy(commande, "touch base_descripteur_image");
        system(commande);
    }
    else{
        int val;
        fscanf(fichierPile,"%d",&val); //id du premier element
        do{
            d.id = val;
            for (int i = 0; i < tailleHistogramme; i++)
            {
                fscanf(fichierPile,"%d",&val); //case de l'histogramme
                    d.histogramme[i]= val;
            }
            emPILE(*p,d);
            fscanf(fichierPile,"%d",&val); //id

        }while(val != -1); // -1 signifie que c'est le dernier element de la pile
        fclose(fichierPile);

    }
}

/***
 * Cette fonction permet de sauvegarder la pile passée en paramètre
 * dans le fichier base_descripteur_image.
 * La pile spécifiée écrase l'ancienne
 */
void sauvegarderPile(PILE p){
    //On stocke sous la forme de une ligne = un element de la pile : "[id] [e1] [e2 [e3] ..." pour les 64 elements du tableau histogramme (sans les crochets)
    FILE *pileFichier;
    pileFichier = fopen("base_descripteur_image","w+");    
    CEL *cellCourant;
    cellCourant = p;

    while(cellCourant!= NULL)
    {
        //on ecrit l'id + espace
        //on ecrit l'histogramme, chaque valeur séparée par un espace
        //on revient à la ligne

        fprintf(pileFichier,"%d ",cellCourant->e.id);
        for (int i = 0; i < tailleHistogramme; i++)
        {
            fprintf(pileFichier,"%d ",cellCourant->e.histogramme[i]);
        }
        cellCourant = cellCourant->suivant; // Parcours de la liste dynamique
    }
    
    fprintf(pileFichier,"%d ",-1);


    fclose(pileFichier);

}

int lire_image(int lignes, int colonnes, int *matriceImage, FILE *image){
	int val = 0;
	 for (int i = 0; i < lignes; i++)
        {
            for (int j = 0; j < colonnes; j++)
            {
                fscanf(image,"%d",&val);
                /*
                * Passer un tableau 2D en paramètre : https://codes-sources.commentcamarche.net/faq/918-passer-un-tableau-a-2-dimensions-a-une-fonction
                */
				matriceImage[(int unsigned)((i*colonnes)+i)] = val; // A tester, je ne sais pas si ça marche vraiment
            }
        
            
        }
	return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}



//TODO :liste_base_image pour lier le nom du fichier du descripteur à ce dernier

