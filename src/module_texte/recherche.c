#include "Header.h"

int comparaison(Descripteur_texte *d1, Descripteur_texte *d2, double seuil, Table_Index t, double *pourcentageS)
{
    //Similaire si seuil% des mots sont similaire
    /****Une case est similaire si :
     * - même mot
     * ET
     * - itération mot val2- seuil<= val1 <= val2 + seuil
    */
    // On ajoute cette case dans le teableau d'intersection
    int nbCaseIntersection = 0;

    if (d2->pile_mot == NULL)
    {
        printf("yo");
    }
    Cellule_mot *parcours_d1 = d1->pile_mot;

    parcours_d1 = d1->pile_mot;

    //printf("comparaison de %d et %d\n", d1->id, d2->id);
    Index *index;
    int nbMot = 0; // nombre d mot dans d1;
    //Pour chaque mot de d1, on cherche si d2 est dans la table du mot courant
    while (parcours_d1 != NULL)
    {
        index = ExisteDansTable_Index(t, parcours_d1->elt.mot); //Mise à jour de l'index du mot courant
        nbMot++;
        //On parcours l'index
        for (int i = 0; i < index->nb_occ; i++)
        {
            if (index->idTxt_avec_occ[0][i] == d2->id)
            {
                nbCaseIntersection++;
                break;
            }
        }

        parcours_d1 = parcours_d1->suivant; // Mot suivant
    }

    printf("\nsimilaire sur %d cases\n", nbCaseIntersection);

    double pourcentage = (double)nbCaseIntersection / nbMot * 100;
    *pourcentageS = pourcentage;
    printf("Similaire à %f pourcents\n", pourcentage);
    printf("seuil = %f\n", seuil);
    if (pourcentage == 100.0)
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
    FILE *liste_base_desc = fopen("sauvegardes/liste_base_descripteurs", "r");
    if (liste_base_desc)
    {

        int id_texte;
        fseek(liste_base_desc, 0, SEEK_SET);
        while (fscanf(liste_base_desc, "%s %d", chemin, &id_texte) != EOF)
        {
            if (id_texte == id)
            {
                break;
            }
        }
        fclose(liste_base_desc);
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
    return NULL;
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

int rechercheParDocument(char *cheminVersDocument, char *fichiersSimilaires[], double seuilSimilarite)
{

    //On indexe le nouveau document
    PILE_descripteur_texte pile = init_PILE_desc();
    Table_Index table = Init_Index();
    Descripteur_texte *desc1;
    int nbF = 0;
    int id = texte_deja_indexe(cheminVersDocument);

    if (id == 0)
    {
        id = Descripteur_texte_fichier(cheminVersDocument, &pile, &table, 1); // Bug, idée : le nouveau fichier indexé ecrase la pile ?
    }

    //on charge la pile des descripteurs
    charger_Table_index(&table, "sauvegardes/sauvegarde.index");
    charger_PILE_Desc_mot(&pile, "sauvegardes/sauvegarde.desc");

    //On récupéere le descripteur qui vient d'être crée
    desc1 = getDescripteur_Texte(id, &pile);

    //printf("id du descripteur 1 =%d\n", id);
    //On utilise un tableau pour stocker les chemins ()
    char chemin1[100];
    getChemin(desc1->id, chemin1);
    // printf("chemin = %s\n", chemin1);

    //On stock les pourcentages de similarité pour chaque fichier.
    // On considère les deux tableaux (pourcentages et fichierSimilaires) triés de façon identique et correspodant. 
    //C'est à dire que le pourcentage à l'indice i correspond au chemin à ce même indice
    int pourcentages[350]; 
    double pourcentagesS; // Pourcentage de similarité entre 2 descripteurs,
    if (desc1 != NULL)
    {
        //On compare le desc1 avec tous les descripteurs de la pile sauf lui même
        Descripteur_texte *desc2 = pile;
        int res; // resultat de la comparaison
        while (desc2 != NULL)
        {

            char chemin2[350];
            //printf("\nid du descripteur 2 =%d\n", desc2->id);
            res = comparaison(desc1, desc2, seuilSimilarite, table,&pourcentagesS);
            if (res < 2)
            {
                getChemin(desc2->id, chemin2);
                printf("fichier similaire : %s \n", chemin2);
                if(nbF==0){
                    pourcentages[0] = pourcentagesS;
                    strcpy(fichiersSimilaires[0], chemin2);
                }else{
                    for (int i = 0; i < nbF; i++)
                    {
                        if(){
                            
                        }
                    }
                    
                }
                nbF++;
            }
            desc2 = desc2->suivant;
        }
    }
}