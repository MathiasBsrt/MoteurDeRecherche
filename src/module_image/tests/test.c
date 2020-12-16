#include "controle_descripteur.h"
#include <string.h>
#include <stdio.h>

int test_RGB(){
    //lancer une indexation du dossier TEST_RGB
    char cheminFichier[] = "";
    
     // pour chaque fichier d'un dossier

    // Comparer base_descripteur_image et base_descripteur_image_OK
    //Utilistion de diff (cmd unix)

    char cmd[100] = "diff ../base_descripteur_image base_descripteur_image_OK";

    int resCmd = system(cmd); //retourne 0 si égaux

    return resCmd;
}
int main(int argc, char const *argv[])
{
    test_RGB();
    return 0;
}
