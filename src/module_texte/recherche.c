#include "recherche.h"

int comparaison(Descripteur_texte d1, Descripteur_texte d2, double seuil)
{
    //Similaire si seuil% des mots sont similaire
    /****Une case est similaire si :
     * - même mot
     * ET
     * - itération mot val2- seuil<= val1 <= val2 + seuil
    */

    // On ajoute cette case dans le teableau d'intersection
    int nbCaseIntersection = 0;
    char *mot1;
    char *mot2;
    int nbR1;
    int nbR2;

    Cellule *parcours_d1 = d1.pile_mot;
    Cellule *parcours_d2 = d2.pile_mot;

    affiche_PILE(d1.pile_mot);
    //printf("nbR= %d",parcours_d1->elt.nbr_occurrence);

    do // Parcours d1
    {
        nbR1 = parcours_d1->elt.nbr_occurrence;
        strcpy(mot1, parcours_d1->elt.mot);
        do //Parcours d2
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
            parcours_d1 = parcours_d2->suivant;
        } while (parcours_d1 != NULL);

        parcours_d1 = parcours_d1->suivant;
    } while (parcours_d1 != NULL);

    //On obtient un tableau dont al longueur et le nb de cases similaire. On peut en tirer un pourcentage de similarité
    //On compare la similarité au seuil

    printf("\n similaire sur %d cases\n", nbCaseIntersection);

    double pourcentage = (double)nbCaseIntersection / ((d1.nbr_mots_retenus + d2.nbr_mots_retenus) / 2) * 100;

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

void rechercheParCritere(char *mot, int *fichiersSimilairesID, double seuilSimilarite)
{

    PILE_descripteur_texte pile = init_PILE_desc();
    PILE_descripteur_texte pile1 = init_PILE_desc();
    Table_Index table = Init_Index();
    Table_Index table1 = Init_Index();
    Descripteur_texte_dossier("Textes_UTF8", &pile, &table);

    //Charger la table
    enregistre_Table_Index(table, "sauvegarde.index");
    charger_Table_index(&table1, "sauvegarde.index");
    //AFFICHE_table_index(table1);

    //Dans cette table on cherche l'index du mot pour obtenir la liste des fichiers qui ont ce mot

    Table_Index indexMot;
    indexMot = rechercheMot(table1, mot);

    //une liste de tout ses fichiers
    //int *idTxt_avec_occ[2]; tableau 2D des id associés au nombre d'occur du mot
    if (indexMot == NULL)
    {
        fichiersSimilairesID = NULL;
    }
    else
    {
        //Pour tester
        int id = indexMot->idTxt_avec_occ[0][0];
        int nbOcc = indexMot->idTxt_avec_occ[0][1];

        //Creer le descripteur du plus grand
        Descripteur_texte desc1; //pas null, chercher dans la pile

        //On prend le fichier avec le plus grand nb de fois mot
        int fichiers[TAILLEPILE];

        fichiers[0] = desc1.id;
        //On compare ce fichier avec tous les autres fichiers en appliquant le seuil
        for (int i = 1; i < indexMot->nb_max; i++)
        {
            //Creer le descripteur du desc2
            Descripteur_texte desc2; //pas null, chercher dans la pile
            if (comparaison(desc1, desc2, seuilSimilarite) < 2)
            {
                //stock id du desc
                fichiers[i] = desc2.id;
            }
        }

        fichiersSimilairesID = &fichiers;
    }
}

Table_Index *rechercheMot(Table_Index a, char *mot)
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

void rechercheParDocument(char *cheminVersDocument, int *fichiersSimilairesID, double seuilSimilarite)
{
    //Indexer nouveau document
    Descripteur_texte desc1;

    //desc2 => descripteur courant,permet de parcourir la pile
    Descripteur_texte desc2;

    for (int i = 0; i < taillePile; i++)
    {
        desc2 = NULL; //pas null, voir dans pile
        if(comparaison(desc1, desc2, seuilSimilarite) < 2)
        {
            fichiersSimilairesID[i] = desc2.id;
        }
    }
}

int main(int argc, char const *argv[])
{

    FILE *f;
    rechercheParCritere("lyon", f, 80.0);
    /* Descripteur_texte *d1;
    Descripteur_texte *d2;
    PILE_descripteur_texte p;
    charger_PILE_Desc(&p,"sauvegarde.index");
    d1 = p;
    d2 = p->suivant;

    affiche_PILE(d1->pile_mot);*/

    //comparaison(*d1,*d2,80.0);
    return 0;
}
