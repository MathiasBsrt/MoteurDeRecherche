/***
 * Ici les tests de la recherche texte
 */
//#SI notre prog de test retourn 1 : echec de la pipeline
#include "recherche.h"
#include "indexation.h"

int main(int argc, char const *argv[])
{
    int res = 0;
    res = res || indexationImage();
    res = res || indexationSon();
    res = res || indexationTexte();
    res = res || rechercheImage();
    res = res || rechercheSon();
    res = res || rechercheTexte();

    return res;
}
