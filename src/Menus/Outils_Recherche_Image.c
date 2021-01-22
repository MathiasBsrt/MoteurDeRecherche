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

void txt_to_bmp(char *txt)
{
    char b[7];
    int i = strlen(txt);
    txt[i - 3] = 'b';
    txt[i - 2] = 'm';
    txt[i - 1] = 'p';
    while (txt[i - 1] != '/')
    {
        i--;
    }
    strcpy(b, txt + i);
    txt[i - 1] = '\0';
    while (txt[i] != '/')
    {
        txt[i] = '\0';
        i--;
    }
    strcat(txt, b);
}

void txt_to_png(char *txt)
{
    char b[7];
    int i = strlen(txt);
    txt[i - 3] = 'j';
    txt[i - 2] = 'p';
    txt[i - 1] = 'g';
    while (txt[i - 1] != '/')
    {
        i--;
    }
    strcpy(b, txt + i);
    txt[i - 1] = '\0';
    while (txt[i] != '/')
    {
        txt[i] = '\0';
        i--;
    }
    strcat(txt, b);
}

void MenuRecherche_image()
{
    int code;
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
            printf("Veuillez choisir une action valide.\n");
            waiter();
        }
        else if (code == 1)
        {
            lancer_recherche_critere();
           /* FILE *fich = fopen("sauvegardes/img/Fichiers_similaires", "r");
            char chemin[255];
            float tmp;
            fscanf(fich, "%f %s", &tmp, chemin);
            printf("chemin avant : %s\n", chemin);
            txt_to_png(chemin);
            printf("chemin après : %s\n", chemin);
            char cmd[100] = "eog ";
            system(strcat(cmd, chemin));
            fclose(fich);*/
            waiter();
        }
        else if (code == 2)
        {
            system("clear");
            printf("Vous souhaitez lancer une recherche dans :\n1. Les documents Noirs et Blancs\n2. Les documents RGB\n");
            printf("Veuillez choisir une action :\n");
            scanf("%d", &code);
            if (code < 1 || code > 2)
            {
                printf("Veuillez choisir une action valide.\n");
                waiter();
            }
            else if (code == 1)
            {
                lancer_recherche_document_NB();
                /*FILE *fich = fopen("sauvegardes/img/Fichiers_similaires", "r");
                char chemin[255];
                float tmp;
                fscanf(fich, "%f %s", &tmp, chemin);
                printf("chemin avant : %s\n", chemin);
                txt_to_bmp(chemin);
                printf("chemin après : %s\n", chemin);
                char cmd[100] = "eog ";
                system(strcat(cmd, chemin));
                fclose(fich);*/
                waiter();
            }

            else if (code == 2)
            {
                lancer_recherche_document_RGB();
                /*FILE *fich = fopen("sauvegardes/img/Fichiers_similaires", "r");
                char chemin[255];
                float tmp;
                fscanf(fich, "%f %s", &tmp, chemin);
                printf("chemin avant : %s\n", chemin);
                txt_to_png(chemin);
                printf("chemin après : %s\n", chemin);
                char cmd[100] = "eog ";
                system(strcat(cmd, chemin));
                fclose(fich);*/
                waiter();
            }
        }

    } while (code != 3);
}
//module_image/tests/TEST_RGB/txt