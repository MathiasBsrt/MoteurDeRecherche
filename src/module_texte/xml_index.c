/**
 * @file xml_index.c
 * @author Baptiste POMARELLE
 * @brief Fonctions d'indexations et de création de piles de descripteurs
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Header.h"

/**
 * @brief Permet d'enlever un mot dans une pile de mots
 * 
 * @param[in,out] p 
 * @param[in] mot 
 */
void recherche_et_destruction(PILE *p, MOT mot)
{
    Cellule *marqueur;
    Cellule *parcours = *p;
    while (parcours)
    {
        if (compare_MOT(mot, parcours->elt))
        {
            marqueur = parcours;
            break;
        }
        parcours = parcours->suivant;
    }
    parcours = *p;
    while (parcours->suivant != marqueur)
        parcours = parcours->suivant;
    parcours->suivant = marqueur->suivant;
    free(marqueur);
}

/**
 * @brief Permet d'obtenir une pile contenant les mots qui apparaissent ainsi que leurs occurences dans le texte
 * 
 * @param[in] src Descripteur du fichier texte 
 * @param[in,out] p La pile à remplir
 */
void *descripteur_de_texte(FILE *src, PILE *p, Table_Index *table_index, int seuil)
{
    char buffer[MAX_WORD];
    while (fscanf(src, "%s ", buffer) != EOF)
    {
        if (!(estDanslaPile(*p, buffer)))
        {

            *p = emPILE(*p, affecter_MOT(buffer));
            estDanslaPile(*p, buffer);
        }
    }

    Cellule *parcours = *p;
    if (seuil)

    {
        while (parcours)
        {
            if (parcours->elt.nbr_occurrence < seuil)
            {
                recherche_et_destruction(p, parcours->elt);
            }
            parcours = parcours->suivant;
        }
    }
}

int texte_deja_indexe(char *path_to_xml)
{
    int code_retour = 0;
    FILE *liste_base_desc = fopen("liste_base_descripteurs", "r");
    if (liste_base_desc)
    {

        int id_texte;
        char buffer[MAX_STRING];
        while (fscanf(liste_base_desc, "%s %d", buffer, &id_texte) != EOF)
        {

            if (!strcmp(buffer, path_to_xml))
            {
                code_retour = id_texte;

                break;
            }
        }
        fclose(liste_base_desc);
    }
    return code_retour;
}

/**
 * @brief Permet de concevoir un descripteur et à l'empiler
 * 
 * @param[in] path_to_xml chemin vers un fichier xml
 * @param[in,out] pile_desc Pile de descripteurs
 */
void fabrique_a_descripteur(char *path_to_xml, PILE_descripteur_texte *pile_desc, Table_Index *table_index, int seuil)
{

    FILE *tmp = fopen("tmp", "w+");   //fichier de destination du xml_cleaner
    FILE *tmp1 = fopen("tmp1", "w+"); // fichier de destination du xml_tokenizer
    FILE *src = fopen(path_to_xml, "r");
    PILE p = init_pile();

    if (tmp && tmp1 && src)
    {
        if (!texte_deja_indexe(path_to_xml))
        {
            Index *index;
            xml_cleaner(src, tmp);
            rewind(tmp);
            xml_filter(tmp, tmp1);
            rewind(tmp1);

            descripteur_de_texte(tmp1, &p, table_index, seuil);

            EMPILE_desc_from_pile(p, pile_desc, path_to_xml, table_index);
        }
        else
        {
            perror("Texte déjà rentré !\n");
        }

        fclose(tmp);
        fclose(tmp1);
        fclose(src);
    }
    else
    {
        perror("erreur dans l'ouverture des fichiers");
        exit(3);
    }
}

int Descripteur_texte_dossier(char *nom_dossier, PILE_descripteur_texte *pile_desc, Table_Index *table_index, int seuil)
{
    FILE *f = fopen("nom_fichiers.txt", "w+");
    if (f)
    {
        lecture_dossier(f, nom_dossier);
        char path_to_xml[MAX_WORD];
        char nom_fichier[MAX_WORD / 2];
        while (fscanf(f, "%s", nom_fichier) != EOF)
        {
            path_maker(path_to_xml, nom_dossier, nom_fichier); //permet de recuperer le chemin vers un fichier xml dans path_to_xml
            fabrique_a_descripteur(path_to_xml, pile_desc, table_index, seuil);
        }
        fclose(f);
        remove("tmp");
        remove("tmp1");
        remove("nom_fichiers.txt");
        return 1;
    }

    return 0;
}

void Descripteur_texte_fichier(char *nom_fichier, PILE_descripteur_texte *pile_desc, Table_Index *table_index, int seuil)
{
    fabrique_a_descripteur(nom_fichier, pile_desc, table_index, seuil);
    remove("tmp");
    remove("tmp1");
}

int main(void)
{
    PILE_descripteur_texte pile = init_PILE_desc();
    PILE_descripteur_texte pile1 = init_PILE_desc();
    Table_Index table = Init_Index();
    Table_Index table1 = Init_Index();

    //Descripteur_texte_dossier("Textes_UTF8", &pile, &table, 1);
    //Descripteur_texte_fichier("Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml", &pile, &table, 1);
    //affiche_PILE(pile1->pile_mot);

    //Enregistrement Index
    //enregistre_Table_Index(table, "sauvegarde.index");
    //charger_Table_index(&table1, "sauvegarde.index");

    //Enregistrement Pile
    //enregistre_PILE_Desc(pile, "sauvegarde.desc");
    charger_PILE_Desc(&pile1, "sauvegarde.desc");

    //Affichage de quelques resultats
    affiche_PILE(pile1->pile_mot);
    printf("nombre total de mots : %d\tnombre de mots differents : %d\n", pile1->nombre_mots_total, pile1->nbr_mots_retenus);
    //printf("nombre total de mots : %d\tnombre de mots differents : %d\n", pile->nombre_mots_total, pile->nbr_mots_retenus);
    //AFFICHE_table_index(table1);
    remove("liste_base_descripteurs");
}
>>>>>>> Menus
