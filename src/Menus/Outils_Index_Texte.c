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
void waiter()
{
    fflush(stdin);
    while (getchar() != '\n')
        ;
    printf("Appuyer sur la touche Entrée pour continuer...\n");
    getchar();
}

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
            charger_PILE_Desc_mot(pile_desc, "sauvegardes/txt/sauvegarde.desc");
            charger_Table_index(table_index, "sauvegardes/txt/sauvegarde.index");
            printf("Chargement des données réussie.\n");
            *ind_sauv = 1;
            waiter();
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
        charger_PILE_Desc_mot(pile_desc, "sauvegardes/txt/sauvegarde.desc");
        charger_Table_index(table_index, "sauvegardes/txt/sauvegarde.index");
        printf("Chargement des données réussie.");
        *ind_sauv = 1;
        waiter();
    }
}

void MenuIndexation_texte(PILE_descripteur_texte *pile, Table_Index *table)
{
    int code;
    //Déclarations de variables
    char buffer[MAX_INPUT];
    int seuil, valeur_Limite;
    charger_PILE_Desc_mot(pile, "sauvegardes/txt/sauvegarde.desc");
    charger_Table_index(table, "sauvegardes/txt/sauvegarde.index");
    do
    {
        system("clear");

        //Affichage du menu
        printf("///\tMENU INDEXATION TEXTE\t///\n");
        printf("1. Indexer un fichier\n2. Indexer un dossier\n3. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 4)
        {
            printf("Veuillez choisir une action valide.\n");
            waiter();
        }

        else if (code == 1)
        {
            do
            {
                printf("Entrer un nom de dossier correct à indexer : ");
                scanf("%s", buffer);
            } while (access(buffer, F_OK));
            do
            {
                printf("Entrer maintenant un seuil qui définira les mots ignorés en fonction de leur nombre d'apparition (0 pour ignorer ce paramètre) : ");
                scanf("%d", &seuil);
            } while (seuil < 0);

            Descripteur_texte_fichier(buffer, pile, table, seuil);
            printf("\t=======INDEXATION FICHIER TERMINÉE=======\n");
            printf("Retour au menu Indexation texte...\n");
            waiter();
        }
        else if (code == 2)
        {
            do
            {
                printf("Entrer un nom de dossier correct à indexer : ");
                scanf("%s", buffer);
            } while (access(buffer, F_OK));
            do
            {
                printf("Entrer maintenant un seuil qui définira les mots ignorés en fonction de leur nombre d'apparition (0 pour ignorer ce paramètre) : ");
                scanf("%d", &seuil);
            } while (seuil < 0);
            Descripteur_texte_dossier(buffer, pile, table, seuil);
            printf("\t=======INDEXATION DOSSIER TERMINÉE=======\n");
            printf("Retour au menu Indexation texte...\n");
            waiter();
        }
    } while (code != 3);

    printf("Sauvegarde de la base de descripteurs...\n");
    enregistre_PILE_Desc(*pile, "sauvegardes/txt/sauvegarde.desc");

    printf("Sauvegarde de la Table des Index...\n");
    enregistre_Table_Index(*table, "sauvegardes/txt/sauvegarde.index");
    printf("Sauvegarde effectuée avec succès !\n");
    waiter();
}

// module_texte/Textes_UTF8