/***
 * Ici les tests de l'indexation
 */
//#SI notre prog de test retourn 1 : echec de la pipeline
#include <stdio.h>

int indexationImage(){
    //Lancer une indexation pour tous les fichiers du dossier de test
    //On récupere les fichiers générés base_descripteur_image et lier_base_image
    //On compare ces deux fichiers avec nos fichiers base_descripteur_image_OK et lier_base_image_OK => ces deux fichiers sont une version confirmée de nos indexations
    int res = 0;

    //if base_descripteur_image != base_descripteur_OK || lier_base_image != lier_base_image_OK

    if(res){
        printf("ERREUR DANS L'INDEXATION DES IMAGES");
    }else{
        printf("SUCCES DANS L'INDEXATION DES IMAGES");
    }
    return res;
}

int indexationTexte(){
    return 0;
}

int indexationSon(){
    return 0;
}

int main(int argc, char const *argv[])
{
    int res = 0;
    res = res || indexationImage();
    res = res || indexationSon();
    res = res || indexationTexte();
    
    return res;
}
