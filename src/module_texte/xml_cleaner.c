#include "Header.h"


void add_char(char *buffer, char c, int *cpt)
{
    c = tolower(c);
    buffer[*cpt] = c;
    *cpt = *cpt + 1;
}

int estPonctuation(char c)
{
    return (c == '.' || c == ',' || c == '?' || c == ';' || c == '!' || c == '\'' || c == ':' || c == '"' || c == '&' || c == '(' || c == ')' || c == '-' || c == '_');
}

void xml_cleaner(FILE *src, FILE *dest)
{
    char parcours;
    char buffer[MAX];
    int nbr_char = 0;
    parcours = fgetc(src);
    do
    {
        if (parcours == '<')
            while ((parcours = fgetc(src)) != '>')
                ;
        else if (nbr_char < MAX - 1)
        {
            if (estPonctuation(parcours))
                add_char(buffer, ' ', &nbr_char);
            else
                add_char(buffer, parcours, &nbr_char);
        }
        else
        {
            fprintf(dest, "%s", buffer);
            strcpy(buffer, "");
            nbr_char = 0;
            if (estPonctuation(parcours))
                add_char(buffer, ' ', &nbr_char);
            add_char(buffer, parcours, &nbr_char);
        }

    } while ((parcours = fgetc(src)) != EOF);
    if (nbr_char != 0)
    {
        buffer[nbr_char] = '\0';
        fprintf(dest, "%s", buffer);
    }
}

int main(void)
{
    FILE *src = fopen("Textes_UTF8/05-Le_Colombien_Juan_Pablo_Montoya_utf8.xml", "r");
    FILE *dest = fopen("out.clean", "w");
    if (src)
    {
        xml_cleaner(src, dest);
    }
    fclose(src);
    fclose(dest);
    return 0;
}