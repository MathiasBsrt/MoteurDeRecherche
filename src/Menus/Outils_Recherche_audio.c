/**
 * @file Outils_Index_audio.c
 * @author Baptiste Pomarelle
 * @brief 
 * @version 0.1
 * @date 2021-01-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "header.h"


void MenuRecherche_audio(PILE_AUDIO *pile_audio)
{
    int code, choix_indexation;
    char buffer[MAX_INPUT];
    int id, n, m;

    int indice_sauvegarde = 1;

    init_FICHIER_BASE_DESC();
    DESC_AUDIO descripteur;
    do
    {
        system("clear");
        //Affichage du menu
        printf("///\tMENU RECHERCHE AUDIO\t///\n");
        printf("1. Recherche par document\n3. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 3)
        {
            printf("Veuillez choisir une action valide.\n");
            sleep(3);
        }
        else if (code == 1) //Recherche par doc
        {
            //Demander chemin fichier filename
            char filename1[MAX_STRING];
            int codeRetour = 0;
            int fetch_n_best = 3;

            RES_RECHERCHE_AUDIO resultat = rechercher_DESC_AUDIO(filename1, fetch_n_best, EVAL_VERYTOUGH, &codeRetour);
        }

    } while (code != 2);
}