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
 * @brief Permet d'obtenir une pile contenant les mots qui apparaissent ainsi que leurs occurences dans le texte
 * 
 * @param[in] src Descripteur du fichier texte 
 * @param[in,out] p La pile à remplir
 */
void descripteur_de_texte(FILE *src, PILE *p)
{

    char buffer[MAX_WORD];
    while (fscanf(src, "%s ", buffer) != EOF)
    {
        if (!estDanslaPile(*p, buffer) == 1)
        {
            *p = emPILE(*p, affecter_MOT(buffer));
            estDanslaPile(*p, buffer);
        }
    }
}

/**
 * @brief Permet de concevoir un descripteur et à l'empiler
 * 
 * @param[in] path_to_xml chemin vers un fichier xml
 * @param[in,out] pile_desc Pile de descripteurs
 */
void fabrique_a_descripteur(char *path_to_xml, PILE_descripteur_texte *pile_desc)
{

    FILE *tmp = fopen("tmp", "w+");   //fichier de destination du xml_cleaner
    FILE *tmp1 = fopen("tmp1", "w+"); // fichier de destination du xml_tokenizer
    FILE *src = fopen(path_to_xml, "r");
    PILE p = init_pile();
    
    if (tmp && tmp1 && src)
    {
        xml_cleaner(src, tmp);
        rewind(tmp);
        xml_filter(tmp, tmp1);
        rewind(tmp1);
        descripteur_de_texte(tmp1, &p);
        EMPILE_desc_from_pile(p, pile_desc);

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

int Descripteur_texte_dossier(char *nom_dossier, PILE_descripteur_texte *pile_desc)
{
    FILE *f = fopen("nom_fichiers.txt", "w+");
    if (f)
    {
        lecture_dossier(f, nom_dossier);
        char path_to_xml[MAX_WORD];
        char nom_fichier[MAX_WORD / 2];
        while (fscanf(f, "%s", nom_fichier) != EOF)
        {
            path_maker(path_to_xml, "Textes_UTF8", nom_fichier); //permet de recuperer le chemin vers un fichier xml dans path_to_xml
            fabrique_a_descripteur(path_to_xml, pile_desc);
            
        }
        fclose(f);
        return 1;
    }

    return 0;
}

void Descripteur_texte_fichier(char *nom_fichier, PILE_descripteur_texte *pile_desc)
{
    fabrique_a_descripteur(nom_fichier, pile_desc);
}

int main(void)
{
    PILE_descripteur_texte pile = init_PILE_desc();
    PILE_descripteur_texte pile1 = init_PILE_desc();
    Descripteur_texte_dossier("Textes_UTF8", &pile);
    //Descripteur_texte_fichier("Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml",&pile);
    enregistre_PILE_Desc(pile, "sauvegarde.desc");
    charger_PILE_Desc(&pile1, "sauvegarde.desc");
    affiche_PILE(pile1->pile_mot);
    printf("nombre total de mots : %d\tnombre de mots differents : %d\n",pile1->nombre_mots_total,pile1->nbr_mots_retenus);
    printf("nombre total de mots : %d\tnombre de mots differents : %d\n",pile->nombre_mots_total,pile->nbr_mots_retenus);
}