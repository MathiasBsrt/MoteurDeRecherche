#include "controle_descripteur.h"

/***
 * Cette fonction permet de créer le descripteur d'un fichier
 * donné et le stocker dans le fichier base_descripteur
 */

void creationDescripteur(char *chemin){
    //lire fichier pointé par le chemin
    //quantification de chaque pixel de l'image
    //Creer l'histograme
    //Creer variable descripteur et le remplir
     FILE *image;
     PILE p; //La pile de descripteurs
     Descripteur newDesc;  //Le desctipeur à ajouter

     int lignes;
     int colonnes;
     int nbComposantes;
     char *basec, *bname; //bname est le nom du fichier à indexer
    // Intialisation des variables

    basec = strdup(chemin); 
    bname = basename(basec);
     p = NULL;
     image = fopen(chemin,"r");

     //Lecture des propriétés de l'image
     fscanf(image,"%d",&lignes);
     fscanf(image,"%d", &colonnes);
     fscanf(image,"%d", &nbComposantes);
     int ** matriceImageQuant=malloc(sizeof(int*)*lignes);

     //intialisation de la matrice de quantification
     for(int i=0;i<lignes;i++){
       matriceImageQuant[i]=malloc(sizeof(int)*colonnes);
     }
     //Lecture du fichier image
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

    // intialisation de l'histogramme
    for(int i=0;i<tailleHistogramme;i++){
      newDesc.histogramme[i]=0;
    }
   creationHistogramme(matriceImageQuant,&newDesc,lignes,colonnes); // doit créer l'histo et remplir l'attribut histogramme du descripteur

    //Sauvegarde du nouveau descripteur
    p=init_PILE();
    //chargerPile(&p); // On chargera la pile
     p=SauvegardeDescripteur(newDesc,p,bname);
    for(int i=0;i<lignes;i++){
      free(matriceImageQuant[i]);
  }
   free(matriceImageQuant);

   }

/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
PILE SauvegardeDescripteur(Descripteur nouveau, PILE p, char *nom){
    nouveau.id = 1;//TODOOn chargera la pile au lancement du programme pour al recherche, on aura donc accès aux id. On utilisera dernier id
    p = emPILE(p,nouveau);
    sauvegarderPile(p);
    lierDescripteur(nouveau,nom);

  return p;
}
/***
 * Cette fonction permet de charger la pile stockée dans
 * le fichier base_descripteur_image. Dans le cas où ce
 * fichier n'existe pas, on le créera.
 *
 * Retourne une pile
 */
// void chargerPile(PILE *p){
//     Descripteur d;
//     FILE *fichierPile;
//     p = init_PILE();
//     fichierPile = fopen("base_descripteur_image","r");
//     //Condition si le fichier n'existe pas
//     if(fichierPile == NULL){
//         char commande[1000] ;
//         strcpy(commande, "touch base_descripteur_image");
//         system(commande);
//     }
//     else if(!feof(fichierPile)) {
//         int val;
//         fscanf(fichierPile,"%d",&val); //id du premier element
//         do{
//             d.id = val;
//             for (int i = 0; i < tailleHistogramme; i++)
//             {
//                 fscanf(fichierPile,"%d",&val); //case de l'histogramme
//                     d.histogramme[i]= val;
//             }
//             emPILE(&p,d);
//             fscanf(fichierPile,"%d",&val); //id
//
//         }while(val != EOF); // Utiliser EOF pour signifier que c'est le dernier element de la pile
//         fclose(fichierPile);
//     }
// }

/***
 * Cette fonction permet de sauvegarder la pile passée en paramètre
 * dans le fichier base_descripteur_image.
 * La pile spécifiée écrase l'ancienne
 */
void sauvegarderPile(PILE p){
    //On stocke sous la forme de une ligne = un element de la pile : "[id] [e1] [e2 [e3] ..." pour les 64 elements du tableau histogramme (sans les crochets)
    FILE *pileFichier;
    pileFichier = fopen("base_descripteur_image","w+");
    Descripteur copier;
    while(!PILE_estVide(p))
    {
        //on ecrit l'id + espace
        //on ecrit l'histogramme, chaque valeur séparée par un espace
        //on revient à la ligne
         p=dePILE(p,&copier);
         // On met tout en ligne, pas beosin des indices du tableau de l'histogramme. 
        // On met tout en ligne pour faciliter la lecture par le futur charger fichier/pile. Un \n represente la fin d'un descripteur
         fprintf(pileFichier,"%d ",copier.id);
         for (int i = 0; i < tailleHistogramme; i++)
         {
             fprintf(pileFichier,"%d ",copier.histogramme[i]);
         }
    }

    fprintf(pileFichier,"%s ","\n");


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
    composantes[(3*quantificateur)-etape]=pixel.red>power(2,puissance);
    if(pixel.red>power(2,puissance)) {pixel.red/=2;}
    composantes[(2*quantificateur)-etape]=(pixel.green>(power(2,puissance)));
    if(pixel.green>power(2,puissance)) {pixel.green/=2;}
    composantes[(1*quantificateur)-etape]=(pixel.blue>(power(2,puissance)));
    if(pixel.blue>power(2,puissance)) {pixel.blue/=2;}
    puissance--;
    etape++;
  }
  for(int i=0;i<(3*quantificateur);i++){
    resultat+=(composantes[i])*power(2,i);
  }  return resultat;
}

int quantificationRGB(RGB **matriceImageRGB,int** matriceImageQuant,int lignes,int colonnes){
  for(int i=0;i<lignes;i++)
  {
    for(int j=0;j<colonnes;j++)
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

/***
 * Cette fonction permet de lier un descripteur à son fichier
 * Le fichier liste_base image mémorise le nom des fichiers traités
 * et l'idendifiant unique du descripteur de ce fichier
 */
void lierDescripteur(Descripteur d, char *nom){
    FILE *pileFichier;
    pileFichier = fopen("liste_base_image","w+");
  //Condition si le fichier n'existe pas
     if(pileFichier == NULL){
         char commande[1000] ;
         strcpy(commande, "touch base_descripteur_image");
         system(commande);
         pileFichier = fopen("liste_base_image","w+");
     }

    //on ecrit l'id + le nom du fichier + retour à la la ligne
    fprintf(pileFichier,"%d %s \n",d.id, nom);

    fclose(pileFichier);
}

int main(int argc, char  *argv[])
{
    creationDescripteur(argv[1]);

    return 0;
}

