#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512

void add_char(char *buffer, char c,int *cpt)
{
    buffer[*cpt] = c;
    *cpt++;
}

int xml_cleaner(FILE *src, FILE *dest)
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
                add_char(buffer,parcours,&nbr_char);
            }
            else
            {
                fprintf(dest, "%s", buffer);
                strcpy(buffer, "");
                nbr_char = 0;
                add_char(buffer,parcours,&nbr_char);
            }

        } while ((parcours = fgetc(src)) != EOF);
        if (nbr_char != 0)
        {
            buffer[nbr_char] = '\0';
            fprintf(dest, "%s", buffer);
        }
}

