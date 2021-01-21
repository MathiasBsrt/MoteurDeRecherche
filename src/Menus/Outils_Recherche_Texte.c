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
            waiter();
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