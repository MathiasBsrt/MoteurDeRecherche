#include "header.h"

void MenuIndexation_image()
{
    int code,choix_indexation;
    char buffer[MAX_INPUT];
    do
    {
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
        else if (code == 1)
        {
            do
            {
                printf("Entrer un nom de dossier correct à indexer : ");
                scanf("%s", buffer);
            } while (access(buffer,F_OK));
            printf("\n\n");
            do
            {
                printf("1. Indexation noir et blanc\n2. Indexation couleur\n");
                printf("Veuillez choisir une action.\n");
                scanf("%d",&choix_indexation);
                if(choix_indexation==2)    choix_indexation=3;
            }while(choix_indexation!=1 && choix_indexation!=3);
            genererDescripteurDossier(buffer,choix_indexation);
            
        }
        else if (code == 2)
        {
            do
            {
                printf("Entrer un nom de fichier correct à indexer : ");
                scanf("%s", buffer);
            } while (access(buffer,F_OK));
            printf("\n\n");
            do
            {
                printf("1. Indexation noir et blanc\n2. Indexation couleur\n");
                printf("Veuillez choisir une action.\n");
                scanf("%d",&choix_indexation);
                if(choix_indexation==2)    choix_indexation=3;
            }while(choix_indexation!=1 && choix_indexation!=3);
        }

    } while (code != 3);
}