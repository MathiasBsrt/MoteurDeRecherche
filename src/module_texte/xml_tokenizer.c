/**
 * @file xml_tokenizer.c
 * @author Baptiste POMARELLE
 * @brief Fonctions de nettoyage de fichiers .clean
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Header.h"
/**
 * @brief Permet de créer une pile contenant tous les stopwords
 * 
 * @return PILE pile de stopwords
 */
PILE pile_stopwords()
{
    FILE *stopwords = fopen("stopwords.txt", "r");
    if (stopwords)
    {
        char buffer[MAX_WORD];
        PILE pile_stopwords = init_pile();
        while (fscanf(stopwords, "%s", buffer) != EOF) //mise en mémoire des stopwords
            pile_stopwords = emPILE(pile_stopwords, affecter_MOT(buffer));

        fclose(stopwords);
        return pile_stopwords;
    }
    else
    {
        fprintf(stderr, "Probleme d'ouverture des stopwords");
        exit(2);
    }
}

void xml_filter(FILE *src, FILE *dest)

{
    char buffer[MAX_WORD];
    PILE pileStopwords = pile_stopwords();
    while (fscanf(src, "%s ", buffer) != EOF)
    {
        if (!estDanslaPile(pileStopwords, buffer))
            fprintf(dest, "%s ", buffer);
    }
}
