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


void menus_admin(PILE_descripteur_texte *pile, Table_Index *table,PILE_AUDIO *pile_audio)
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
            MenuIndexation_audio(pile_audio);
        }
        else if (code == 2)
        {
            MenuIndexation_image();
        }
        else if (code == 3)
        {

            MenuIndexation_texte(pile, table);
        }
    } while (code != 4);
}

int main(void)
{
    //PILES ET TABLE POUR L'INDEXATION TEXTE
    PILE_descripteur_texte pile_desc = init_PILE_desc();
    Table_Index table_index = Init_Index();

    //PILE POUR L'AUDIO
    PILE_AUDIO pile_audio=init_PILE_AUDIO();

    menus_admin(&pile_desc, &table_index,&pile_audio);
    remove("sauvegardes/liste_base_descripteurs");
    system("clear");
    return 0;
}
