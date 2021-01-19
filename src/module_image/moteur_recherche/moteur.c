#include "moteur.h"

int comparaison(Descripteur d1, Descripteur d2, double seuil)
{
    //Méthode de comparaison : intersection des 2 histogrammes

    //Similaire si seuil% des cases sont similaire
    //Une case est similaire si l la valeur 1 et compris dans l'intervale val2-seuil; val2 +seuil
    printf("\nd1 : \n");
    affiche_Descripteur(d1);
    printf("\nd2 : \n");
    affiche_Descripteur(d2);
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
    for (int i = 0; i < tailleHistogramme; i++)
    {
        val1 = d1.histogramme[i];
        val2 = d2.histogramme[i];
        if (val2 - val2 * ((100.0 - seuil) / 100) <= val1 && val1 <= val2 + val2 * ((100.0 - seuil) / 100))
        {
            nbCaseIntersection++;
        }
    }

    //On obtient un tableau dont la longueur et le nb de cases similaire. On peut en tirer un pourcentage de similarité (sur les 64 cases d'un histogramme)
    //On compare la similarité au seuil
    printf("\n similaire sur %d cases\n", nbCaseIntersection);

    double pourcentage = (double)nbCaseIntersection / tailleHistogramme * 100;

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

/***
 * Recherche par critère
 * Cette fonction permet de rechercher des documents en fonction d'u critère donné
 * @param RGB couleurDominante
 * @param File[] tableau à remplir
 * @param int seuilSimilarité
 */
void rechercheParCritere(RGB couleurDominante, FILE *fichiersSimilaires, int seuilSimilarite)
{
    int couleur;
    float nbCouleurRecherche, nbTotal;
    Descripteur desc;
    char chemin[255];
    //Calcule de la valeur du RGB
    couleur = quantifie_un_pixelRGB(couleurDominante);
    // Charger la pile de tous les descripteurs avec la fonction dans controle descripteur
    PILE pile = init_pile();
    pile = chargerPILE("../base_descripteur_image_RGB");
    // Pour chaque fichier faire la comparaison nb_de_données/nb_de_donnee_egal_au_RGB
    while (!PILE_estVide(pile))
    {
        pile = dePILE(pile, &desc);
        nbCouleurRecherche = desc.histogramme[couleur];
        nbTotal = 0;
        for (int i = 0; i < tailleHistogramme; i++)
        {
            nbTotal += desc.histogramme[i];
        }
        if ((nbCouleurRecherche / nbTotal) * 100 > seuilSimilarite)
        {
            id_to_chemin(desc.id,3,chemin);
            fprintf(fichiersSimilaires, "%d %s",desc.id, chemin);
        }
    }
    //CSomparer le résultat avec le seuil et garder le fichier si il est au dessus
}

/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité
 */
void rechercheParDocument_RGB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite){
    PILE pile=init_pile();
    Descripteur desc1;
    Descripteur desc2;
    char chemin[255];
    int id=chemin_to_id(cheminVersDocument,3);
    pile=chargerPILE("base_descripteur_image_RGB");
    while(!PILE_estVide(pile)){
        pile=dePILE(pile,&desc2);
        if(desc2.id==id){
            desc1=desc2;
        }
    }
    //charger pile
    pile=chargerPILE("base_descripteur_image_RGB");
    while(!PILE_estVide(pile)){
        pile=dePILE(pile,&desc2);
        if(desc2.id!=id){
            if(comparaison(desc1, desc2, seuilSimilarite)<2){
                id_to_chemin(desc2.id,3,chemin);
                fprintf(fichiersSimilaires, "%d %s", desc2.id,chemin);
            }
        }
    }
}

void rechercheParDocument_NB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite){
    PILE pile=init_pile();
    Descripteur desc1;
    Descripteur desc2;
    char chemin[255];
    int id=chemin_to_id(cheminVersDocument,1);
    pile=chargerPILE("base_descripteur_image_NB");
    while(!PILE_estVide(pile)){
        pile=dePILE(pile,&desc2);
        if(desc2.id==id){
            desc1=desc2;
        }
    }
    //charger pile
    pile=chargerPILE("base_descripteur_image_NB");
    while(!PILE_estVide(pile)){
        pile=dePILE(pile,&desc2);
        if(desc2.id!=id){
            if(comparaison(desc1, desc2, seuilSimilarite)<1){
                id_to_chemin(desc2.id,3,chemin);
                fprintf(fichiersSimilaires, "%d %s", desc2.id,chemin);
            }
        }
    }
}
void id_to_chemin(int id,int NB_RGB,char * chemin){
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

int chemin_to_id(char* chemin, int nb_RGB){
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
    printf("Entrez la valeur du vert : ");
    scanf("%d", &couleur.green);
    printf("Entrez la couleur bleu : ");
    scanf("%d", &couleur.blue);
    rechercheParCritere(couleur, fich, 20);
    fclose(fich);
}
/*
int main(int argc, char const *argv[])
{
    lancer_indexation_image();

    lancer_recherche_critere();
    return 0;
}
*/