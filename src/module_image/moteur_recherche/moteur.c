#include "moteur.h"


/**
 * @brief compare deux image à travers un seuil de ressemblance défini par avance
 * 
 * @param d1 
 * @param d2 
 * @param seuil 
 * @param RGB_ou_NB 
 * @return int 
 */
int comparaison_image(Descripteur_image d1, Descripteur_image d2, double seuil,int RGB_ou_NB)
{
    //Méthode de comparaison : intersection des 2 histogrammes

    //Similaire si seuil% des cases sont similaire
    //Une case est similaire si l la valeur 1 et compris dans l'intervale val2-seuil; val2 +seuil
    //printf("\nd1 : %d\n",d1.id);

    //affiche_Descripteur_image(d1);
    //printf("\nd2 : %d\n",d2.id);
    //affiche_Descripteur_image(d2);
    if (d1.id == d2.id)
    {
        return 0;
    }

    //Construire le tableau d'intersection
    //Une case est similaire si l la valeur 1 et compris dans l'intervale val2-seuil; val2 +seuil
    // On ajoute cette case dans le teableau d'intersection
    int nbCaseIntersection = 0;
    int val1;
    int val2;
    double pourcentage;
    if(RGB_ou_NB==1){
        for (int i = 0; i < tailleHistogrammeNB; i++)
         {
             val1 = d1.histogramme[i];
             val2 = d2.histogramme[i];
            if (val2 - val2 * ((100.0 - seuil) / 100.0) <= val1 && val1 <= val2 + val2 * ((100.0 - seuil) / 100.0))
        {
            nbCaseIntersection++;
        }
    }
        pourcentage = (double)nbCaseIntersection / tailleHistogrammeNB * 100;
    }
    else{
        for (int i = 0; i < tailleHistogramme; i++)
         {
             val1 = d1.histogramme[i];
             val2 = d2.histogramme[i];
            if (val2 - val2 * ((100.0 - seuil) / 100.0) <= val1 && val1 <= val2 + val2 * ((100.0 - seuil) / 100.0))
        {
            nbCaseIntersection++;
        }
    }
        pourcentage = (double)nbCaseIntersection / tailleHistogramme * 100;
    }


    //On obtient un tableau dont la longueur et le nb de cases similaire. On peut en tirer un pourcentage de similarité (sur les 64 cases d'un histogramme)
    //On compare la similarité au seuil
    //printf("\n similaire sur %d cases\n", nbCaseIntersection);


    printf("Similaire à %f pourcents\n", pourcentage);
    if (pourcentage == 100)
    {
        return 0;
    }
    else if (pourcentage >= seuil)
    {
        return 1;
    }

    return 2;
}

/**
 * @brief Recherche par critère
 * @brief Cette fonction permet de rechercher des documents en fonction d'u critère donné
 * @param RGB couleurDominante
 * @param File[] tableau à remplir
 * @param int seuilSimilarité
 */
void rechercheParCritere_image(RGB couleurDominante, FILE *fichiersSimilaires, int seuilSimilarite)
{
    int couleur;
    float nbCouleurRecherche, nbTotal;
    Descripteur_image desc;
    char chemin[255];
    //Calcule de la valeur du RGB
    couleur = quantifie_un_pixelRGB(couleurDominante);
    printf("couleur : %d\n",couleur);
    // Charger la pile de tous les descripteurs avec la fonction dans controle descripteur
    PILE_image pile = init_pile_image();
    pile = chargerPILE_image("base_descripteur_image_RGB",3);
    // Pour chaque fichier faire la comparaison nb_de_données/nb_de_donnee_egal_au_RGB
    while (!PILE_estVide_image(pile))
    {
        pile = dePILE_image(pile, &desc);
        nbCouleurRecherche = desc.histogramme[couleur];
        nbTotal = 0;
        for (int i = 0; i < tailleHistogramme; i++)
        {
            nbTotal += desc.histogramme[i];
        }
        if ((nbCouleurRecherche / nbTotal) * 100 > seuilSimilarite)
        {
            id_to_chemin_image(desc.id,3,chemin);
            fprintf(fichiersSimilaires, "%d %s\n",desc.id, chemin);
        }
    }
    //CSomparer le résultat avec le seuil et garder le fichier si il est au dessus
}

/**
 * @brief Recherche par document
 * @brief Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité
 */
