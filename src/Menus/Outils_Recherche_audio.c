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

PILE_AUDIO chargement_desc_audio(PILE_AUDIO *pile_desc, int *ind_sauv)
{
    int nbr;
    PILE_AUDIO pile_retour;
    if (*pile_desc)
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

            pile_retour = charger_PILE_DESC_AUDIO(&nbr);
            printf("Chargement des données réussie.\n%d descripteurs chargés.\n", nbr);
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
        pile_retour = charger_PILE_DESC_AUDIO(&nbr);
        printf("Chargement des données réussie.\n%d descripteurs chargés.\n", nbr);
        *ind_sauv = 1;
        sleep(5);
    }
    return pile_retour;
}

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
        printf("1. Recherche par critère\n2. Recherche par document\n3. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 3)
        {
            printf("Veuillez choisir une action valide.\n");
            sleep(3);
        }
        else if (code == 1) //Recherche par critère
        {
           
        }
        else if (code == 2) //Recherche par document
        {
            
        }

    } while (code != 3);
}