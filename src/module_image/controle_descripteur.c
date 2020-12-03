#include "controle_descripteur.h"

/***
 * Cette fonction permet de créer le descripteur d'un fichier
 * donné et le stocker dans le fichier base_descripteur
 */

void creationDescripteur(char *chemin){
//     //lire fichier pointé par le chemin
//     //quantification de chaque pixel de l'image
//     //Creer l'histograme
//     //Creer variable descripteur et le remplir
//
     FILE *image;
     PILE *p; //La pile de descripteurs
     Descripteur newDesc;  //Le desctipeur à ajouter
//
     int lignes;
     int colonnes;
     int nbComposantes;
//
     p = NULL;
     image = fopen(chemin,"r");
//     //Lecture des propriétés de l'image
     fscanf(image,"%d",&lignes);
     fscanf(image,"%d", &colonnes);
     fscanf(image,"%d", &nbComposantes);
     int ** matriceImageQuant=malloc(sizeof(int*)*lignes);
     for(int i=0;i<lignes;i++){
       matriceImageQuant[i]=malloc(sizeof(int)*colonnes);
     }
//     //Lecture du fichier image
     if(nbComposantes==1){
       int matriceImageNB[lignes][colonnes]; // Contient les matrices noir et blanc
       lire_imageNB(lignes,colonnes,matriceImageNB, image);
     }
     else{
       RGB **matriceRGB=(RGB**)malloc(sizeof(RGB)*lignes);
       for(int i=0;i<lignes;i++){
         matriceRGB[i]=(RGB*)malloc(sizeof(RGB)*colonnes);
       }
      lire_imageRGB(lignes,colonnes,matriceRGB,image);
      quantificationRGB(matriceRGB, matriceImageQuant,lignes,colonnes);

      for(int i=0;i<lignes;i++){
        free(matriceRGB[i]);
      }
      free(matriceRGB);
    }
     fclose(image);

//     // Pour une image rgb on a 3 matrices : matrice R, matrice G et matrice B
//     //Pour une image niveau de gris : un seule matrice
//     //On cree une une matrice commune à ses 3 matrices en faisant une quantification pour chaque pixel
    for(int i=0;i<tailleHistogramme;i++){
      newDesc.histogramme[i]=0;
    }
   creationHistogramme(matriceImageQuant,&newDesc,lignes,colonnes); // doit créer l'histo et remplir l'attribut histogramme du descripteur


     chargerPile(p);
//     SauvegardeDescripteur(newDesc, chemin,*p);
//     sauvegarderPile(*p);
 //   for(int i=0;i<lignes;i++){
 //     free(matriceImageQuant[i]);
 // }
  // free(matriceImageQuant);

   }

/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
void SauvegardeDescripteur(Descripteur nouveau,char *cheminVersFichier[], PILE p){
    nouveau.id = p->e.id++;
    p = emPILE(p,nouveau);
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

int lire_imageNB(int lignes, int colonnes, int* matriceImage[], FILE *image){
 for (int i = 0; i < lignes; i++)
  {
      for (int j = 0; j < colonnes; j++)
    {
      fscanf(image,"%d",&matriceImage[i][j]);
    }
  }
  return 0;
}

int lire_imageRGB(int lignes, int colonnes, RGB** matriceImage, FILE *image){

  for (int i = 0; i < lignes; i++)
   {
       for (int j = 0; j < colonnes; j++)
     {
       fscanf(image,"%d",&matriceImage[i][j].red);
     }
   }
   for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
      {
        fscanf(image,"%d",&matriceImage[i][j].green);
      }
    }
    for (int i = 0; i < lignes; i++)
     {
         for (int j = 0; j < colonnes; j++)
       {
         fscanf(image,"%d",&matriceImage[i][j].blue);
       }
     }

	return 0;
}


int power(int x, int puiss){
  int resultat=x;
  if(puiss==0){
    return 1;
  }
  for(int i=1;i<puiss;i++)
  {
    resultat*=x;
  }
  return resultat;
}

int quantifie_un_pixelRGB(RGB pixel){
  int resultat=0;
  int etape=1;
  int composantes[6];
  int puissance=7;
  while(etape-quantificateur<=0){
    composantes[(3*quantificateur)-etape]=(pixel.red>(power(2,puissance)));
    pixel.red/=2;
    composantes[(2*quantificateur)-etape]=(pixel.green>(power(2,puissance)));
    pixel.green/=2;
    composantes[(1*quantificateur)-etape]=(pixel.blue>(power(2,puissance)));
    pixel.blue/=2;
    puissance--;
    etape++;
  }
  for(int i=0;i<(3*quantificateur);i++){
    resultat+=(composantes[i])*power(2,i);
  }  return resultat;
}

int quantificationRGB(RGB **matriceImageRGB,int** matriceImageQuant,int lignes,int colonnes){
  for(int i=0;i<200;i++)
  {
    for(int j=0;j<200;j++)
    {
      matriceImageQuant[i][j]=quantifie_un_pixelRGB(matriceImageRGB[i][j]);
    }
  }
  return 0;
}

int creationHistogramme(int *matriceImageQuant[],Descripteur *newDesc,int lignes,int colonnes) // doit créer l'histo et remplir l'attribut histogramme du descripteur
{
  for(int i=0;i<lignes;i++)
  {
    for(int j=0;j<colonnes;j++)
    {
      newDesc->histogramme[matriceImageQuant[i][j]]+=1;
    }
  }
  return 0;
}

int main(int argc, char  *argv[])
{
    /* code */
    creationDescripteur(argv[1]);

    return 0;
}
//TODO :liste_base_image pour lier le nom du fichier du descripteur à ce dernier