void rechercheParDocument_RGB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite){
    PILE_image pile=init_pile_image();
    Descripteur_image desc1;
    Descripteur_image desc2;
    char chemin[255];
    int id=chemin_to_id_image(cheminVersDocument,3);
    printf("cheminVersDocument : %s %d\n",chemin,id);
    pile=chargerPILE_image("base_descripteur_image_RGB",3);
    while(!PILE_estVide_image(pile)){
        pile=dePILE_image(pile,&desc2);
        if(desc2.id==id){
            desc1=desc2;
        }
    }
    //charger pile
    pile=chargerPILE_image("base_descripteur_image_RGB",3);
    while(!PILE_estVide_image(pile)){
        pile=dePILE_image(pile,&desc2);
        if(desc2.id!=id){
            if(comparaison_image(desc1, desc2, seuilSimilarite,3)<2){
                id_to_chemin_image(desc2.id,3,chemin);
                fprintf(fichiersSimilaires, "%d %s\n", desc2.id,chemin);
            }
        }
    }
}
/**
 * @brief Compare deux documents noir et blanc
 * 
 * @param cheminVersDocument 
 * @param fichiersSimilaires 
 * @param seuilSimilarite 
 */
void rechercheParDocument_NB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite){
    PILE_image pile=init_pile_image();
    Descripteur_image desc1;
    Descripteur_image desc2;
    char chemin[255];
    int id=chemin_to_id_image(cheminVersDocument,1);
    pile=chargerPILE_image("base_descripteur_image_NB",1);
    while(!PILE_estVide_image(pile)){
        pile=dePILE_image(pile,&desc2);
        if(desc2.id==id){
            desc1=desc2;
        }
    }
    //charger pile
    pile=chargerPILE_image("base_descripteur_image_NB",1);
    while(!PILE_estVide_image(pile)){
        pile=dePILE_image(pile,&desc2);
        if(desc2.id!=id){
            if(comparaison_image(desc1, desc2, seuilSimilarite,1)<2){
                id_to_chemin_image(desc2.id,1,chemin);
                fprintf(fichiersSimilaires, "%d %s\n", desc2.id,chemin);
            }
        }
    }
}


void id_to_chemin_image(int id,int NB_RGB,char * chemin){
    FILE* fich;
    int bon_id;
    if(NB_RGB==1){
        fich=fopen("liste_base_image_NB","r");
    }
    else{
        fich=fopen("liste_base_image_RGB","r");
    }
    if(fich!=NULL){
        while(fscanf(fich,"%d %s",&bon_id,chemin)!=EOF){
            if(bon_id==id){
                break;
            }
        }
        fclose(fich);
    }
}

int chemin_to_id_image(char* chemin, int nb_RGB){
    FILE* fich;
    char bon_chemin[255];
    int id;
    if(nb_RGB==1){
        fich=fopen("liste_base_image_NB","r");
    }
    else{
        fich=fopen("liste_base_image_RGB","r");
    }
    if(fich!=NULL){
        while(fscanf(fich,"%d %s",&id,bon_chemin)!=EOF){
            if(strcmp(chemin,bon_chemin)==0){
                break;
            }
        }
    }

    fclose(fich);
    return id;

}


void lancer_recherche_critere()
{
    FILE *fich;
    fich = fopen("Fichiers_similaires", "w+");
    RGB couleur;
    printf("Entrez un code RGB :\nValeur du rouge : ");
    scanf("%d", &couleur.red);
    printf("Valeur du vert : ");
    scanf("%d", &couleur.green);
    printf("Valeur du bleu : ");
    scanf("%d", &couleur.blue);
    rechercheParCritere_image(couleur, fich, 10);
    fclose(fich);
}

void lancer_recherche_document_RGB()
{
    FILE *fich;
    fich = fopen("Fichiers_similaires", "w+");
    char cheminVersDocument[255];
    printf("Entrez un chemin vers un fichier : ");
    scanf("%s",cheminVersDocument);
    rechercheParDocument_RGB(cheminVersDocument, fich,73);
    fclose(fich);
}

void lancer_recherche_document_NB()
{
    FILE *fich;
    fich = fopen("Fichiers_similaires", "w+");
    char cheminVersDocument[255];
    printf("Entrez un chemin vers un fichier : ");
    scanf("%s",cheminVersDocument);
    rechercheParDocument_NB(cheminVersDocument, fich,85);
    fclose(fich);
}


int main(int argc, char const *argv[])
{
    genererDescripteur_imageDossier("../tests/TEST_RGB/txt", 3); // Génération rgb
    genererDescripteur_imageDossier("../tests/TEST_NB/txt", 1);  // Génératio nb
    //lancer_recherche_critere();
    lancer_recherche_document_NB();
    return 0;
}
