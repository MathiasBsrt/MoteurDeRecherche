/**
 * @file Interprete_de_commandes.c
 * @author Baptiste POMARELLE
 * @brief 
 * @version 0.1
 * @date 2021-01-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "header.h"

void MenuIndexation(PILE_descripteur_texte *pile, Table_Index *table)
{
    int code;
    do
    {
        system("clear");
        //Affichage du menu
        printf("///\tMENU INDEXATION\t///\n");
        printf("1. Indexation audio\n2. Indexation Image\n3. Indexation Texte\n4. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 4)
        {
            printf("Veuillez choisir une action valide.\n");
        }

        else if (code == 1)
        {
            //MenuIndexation_audio();
        }
        else if (code == 2)
        {

            //MenuIndexation_image();

        }
        else if (code == 3)
        {

            MenuIndexation_texte(pile, table);

        }
    } while (code != 4);
}

void Menu_affichage(PILE_descripteur_texte pile, Table_Index table)
{
    int code;
    do
    {
        system("clear");
        printf("///\tMENU VISUALISATION\t///\n");
        printf("1. Affichage descripteurs audios\n2. Affichage descripteurs image\n3. Affichage descripteurs\n4. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 4)
        {
            printf("Veuillez choisir une action valide.\n");
        }
        else if (code == 1)
        {
        }
        else if (code == 2)
        {
        }
        else if (code == 3)
        {
            Affichage_texte(pile);
        }
    } while (code != 4);
}

void menu_user(PILE_descripteur_texte *pile, Table_Index *table)
{
    int code;
   // do
    //{
        system("clear");
        //Affichage du menu
        printf("///\tMENU USER\t///\n");
        printf("1. Rechercher un texte\n2. Retour\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 2)
        {
            printf("Veuillez choisir une action valide.\n");
        }
        else if (code == 1)
        {
            char **fichiers;
            fichiers = malloc(sizeof(char *) * 350);
            for (int i = 0; i < 350; i++)
            {
                fichiers[i] = malloc(sizeof(char) * 512);
            }
           /* PILE_descripteur_texte p = init_PILE_desc();
            charger_PILE_Desc_mot(&p,"sauvegardes/sauvegarde.desc");
            Descripteur_texte *d1 = getDescripteur_Texte(13,&p);
            Descripteur_texte *d2 = getDescripteur_Texte(13,&p);*/

            //int res = comparaison(d1,d2,80.0);

            
            int nbF = rechercheParDocument_texte("module_texte/Textes_UTF8/27-Le_Stade_de_France_s_ouvre_utf8.xml", fichiers, 13.0);
            printf("nbF principal =%d\n",nbF);
            printf("recherche par document :<\n");
            for (int i = 0; i < nbF; i++)
            {
                printf("%s \n", fichiers[i]);
            }
        }

   // } while (code != 2);
}

void menus_admin(PILE_descripteur_texte *pile, Table_Index *table)
{
    int code;
    do
    {
        system("clear");
        //Affichage du menu
        printf("///\tMENU ADMINISTRATEUR\t///\n");
        printf("1. Indexation\n2. Visualisation des Descripteurs\n3. Controler le monde\n4. Quitter le mode administrateur\n");
        printf("Veuillez choisir une action :\n");
        scanf("%d", &code);
        if (code < 1 || code > 4)
        {
            printf("Veuillez choisir une action valide.\n");
        }
        else if (code == 1)
        {
            MenuIndexation(pile, table);
        }
        else if (code == 2)
        {
            Menu_affichage(*pile, *table);
        }
        else if (code == 3)
        {
            printf("Cette option est encore en cours de développement...\n");
            sleep(5);
        }

    } while (code != 4);
}

int main(void)
{

    PILE_descripteur_texte pile_desc = init_PILE_desc();
    Table_Index table_index = Init_Index();
    menu_user(&pile_desc, &table_index);
    //menus_admin(&pile_desc, &table_index);
    //remove("sauvegardes/liste_base_descripteurs");

    /*
    charger_PILE_Desc_mot(&pile_desc, "sauvegardes/sauvegarde.desc");

    //Exemple code recherche par document:
/*
    char **fichiers;
    int nbF = 0;
    double seuil = 90.0;

    fichiers = malloc(sizeof(char *) * 350);

    for (int i = 0; i < 350; i++)
    {
        fichiers[i] = malloc(sizeof(char) * 512);
    }
    rechercheParDocument("module_texte/Textes_UTF8/27-Le_Stade_de_France_s_ouvre_utf8.xml", fichiers, &nbF, seuil);


    printf("recherche par document :<\n");
    for (int i = 0; i < nbF; i++)
    {
        printf("%s \n", fichiers[i]);
    }

    //system("clear");
    */
    return 0;
}
