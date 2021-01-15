#include "../module_texte/Header.h"



void chargement_desc_texte(PILE_descripteur_texte *pile_desc, Table_Index *table_index, int *ind_sauv)
{
    if (*pile_desc || *table_index)
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
            *table_index = NULL;
            charger_PILE_Desc(pile_desc, "sauvegardes/sauvegarde.desc");
            charger_Table_index(table_index, "sauvegardes/sauvegarde.index");
            printf("Chargement des données réussie.");
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
        charger_PILE_Desc(pile_desc, "sauvegardes/sauvegarde.desc");
        charger_Table_index(table_index, "sauvegardes/sauvegarde.index");
        printf("Chargement des données réussie.");
        *ind_sauv = 1;
        sleep(5);
    }
}

void MenuIndexation_texte()
{
    int indice_sauvegarde = 0;
    int code;
    PILE_descripteur_texte pile_desc = init_PILE_desc();
    Table_Index table_index = Init_Index();
    do
    {
        system("clear");
        //Déclarations de variables
        char buffer[MAX_INPUT];
        int seuil, valeur_Limite;

        //Affichage du menu
        printf("///\tMENU INDEXATION TEXTE\t///\n");
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
            printf("Entrer un nom de fichier à indexer : ");
            scanf("%s", buffer);
            do
            {
                printf("Entrer maintenant un seuil qui définira les mots ignorés en fonction de leur nombre d'apparition (0 pour ignorer ce paramètre) : ");
                scanf("%d", &seuil);
            } while (seuil < 0);

            Descripteur_texte_fichier(buffer, &pile_desc, &table_index, seuil);
            printf("\t=======INDEXATION FICHIERS TERMINÉE=======\n");
            printf("Retour au menu Indexation texte...\n");
            sleep(5);
        }
        else if (code == 2)
        {
            if (indice_sauvegarde)
                indice_sauvegarde = 0;
            printf("Entrer un nom de dossier à indexer : ");
            scanf("%s", buffer);
            do
            {
                printf("Entrer maintenant un seuil qui définira les mots ignorés en fonction de leur nombre d'apparition (0 pour ignorer ce paramètre) : ");
                scanf("%d", &seuil);
            } while (seuil < 0);
            Descripteur_texte_dossier(buffer, &pile_desc, &table_index, seuil);
            printf("\t=======INDEXATION DOSSIER TERMINÉE=======\n");
            printf("Retour au menu Indexation texte...\n");
            sleep(5);
        }
        else if (code == 3)
        {
            printf("Sauvegarde de la base de descripteurs...\n");
            enregistre_PILE_Desc(pile_desc, "sauvegardes/sauvegarde.desc");
            printf("Sauvegarde de la Table des Index...\n");
            enregistre_Table_Index(table_index, "sauvegardes/sauvegarde.index");
            printf("Sauvegarde effectuée avec succès !\n");
            sleep(5);
            indice_sauvegarde = 1;
        }
        else if (code == 4)
        {
            chargement_desc_texte(&pile_desc, &table_index,&indice_sauvegarde);
        }

    } while (code != 5);
    if (code == 5 && !indice_sauvegarde)
    {
        char choix;
        system("clear");
        printf("///\t ATTENTION TYE FADA OH TYA PAS SAUVEGARDE BB\n///\t C'EST PAS GRAVE BB ON T'EN VEUX PAS\n\tTU VEUX SAUVEGARDER OU PAS OH?(y/n) ");
        while ((choix = getchar()) != 'y' && choix != 'n')
            ;
        switch (choix)
        {
        case 'y':
        {
            printf("Sauvegarde de la base de descripteurs...\n");
            enregistre_PILE_Desc(pile_desc, "sauvegardes/sauvegarde.desc");
            printf("Sauvegarde de la Table des Index...\n");
            enregistre_Table_Index(table_index, "sauvegardes/sauvegarde.index");
            printf("Sauvegarde effectuée avec succès !\n");
            sleep(5);
            break;
        }
        case 'n':
            printf("OK TANT PIS BB SPA LA MORT OH\n");
            sleep(5);
            break;
        }
    }
}

void MenuIndexation()
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

            MenuIndexation_texte();
        }
    } while (code != 4);
}

void menus_admin()
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
            MenuIndexation();
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
    menus_admin();
    remove("sauvegardes/liste_base_descripteurs");
    system("clear");
    return 0;
}