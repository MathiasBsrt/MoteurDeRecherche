#include "controle_descripteur.h"

int test_IndexationImage(){

    genererDescripteurDossier("tests/TEST_RGB/txt"); // Génération rgb
    //genererDescripteurDossier("tests/TEST_NB/txt"); // Génératio nb
    
    //Utilistion de diff (cmd unix)
    char cmd[100] = "diff ../base_descripteur_image base_descripteur_image_OK";

    int resCmd = system(cmd); //retourne 0 si égaux

    return resCmd;
}
/*int main(int argc, char const *argv[])
{
    test_IndexationImage();
    return 0;
}*/
