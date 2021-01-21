/**
 * @file Outils_Index_Image.c
 * @author Baptiste POMARELLE
 * @brief 
 * @version 0.1
 * @date 2021-01-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "header.h"

void MenuRecherche_image()
{
    int code,choix_indexation;
    char buffer[MAX_INPUT];
    do
    {
        system("clear");
        //Affichage du menu
        printf("///\tMENU INDEXATION IMAGE\t///\n");
        printf("1. Recherche par critère\n2. Recherche par document\n3. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 4)
        {
            
        }
        else if (code == 1)
        {
            
        }
        else if (code == 2)
        {

        }

    } while (code != 3);
}