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

void MenuRecherche_audio()
{
    int code;


    init_FICHIER_BASE_DESC();
    do
    {
        system("clear");
        //Affichage du menu
        printf("///\tMENU RECHERCHE AUDIO\t///\n");
        printf("1. Recherche par document\n2. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 3)
        {
            printf("Veuillez choisir une action valide.\n");
            waiter();
        }
        else if (code == 1) //Recherche par doc
        {
            //Demander chemin fichier filename
            char filename1[MAX_STRING];
            int codeRetour = 0;
            int fetch_n_best = 3;
            do
            {
                printf("Entrer un nom de fichier correct à indexer : ");
                scanf("%s", filename1);
            } while (access(filename1, F_OK));
            RES_RECHERCHE_AUDIO resultat = rechercher_DESC_AUDIO(filename1, fetch_n_best, EVAL_VERYTOUGH, &codeRetour);
            if (codeRetour == RECHERCHE_ERREUR)
            {
                perror("une erreur s'est produite lors de la recherche\n");
            }
            else
            {
                if (resultat.n == 0)
                {
                    printf("Aucun résultat trouvé.\n");
                }
                else
                {
                    printf("Liste des résultats (%d trouvé(s)):\n", resultat.n);
                    for (int i = 0; i < resultat.n; i++)
                    {
                        printf("\t Résultat %d dans le fichier '%s':\n", i + 1, resultat.resultats[i].fichier);
                        for (int j = 0; j < resultat.resultats[i].n; j++)
                        {
                            printf("\t\t j = %d: %f\n", j, resultat.resultats[i].times[j]);
                        }
                    }
                }

                free_RES_RECHERCHE_AUDIO(resultat);
            }
            waiter();
        }

    } while (code != 2);
    
}