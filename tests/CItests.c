#include <stdio.h>
/***
 * On va tester par module et par bloc 
 */

int testIndexationImage(){
    /*
    On utilise le fichier base_descripteur_image_test qui n'a aucune erreur
    On lance une indexation sur les mêmes fichiers via ce fichier de tests
    On compare les deux fichiers
    */
    return 1;
}

int main(int argc, char const *argv[])
{
    int res = testIndexationImage();
    if(res==1){
        printf("Indexation image : OK");
    }
    else
    {
        printf("Indexation image : error");
    }
    
    return 0;
}
