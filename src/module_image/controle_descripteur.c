#include "controle_descripteur.h"

/***
 * Cette fonction permet de créer le descripteur d'un fichier
 * donné et le stocker dans le fichier base_descripteur
 */
void creationDescripteur(char *chemin,PILE * p)
{
  //lire fichier pointé par le chemin
  //quantification de chaque pixel de l'image
  //Creer l'histograme
  //Creer variable descripteur et le remplir
  FILE *image;
  Descripteur newDesc; //Le desctipeur à ajouter

  int lignes;
  int colonnes;
  int nbComposantes;
  char *basec, *bname; //bname est le nom du fichier à indexer
  // Intialisation des variables

  basec = strdup(chemin);
  bname = basename(basec);
  image = fopen(chemin, "r");

  //Lecture des propriétés de l'image
  fscanf(image, "%d", &lignes);
  fscanf(image, "%d", &colonnes);
  fscanf(image, "%d", &nbComposantes);
  int **matriceImageQuant = malloc(sizeof(int *) * lignes);

  //intialisation de la matrice de quantification
  for (int i = 0; i < lignes; i++)
  {
    matriceImageQuant[i] = malloc(sizeof(int) * colonnes);
  }
  //Lecture du fichier image
  if (nbComposantes == 1)
  {
    int **matriceNB = (int **)malloc(sizeof(int *) * lignes); // Contient les matrices noir et blanc
    for (int i = 0; i < lignes; i++)
    {
      matriceNB[i] = (int *)malloc(sizeof(int) * colonnes);
    }
    lire_imageNB(lignes, colonnes, matriceNB, image);
    quantificationNB(matriceNB, matriceImageQuant, lignes, colonnes);
    for (int i = 0; i < lignes; i++)
    {
      free(matriceNB[i]);
    }
    free(matriceNB);
  }
  else
  {
    RGB **matriceRGB = (RGB **)malloc(sizeof(RGB) * lignes);
    for (int i = 0; i < lignes; i++)
    {
      matriceRGB[i] = (RGB *)malloc(sizeof(RGB) * colonnes);
    }
    lire_imageRGB(lignes, colonnes, matriceRGB, image);
    quantificationRGB(matriceRGB, matriceImageQuant, lignes, colonnes);

    for (int i = 0; i < lignes; i++)
    {
      free(matriceRGB[i]);
    }
    free(matriceRGB);
  }
  fclose(image);

  // intialisation de l'histogramme
  for (int i = 0; i < tailleHistogramme; i++)
  {
    newDesc.histogramme[i] = 0;
  }
  creationHistogramme(matriceImageQuant, &newDesc, lignes, colonnes); // doit créer l'histo et remplir l'attribut histogramme du descripteur

  //Sauvegarde du nouveau descripteur
   *p = SauvegardeDescripteur(newDesc, *p, bname,nbComposantes);

  for (int i = 0; i < lignes; i++)
  {
    free(matriceImageQuant[i]);
  }
  free(matriceImageQuant);
}

PILE chargerPILE(char* cheminFichier){
  PILE pile=init_pile();
  FILE* fich=fopen(cheminFichier,"r");
  if(fich){
    Descripteur desc;
    while(fscanf(fich,"%d",&desc.id)!=EOF){
      for(int i=0;i<tailleHistogramme;i++){
        fscanf(fich,"%d",&desc.histogramme[i]);
      }
      pile=emPILE(pile,desc);
    }
  }

  return pile;
}
/**
 * Cette fonction permet de sauvegarder un descripteur donné en paramètre dans le fichier base_descripteur_image
 * et de lier ce descripteur avec le fichier dans le fichier liste_base_image
 */
PILE SauvegardeDescripteur(Descripteur nouveau, PILE p, char *nom,int RGB_ou_NB)
{
  if(!PILE_estVide(p))
  nouveau.id=p->elt.id+1;
  else{
    nouveau.id=1;
  }
  p = emPILE(p, nouveau);
  lierDescripteur(nouveau, nom,RGB_ou_NB);

  return p;
}

/***
 * Cette fonction permet de sauvegarder la pile passée en paramètre
 * dans le fichier base_descripteur_image.
 * La pile spécifiée écrase l'ancienne
 */
void sauvegarderPile(PILE p,int RGB_ou_NB)
{
  //On stocke sous la forme de une ligne = un element de la pile : "[id] [e1] [e2 [e3] ..." pour les 64 elements du tableau histogramme (sans les crochets)
  FILE *pileFichier;
  if(RGB_ou_NB==1){
    pileFichier = fopen("base_descripteur_image_NB", "w+");
  }
  else{
    pileFichier = fopen("base_descripteur_image_RGB", "w+");
  }
  Descripteur copier;
  while (!PILE_estVide(p))
  {
    //on ecrit l'id + espace
    //on ecrit l'histogramme, chaque valeur séparée par un espace
    //on revient à la ligne
    p = dePILE(p, &copier);
    // On met tout en ligne, pas beosin des indices du tableau de l'histogramme.
    // On met tout en ligne pour faciliter la lecture par le futur charger fichier/pile. Un \n represente la fin d'un descripteur
    fprintf(pileFichier, "%d ", copier.id);
    for (int i = 0; i < tailleHistogramme; i++)
    {
      fprintf(pileFichier, "%d ", copier.histogramme[i]);
    }
    fprintf(pileFichier,"%s","\n");

  }


  fclose(pileFichier);
}

