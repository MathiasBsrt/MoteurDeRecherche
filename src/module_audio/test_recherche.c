#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descripteur.h"
#include "base_descripteur.h"

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <file1>\n", argv[0]);
        fprintf(stderr, "\tPour rechercher file1 dans les fichiers déjà indexés.\n");
        return 1;
    }
    
    PILE pileDescripteur = init_PILE();
    init_FICHIER_BASE_DESC();
    DESC_AUDIO descCorpusWAV = init_DESC_AUDIO(0, 5, 30, "TEST_SON/corpus_fi.wav");
    lier_DESC_AUDIO_FICHIER(descCorpusWAV, "TEST_SON/corpus_fi.wav");
    pileDescripteur = sauvegarder_DESC_AUDIO(pileDescripteur, descCorpusWAV);
    DESC_AUDIO descJingleWAV = init_DESC_AUDIO(1, 5, 30, "TEST_SON/jingle_fi.wav");
    lier_DESC_AUDIO_FICHIER(descJingleWAV, "TEST_SON/jingle_fi.wav");
    pileDescripteur = sauvegarder_DESC_AUDIO(pileDescripteur, descJingleWAV);
    DESC_AUDIO descCymbaleWAV = init_DESC_AUDIO(2, 5, 30, "TEST_SON/cymbale.wav");
    lier_DESC_AUDIO_FICHIER(descCymbaleWAV, "TEST_SON/cymbale.wav");
    pileDescripteur = sauvegarder_DESC_AUDIO(pileDescripteur, descCymbaleWAV);
    
    sauvegarder_PILE_DESC_AUDIO(pileDescripteur);

    free_DESC_AUDIO(&descCorpusWAV);
    free_DESC_AUDIO(&descJingleWAV);
    free_DESC_AUDIO(&descCymbaleWAV);

    char * filename1 = argv[1];

    int n = 5;
    int fetch_n_best = 3;
    
    printf("Recherche de '%s' dans d'autres fichiers audio.\n", filename1);

    int code;
    RES_RECHERCHE_AUDIO resultat = rechercher_DESC_AUDIO(filename1, fetch_n_best, EVAL_VERYHIGH, &code);

    if(code == RECHERCHE_ERREUR)
    {
        fprintf(stderr, "Une erreur est survenue pendant la recherche.\n");
        return code;
    }

    if(resultat.n == 0)
    {
        printf("Aucun résultat trouvé.\n");
        return 0;
    }

    printf("Liste des résultats (%d trouvé(s)):\n", resultat.n);
    for(int i = 0; i < resultat.n; i++)
    {
        printf("\t Résultat %d dans le fichier '%s':\n", i + 1, resultat.resultats[i].fichier);
        for(int j = 0; j < resultat.resultats[i].n; j++)
        {
        printf("\t\t j = %d: %f\n", j, resultat.resultats[i].times[j]);
        }
    }

}