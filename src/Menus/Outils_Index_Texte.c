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

void Affichage_texte(PILE_descripteur_texte pile)
{
    int code;
    //do
   // {
        printf("///\tAffichage des descripteurs textes\t///\n");
        printf("Veuillez utiliser les flèches pour afficher le descripteur de votre choix\n");
   // } while (code!=);
    
}

void MenuIndexation_texte(PILE_descripteur_texte *pile, Table_Index* table)
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
        printf("///\tMENU INDEXATION TEXTE\t///\n");
        printf("1. Indexer un fichier\n2. Indexer un dossier\n3. Sauvegarder la progression\n4. Charger la progression\n5. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 5)
        {
            printf("Veuillez choisir une action valide.\n");
            sleep(3);
        }

        else if (code == 1)
        {
            if (indice_sauvegarde)
                indice_sauvegarde = 0;
            printf("Entrer un nom de fichier à indexer : ");
            scanf("%s", buffer);
            do
            {
                printf("Entrer maintenant un seuil qui définira les mots ignorés en fonction de leur nombre d'apparition (0 pour ignorer ce paramètre) : ");
                scanf("%d", &seuil);
            } while (seuil < 0);

            Descripteur_texte_fichier(buffer, pile, table, seuil);
            printf("\t=======INDEXATION FICHIERS TERMINÉE=======\n");
            printf("Retour au menu Indexation texte...\n");
            sleep(5);
        }
        else if (code == 2)
        {
            if (indice_sauvegarde)
                indice_sauvegarde = 0;
            printf("Entrer un nom de dossier à indexer : ");
            scanf("%s", buffer);
            do
            {
                printf("Entrer maintenant un seuil qui définira les mots ignorés en fonction de leur nombre d'apparition (0 pour ignorer ce paramètre) : ");
                scanf("%d", &seuil);
            } while (seuil < 0);
            Descripteur_texte_dossier(buffer, pile, table, seuil);
            printf("\t=======INDEXATION DOSSIER TERMINÉE=======\n");
            printf("Retour au menu Indexation texte...\n");
            sleep(5);
        }
        else if (code == 3)
        {
            printf("Sauvegarde de la base de descripteurs...\n");
            enregistre_PILE_Desc(*pile, "sauvegardes/sauvegarde.desc");
            printf("Sauvegarde de la Table des Index...\n");
            enregistre_Table_Index(*table, "sauvegardes/sauvegarde.index");
            printf("Sauvegarde effectuée avec succès !\n");
            sleep(5);
            indice_sauvegarde = 1;
        }
        else if (code == 4)
        {
            chargement_desc_texte(pile, table, &indice_sauvegarde);
        }

    } while (code != 5);
    if (code == 5 && !indice_sauvegarde)
    {
        char choix;
        system("clear");
        printf("///\t ATTENTION TYE FADA OH TYA PAS SAUVEGARDE BB\n///\t C'EST PAS GRAVE BB ON T'EN VEUX PAS\n\tTU VEUX SAUVEGARDER OU PAS OH?(y/n) ");
        while ((choix = getchar()) != 'y' && choix != 'n')
            ;
        switch (choix)
        {
        case 'y':
        {
            printf("Sauvegarde de la base de descripteurs...\n");
            enregistre_PILE_Desc(*pile, "sauvegardes/sauvegarde.desc");
            printf("Sauvegarde de la Table des Index...\n");
            enregistre_Table_Index(*table, "sauvegardes/sauvegarde.index");
            printf("Sauvegarde effectuée avec succès !\n");
            sleep(5);
            break;
        }
        case 'n':
            printf("OK TANT PIS BB SPA LA MORT OH\n");
            sleep(5);
            break;
        }
    }
}


// module_texte/Textes_UTF8