#include "Header.h"

int comparaison(Descripteur_texte *d1, Descripteur_texte *d2, double seuil)
{
    //Similaire si seuil% des mots sont similaire
    /****Une case est similaire si :
     * - même mot
     * ET
     * - itération mot val2- seuil<= val1 <= val2 + seuil
    */

    // On ajoute cette case dans le teableau d'intersection
    int nbCaseIntersection = 0;
    char mot1[100];
    char mot2[100];
    int nbR1;
    int nbR2;

    
    if(d2->pile_mot == NULL){
        printf("yo");
    }
    Cellule_mot *parcours_d2 = d2->pile_mot;
        Cellule_mot *parcours_d1 = d1->pile_mot;


    while (parcours_d1 != NULL) // Parcours d1
    {

        nbR1 = parcours_d1->elt.nbr_occurrence;
        strcpy(mot1, parcours_d1->elt.mot);

        while (parcours_d2 != NULL) //Parcours d2
        {
            nbR2 = parcours_d2->elt.nbr_occurrence;
            strcpy(mot2, parcours_d2->elt.mot);
            if (strcmp(mot1, mot2) == 0)
            {
                if (nbR1 - nbR1 * ((100.0 - seuil) / 100) <= nbR2 && nbR2 <= nbR1 + nbR1 * ((100.0 - seuil) / 100))
                {
                    nbCaseIntersection++;
                }
            }
            parcours_d2 = parcours_d2->suivant;
        }

        parcours_d1 = parcours_d1->suivant;
    }
    //On obtient un tableau dont al longueur et le nb de cases similaire. On peut en tirer un pourcentage de similarité
    //On compare la similarité au seuil

    printf("\n similaire sur %d cases\n", nbCaseIntersection);

    double pourcentage = (double)nbCaseIntersection / ((d1->nbr_mots_retenus + d2->nbr_mots_retenus) / 2) * 100;

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

void rechercheParCritere(char *mot, char **fichiersSimilaires, int *nbF, double seuilSimilarite)
{
    printf("recherche par critère...\n");
    PILE_descripteur_texte pile = init_PILE_desc();
    charger_PILE_Desc_mot(&pile, "sauvegarde.desc");
    Table_Index table1 = Init_Index();
    charger_Table_index(&table1, "sauvegarde.index");

    //Dans cette table on cherche l'index du mot pour obtenir la liste des fichiers qui ont ce mot

    Table_Index indexMot;
    indexMot = rechercheMot(table1, mot);

    if (indexMot == NULL)
    {
        fichiersSimilaires = NULL;
    }
    else
    {

        //On compare ce fichier avec tous les autres fichiers en appliquant le seuil
        printf("nb_max=%d\n", indexMot->nb_occ);
        *nbF = indexMot->nb_occ;
        for (int i = 0; i < indexMot->nb_occ; i++)
        {

            char chemin[350];
            getChemin(indexMot->idTxt_avec_occ[0][i], chemin);
            printf("chemin trouvé=%s\n", chemin);
            strcpy(fichiersSimilaires[i], chemin);
        }
    }
}

void getChemin(int id, char chemin[])
{
    FILE *f = fopen("liste_base_descripteurs", "r");
    if (f)
    {
        int idLu;
        while (fscanf(f, "%s", chemin) != EOF)
        {
            fscanf(f, "%d", &idLu);
            if (idLu == id)
            {
                break;
            }
        }
        fclose(f);
    }
}
Descripteur_texte *getDescripteur_Texte(int id, PILE_descripteur_texte *p)
{

    Descripteur_texte *parcours = NULL;
    printf("on cherche le descripteur correspondant\n");
    parcours = *p;
    while (parcours != NULL)
    {
        printf("parcours id :%d\n", parcours->id);

        if (parcours->id == id)
        {
            printf(" descripteur bien trouvé\n\n");

            return parcours;
        }
        parcours = parcours->suivant;
    }
    //printf("%s\n",parcours->pile_mot->elt.mot);
    return parcours;
}

Table_Index rechercheMot(Table_Index a, char *mot)
{
    if (a == NULL)
    {
        printf("mot non trouvé");
        return NULL;
    }
    else if (strcmp(a->mot, mot) == 0)
    {
        return a;
    }
    else if (strcmp(a->mot, mot) > 0)
    {
        return rechercheMot(a->gauche, mot);
    }
    else
    {
        return rechercheMot(a->droit, mot);
    }
}

void rechercheParDocument(char *cheminVersDocument, char *fichiersSimilaires[], int *nbF, double seuilSimilarite)
{

    //On indexe le nouveau document
    PILE_descripteur_texte pile = init_PILE_desc();
    Table_Index table = Init_Index();

    int id = Descripteur_texte_fichier(cheminVersDocument, &pile, &table, 1);


    //Si le fichier n'est pas indexé
    if (pile != NULL)
    {
        //Enregistrement Index
        enregistre_Table_Index(table, "sauvegardes/sauvegarde.index");
        //Enregistrement Pile
        enregistre_PILE_Desc(pile, "sauvegardes/sauvegarde.desc");
    }

    //on charge la pile des descripteurs
    //charger_PILE_Desc_mot(&pile, "sauvegarde.desc");
    
    Descripteur_texte *parcours = NULL;
    printf("on cherche le descripteur correspondant\n");
    parcours = pile;
    while (parcours != NULL)
    {
        //printf("parcours id :%d\n", parcours->id);
        parcours = parcours->suivant;
    }
    //printf("%s\n",parcours->pile_mot->elt.mot);
    
    //On récupéere le descripteur qui vient d'être crée
    Descripteur_texte *desc1 = getDescripteur_Texte(id, &pile);

    //On compare le desc1 avec tous les descripteurs de la pile sauf lui même
    Descripteur_texte *desc2 = pile;
    int res; // resultat de la comparaison
    while (desc2 != NULL)
    {   
        res = comparaison(desc1, desc2, seuilSimilarite);
        if (res < 2)
        {
            getChemin(desc2->id, fichiersSimilaires[*nbF]);
            *nbF++;
        }
        desc2 = desc2->suivant;
    }
}

/*
int main(int argc, char const *argv[])
{

    //Exemple code pour recherchee par critère
    /*char **fichiers;
    fichiers = malloc(sizeof(char *) * 350);
    for (int i=0;i<350;i++)
    {
        fichiers[i]=malloc(sizeof(char)*512);
    }
    int nbF = 0;
    double seuil = 60.0;
    rechercheParCritere("football", fichiers, &nbF, seuil);
    printf("recherche par critère, résulats : \n");
    for (int i = 0; i < nbF; i++)
    {
        printf("%s \n", fichiers[i]);
    }

    //FREEEEEEEE
    printf("\n");

    //Exemple code recherche par document:
    char **fichiers;
    int nbF = 0;
    double seuil = 90.0;

    fichiers = malloc(sizeof(char *) * 350);
    for (int i = 0; i < 350; i++)
    {
        fichiers[i] = malloc(sizeof(char) * 512);
    }
    rechercheParDocument("../module_texte/Textes_UTF8/27-Le_Stade_de_France_s_ouvre_utf8.xml", fichiers, &nbF, seuil);
    printf("recherche par document :<\n");
    for (int i = 0; i < nbF; i++)
    {
        printf("%s \n", fichiers[i]);
    }

    return 0;
}*/
