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
        pile_retour = charger_PILE_DESC_AUDIO(&nbr);
        printf("Chargement des données réussie.\n%d descripteurs chargés.\n", nbr);
        *ind_sauv = 1;
        waiter();
    }
    return pile_retour;
}

void MenuIndexation_audio(PILE_AUDIO *pile_audio)
{
    int code, choix_indexation;
    char buffer[MAX_INPUT]; 
    int id=0, n, m;

    int indice_sauvegarde = 1;

    init_FICHIER_BASE_DESC();
    DESC_AUDIO descripteur;
    do
    {
        system("clear");
        //Affichage du menu
        printf("///\tMENU INDEXATION AUDIO\t///\n");
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
            do
            {
                printf("Entrer un nom de fichier correct à indexer : ");
                scanf("%s", buffer);
            } while (access(buffer, F_OK));
            do
            {
                printf("Entrer le nombre de fenêtres d'analyses (Valeur recommendée 5): ");
                scanf("%d", &n);
            } while (n < 1);
            do
            {
                printf("Entrer le nombre d'intervalles (Valeur recommendée 30): ");
                scanf("%d", &m);
            } while (m < 1);
            printf("\n\n");
            descripteur = init_DESC_AUDIO(id, n, m, buffer);
            lier_DESC_AUDIO_FICHIER(descripteur, buffer);
            sauvegarder_DESC_AUDIO(*pile_audio, descripteur);
            printf("\t=======INDEXATION FICHIERS TERMINÉE=======\n");
            printf("Retour au menu Indexation audio...\n");
            waiter();
        }
        else if (code == 2)
        {
            if (indice_sauvegarde)
                indice_sauvegarde = 0;
            system("clear");
            //Affichage du menu
            printf("///\tMENU INDEXATION AUDIO\t///\n");
            printf("1. Indexer un fichier\n2. Indexer un dossier\n3. Retour\n");
            printf("Veuillez choisir une action :\n");
            scanf("%d", &code);
            if (code < 1 || code > 4)
            {
                printf("Veuillez choisir une action valide.\n");
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
                    printf("Entrer le nombre de fenêtres d'analyses (Valeur recommandée 5): ");
                    scanf("%d", &n);
                } while (n < 1);
                do
                {
                    printf("Entrer le nombre d'intervalles (Valeur recommandée 30): ");
                    scanf("%d", &m);
                } while (m < 1);
                printf("\n\n");
                init_MULTIPLE_DESC_AUDIO(id, n, m, buffer);
                printf("\t=======INDEXATION DOSSIER TERMINÉE=======\n");
                printf("Retour au menu Indexation audio...\n");
                waiter();
                }
            }
            else if (code == 3)
            {
                printf("Sauvegarde de la base de descripteurs...\n");
                sauvegarder_PILE_DESC_AUDIO(*pile_audio);
                printf("Sauvegarde effectuée avec succès !\n");
                waiter();
                indice_sauvegarde = 1;
            }
            else if (code == 4)
            {
                *pile_audio = chargement_desc_audio(pile_audio, &indice_sauvegarde);
            }
        }
        while (code != 5)
            ;
    }