#include "Header.h"

#define MAX_WORD 128

void xml_filter(FILE *stopwords, FILE *src, FILE *dest)

{
    PILE pile_stopwords = init_pile();
    char buffer[MAX_WORD];

    while (fscanf(stopwords, "%s", buffer) != EOF) //mise en mémoire des stopwords
        pile_stopwords = emPILE(pile_stopwords, affecter_MOT(buffer));

    while (fscanf(src, "%s ", buffer) != EOF)
    {
        if (!estDanslaPile(pile_stopwords, buffer))
            fprintf(dest, "%s ", buffer);
    }
}

int main(void)
{
    FILE *stopwords = fopen("stopwords.txt", "r");
    FILE *src = fopen("out.clean", "r");
    FILE *dest = fopen("a.tok", "w");
    if (stopwords && src && dest)
    {
        xml_filter(stopwords, src, dest);
        fclose(stopwords);
        fclose(dest);
        fclose(src);
    }
    return 0;
}