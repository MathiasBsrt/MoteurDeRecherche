/**
 * @file Outils_Index_Texte.c
 * @author Baptiste POMARELLE
 * @brief 
 * @version 0.1
 * @date 2021-01-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "header.h"

void chargement_desc_texte(PILE_descripteur_texte *pile_desc, Table_Index *table_index, int *ind_sauv)
{
    if (*pile_desc || *table_index)
    {
        char choix;
        do
        {
            system("clear");

            printf("///Votre pile de descripteurs ou votre table d'index n'est pas vide, êtes-vous sur de vouloir écrire par dessus ?(y/n) \n");
            choix = getchar();
        } while (choix != 'y' && choix != 'n');
        switch (choix)
        {
        case 'y':
        {
            *pile_desc = NULL;
            *table_index = NULL;
            charger_PILE_Desc_mot(pile_desc, "sauvegardes/sauvegarde.desc");
            charger_Table_index(table_index, "sauvegardes/sauvegarde.index");
            printf("Chargement des données réussie.\n");
            *ind_sauv = 1;
            sleep(5);
            break;
        }
        case 'n':
            break;
        default:
            break;
        }
    }
    else
    {
        charger_PILE_Desc_mot(pile_desc, "sauvegardes/sauvegarde.desc");
        charger_Table_index(table_index, "sauvegardes/sauvegarde.index");
        printf("Chargement des données réussie.");
        *ind_sauv = 1;
        sleep(5);
    }
}

void MenuRecherche_texte(PILE_descripteur_texte *pile, Table_Index *table)
{
    int indice_sauvegarde = 1;
    int code;

    do
    {
        system("clear");
        //Déclarations de variables
        char buffer[MAX_INPUT];
        int seuil, valeur_Limite;

        //Affichage du menu
        printf("///\tMENU RECHERCHE TEXTE\t///\n");
        printf("1. Recherche par critère\n2. Recherche par document\n3. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 3)
        {
            printf("Veuillez choisir une action valide.\n");
            sleep(3);
        }

        else if (code == 1)
        {

        }
        else if (code == 2)
        {
            
        }

    } while (code != 3);
}

// module_texte/Textes_UTF8