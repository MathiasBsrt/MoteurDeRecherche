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
    menus_admin(&pile_desc, &table_index);
    remove("sauvegardes/liste_base_descripteurs");
    system("clear");
    return 0;
    char **fichier;
    fichier = malloc(sizeof(char *) * 350);
    for (int i = 0; i < 350; i++)
    {
        fichier[i] = malloc(sizeof(char) * 512);
    }
}
