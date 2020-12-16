#include "Header.h"


void add_char(char *buffer, char c, int *cpt)
{
    c = tolower(c);
    buffer[*cpt] = c;
    *cpt = *cpt + 1;
}

int estPonctuation(char c)
{
    return (c == '.' || c == ',' || c == '?' || c == ';' || c == '!' || c == '\'' || c == ':' || c == '"' || c == '&' || c == '(' || c == ')' || c == '-' || c == '_' || c == '%'|| c == '€' );
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

