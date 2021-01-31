/***
 * Ici les tests de l'indexation
 */
//#SI notre prog de test retourn 1 : echec de la pipeline
#include <stdio.h>
// Includes pour les tests image
#include "../src/module_image/controle_descripteur.h"


int indexationImage(){

    genererDescripteur_image("../src/module_image/tests/TEST_RGB/txt/01.txt", 3);
    genererDescripteur_image("../src/module_image/tests/TEST_NB/txt/51.txt", 1);

    //creationDescripteur("../src/module_image/tests/TEST_RGB/txt/01.txt"); // Génération rgb
    //creationDescripteur("../src/module_image/tests/TEST_NB/txt/51.txt"); // Génératio nb
    
    //Utilistion de diff (cmd unix)
    char cmd[100] = "diff base_descripteur_image_RGB ./TEST_IMAGE/base_descripteur_image_OK";
    //char cmd3[100] = "diff base_descripteur_image_NB ./TEST_IMAGE/base_descripteur_image_OK_NB";


    int resCmd = system(cmd); //retourne 0 si égaux

    char cmd2[100] = "diff liste_base_image_RGB ./TEST_IMAGE/liste_base_image_OK";
    resCmd = resCmd || system(cmd2); //retourne 0 si égaux

    return resCmd;
}

int main(int argc, char const *argv[])
{

    return indexationImage();

}