/***
 * Cette méthode permet de lire une image noir et blanc
 * @return une matrice représentant l'image noir et blanc
 */
int lire_imageNB(int lignes, int colonnes, int **matriceImage, FILE *image)
{
  for (int i = 0; i < lignes; i++)
  {
    for (int j = 0; j < colonnes; j++)
    {
      fscanf(image, "%d", &matriceImage[i][j]);
    }
  }
  return 0;
}
int quantificationNB(int **matriceImageNB, int **matriceImageQuant, int lignes, int colonnes)
{
  int niveau = 64;
  int pixel;
  for (int i = 0; i < lignes; i++)
  {
    for (int j = 0; j < colonnes; j++)
    {
      pixel = matriceImageNB[i][j];
      matriceImageQuant[i][j] = pixel / (256 / niveau);
    }
  }
  return 0;
}

/***
 * Cette méthode permet de lire une RGB
 * @return une matrice représentant l'image RGB
 */
int lire_imageRGB(int lignes, int colonnes, RGB **matriceImage, FILE *image)
{

  for (int i = 0; i < lignes; i++)
  {
    for (int j = 0; j < colonnes; j++)
    {
      fscanf(image, "%d", &matriceImage[i][j].red);
    }
  }
  for (int i = 0; i < lignes; i++)
  {
    for (int j = 0; j < colonnes; j++)
    {
      fscanf(image, "%d", &matriceImage[i][j].green);
    }
  }
  for (int i = 0; i < lignes; i++)
  {
    for (int j = 0; j < colonnes; j++)
    {
      fscanf(image, "%d", &matriceImage[i][j].blue);
    }
  }

  return 0;
}

int power(int x, int puiss)
{
  int resultat = x;
  if (puiss == 0)
  {
    return 1;
  }
  for (int i = 1; i < puiss; i++)
  {
    resultat *= x;
  }
  return resultat;
}

/***
 * Cette méthode permet de quantifier un pixel de type RGB
 * @return entier resultat de la quantification
 */
int quantifie_un_pixelRGB(RGB pixel)
{
  int resultat = 0;
  int etape = 1;
  int composantes[6];
  int puissance = 7;
  while (etape - quantificateur <= 0)
  {
    composantes[(3 * quantificateur) - etape] = pixel.red > power(2, puissance);
    if (pixel.red > power(2, puissance))
    {
      pixel.red /= 2;
    }
    composantes[(2 * quantificateur) - etape] = (pixel.green > (power(2, puissance)));
    if (pixel.green > power(2, puissance))
    {
      pixel.green /= 2;
    }
    composantes[(1 * quantificateur) - etape] = (pixel.blue > (power(2, puissance)));
    if (pixel.blue > power(2, puissance))
    {
      pixel.blue /= 2;
    }
    puissance--;
    etape++;
  }
  for (int i = 0; i < (3 * quantificateur); i++)
  {
    resultat += (composantes[i]) * power(2, i);
  }
  return resultat;
}

/***
 * Cette méthode permet de quantifier une matrice de type RGB
 * @return la matrice quantifiée et un code de retour (succes ou echec)
 */
int quantificationRGB(RGB **matriceImageRGB, int **matriceImageQuant, int lignes, int colonnes)
{
  for (int i = 0; i < lignes; i++)
  {
    for (int j = 0; j < colonnes; j++)
    {
      matriceImageQuant[i][j] = quantifie_un_pixelRGB(matriceImageRGB[i][j]);
    }
  }
  return 0;
}

/***
 * Cette méthode permet de créer un histogramme à partir de de la matrice quantifiée et de l'ajouter au nouveau descripteur
 * @return le nouveau descripteur et un code de retour (succès ou echec)
 */
int creationHistogramme(int *matriceImageQuant[], Descripteur *newDesc, int lignes, int colonnes) // doit créer l'histo et remplir l'attribut histogramme du descripteur
{
  for (int i = 0; i < lignes; i++)
  {
    for (int j = 0; j < colonnes; j++)
    {
      newDesc->histogramme[matriceImageQuant[i][j]] += 1;
    }
  }

  return 0;
}

/***
 * Cette fonction permet de lier un descripteur à son fichier
 * Le fichier liste_base image mémorise le nom des fichiers traités
 * et l'idendifiant unique du descripteur de ce fichier
 */
