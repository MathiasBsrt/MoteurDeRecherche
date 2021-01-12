#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descripteur.h"

int main(int argc, char * argv[])
{
    if(argc == 0 || argc > 3)
    {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        fprintf(stderr, "\tPour vérifier si file2 est dans file1.");
        return 1;
    }

    char * filename1 = argv[1];
    char * filename2 = argv[2];

    int n = 5;
    int fetch_n_best = 3;
    char * chemin1 = "TEST_SON/corpus_fi.wav";

    DESC_AUDIO desc1 = init_DESC_AUDIO(0, n, 30, chemin1);
    //char * chemin2 = "TEST_SON/jingle_fi.wav";
    //DESC_AUDIO desc2 = init_DESC_AUDIO(1, n, 30, chemin2);
    char * chemin2 = "TEST_SON/cymbale.wav";
    DESC_AUDIO desc2 = init_DESC_AUDIO(2, n, 30, chemin2);
    RES_EVAL_AUDIO resultat = evaluer_DESC_AUDIO(desc1, desc2, fetch_n_best);
    if(resultat.n == 0)
    {
        printf("%s n'a pas été trouvé dans %s !\n", chemin2, chemin1);
        return 0;
    }
    printf("%s a été trouvé dans %s !\n", chemin2, chemin1);
    printf("      %d meilleurs temps trouvés:\n", fetch_n_best);
    for(int i = 0; i < resultat.n; i++)
    {
        printf("      i = %d: %f\n", i, resultat.times[i]);
    }

}