void lierDescripteur(Descripteur d, char *nom,int RGB_ou_NB)
{
  FILE *pileFichier;
  if(RGB_ou_NB==1){
    pileFichier = fopen("liste_base_image_NB", "a");
  }
  else{
    pileFichier = fopen("liste_base_image_RGB", "a");
  }
  //Condition si le fichier n'existe pas
  if (pileFichier == NULL)
  {
    char commande[1000];
    if(RGB_ou_NB==1){
      strcpy(commande, "touch base_descripteur_image_NB");

    }
    else{
      strcpy(commande, "touch base_descripteur_image_RGB");

    }
    system(commande);
    pileFichier = fopen("liste_base_image", "w+");
  }

  //on ecrit l'id + le nom du fichier + retour à la la ligne
  fprintf(pileFichier, "%d %s \n", d.id, nom);

  fclose(pileFichier);
}

void path_maker(char *chemin, char *nom_dossier, char *nom_fichier)
{
  strcpy(chemin, nom_dossier);
  strcat(chemin, "/");
  strcat(chemin, nom_fichier);
}

void lecture_dossier(FILE *f, char *nom_dossier)
{
  struct dirent *dir;
  DIR *d = opendir(nom_dossier);

  while ((dir = readdir(d)) != NULL)
  {

    if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
      ; //on evite de lire les "." et ".."
    else
    {
      struct stat InfosFile;
      char chemin[100];
      path_maker(chemin, nom_dossier, dir->d_name);
      stat(chemin, &InfosFile);            //on recupere les stat du fichier lu pour savoir si c' est un dossier
      if (S_ISREG(InfosFile.st_mode) != 0) //on vérifie si c'est un fichier
      {
        fprintf(f, "%s ", dir->d_name);
      }
    }
  }
  closedir(d);
  rewind(f); //on remet le pointeur du fichier au début
}

 int image_deja_indexe(char *path_to_xml,char *liste_base_image)
 {
   int code_retour = 0;

     FILE *liste_base_desc = fopen(liste_base_image, "r");
     if (liste_base_desc)
     {
         int id_texte;
         char buffer[255];
         while (fscanf(liste_base_desc, "%d %s",&id_texte,buffer) != EOF)
         {
             if (!strcmp(buffer, path_to_xml))
             {
                 code_retour = id_texte;
                 break;
             }
         }
       }
         return code_retour;
 }

void genererDescripteurDossier(char *cheminDossier,int RGB_ou_NB){
  PILE pile;
  FILE* fich;
  fich=fopen("nom_fichiers.txt","w+");
  char chemin[255];
  char cheminFichier[255];
  lecture_dossier(fich, cheminDossier);
  if(RGB_ou_NB==1){
    pile=chargerPILE("base_descripteur_image_NB");
  }
  else{
    pile=chargerPILE("base_descripteur_image_RGB");
  }
if(!PILE_estVide(pile) && pile->elt.id==1){
  pile=inverserPILE(pile);
}
  while(fscanf(fich,"%s",chemin)!=EOF){
    strcpy(cheminFichier,cheminDossier);
    strcat(cheminFichier,chemin);
    if(RGB_ou_NB==1){
      if(!image_deja_indexe(chemin,"liste_base_image_NB")){
        printf("%s \n",cheminFichier);

        creationDescripteur(cheminFichier,&pile);
      }
    }
    else{
      if(!image_deja_indexe(chemin,"liste_base_image_RGB")){
        printf("%s \n",cheminFichier);
        creationDescripteur(cheminFichier,&pile);
    }
    }

  }
    sauvegarderPile(pile,RGB_ou_NB);
  fclose(fich);
}

  // FILE *f = fopen("nom_fichiers.txt", "w+");
  //
  // if (f == NULL)
  // {
  //   char commande[1000];
  //   strcpy(commande, "touch nom_fichiers.txt");
  //   system(commande);
  //   f = fopen("nom_fichiers.txt", "w+");
  // }
  //
  // lecture_dossier(f, cheminDossier); // Dans f on a tous nos fichiers
  // rewind(f);
  //
  // //On lit maintenant le fichier
  // //On lance une indexation pour chaque fichiers
  // char val[100];
  // char cheminFichier[100];
  // int res = 0;
  // do
  // {
  //   strcpy(cheminFichier, cheminDossier);
  //   res = fscanf(f, "%s", val);
  //   strcat(cheminFichier, val);
  //   printf("cheminFichier= %s \n", cheminFichier);
  //   creationDescripteur(cheminFichier);
  //
  // } while (res != EOF);
  //
  // fclose(f);
  //
  // printf("fin de la génération des descripteurs du dossier %s", cheminDossier);
  // //Ajouter la modif de davy pour la pile
//}


int main(int argc, char *argv[])
{
  genererDescripteurDossier("tests/TEST_RGB/txt/",3); // Génération rgb
  genererDescripteurDossier("tests/TEST_NB/txt/",1); // Génératio nb

   // printf("Indexation RGB 01 et RGB 02");
   // creationDescripteur("tests/TEST_RGB/txt/01.txt"); // Génération rgb
   // creationDescripteur("tests/TEST_RGB/txt/02.txt"); // Génératio nb

  return 0;
}
