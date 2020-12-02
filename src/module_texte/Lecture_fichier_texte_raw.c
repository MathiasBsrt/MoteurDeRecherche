#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define TAILLEMAX 1024

void test_ligne(char *buffer)
{
    regex_t preg;
    const char *regex = "<.*>";
    int test = regcomp(&preg, regex, REG_NOSUB | REG_EXTENDED);
    if (test == 0)
    {
        int match;
        match = regexec(&preg, buffer, 0, NULL, 0);
        regfree(&preg);
        if (match == 0)
        {
            printf("ok\n");
        }
        else if (match == REG_NOMATCH)
        {
            printf("nok\n");
        }
    }
}

char *recup_pattern(char *buffer, FILE *dest)
{
    int err;
    regex_t preg;
    const char *str_regex = "(>.*<)";

    err = regcomp(&preg, str_regex, REG_EXTENDED);
    if (err == 0)
    {
        int match;
        size_t nmatch = 0;
        regmatch_t *pmatch = NULL;

        nmatch = preg.re_nsub;
        pmatch = malloc(sizeof(*pmatch) * nmatch);
        if (pmatch)
        {
            match = regexec(&preg, buffer, nmatch, pmatch, 0);
            regfree(&preg);
            if (match == 0)
            {
                char *retour = NULL; /* On crée une string et on recup les indice de debut et fin correspondant a la regex*/
                int start = pmatch[0].rm_so;
                int end = pmatch[0].rm_eo;
                size_t size = end - start;

                retour = malloc(sizeof(*retour) * (size + 1)); /* On initialise la chaine de caractere avec cette taille*/
                if (retour)
                {
                    strncpy(retour, &buffer[start], size); /*on recupere la string sans les balises*/
                    retour[size - 1] = '\0';
                    fprintf(dest, "%s\n", retour + 1);
                    free(retour);
                }
            }
        }
        else
        {
            fprintf(stderr, "Memoire insuffisante\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main(void)
{
    FILE *file = fopen("aa.xml", "r+");
    FILE *dest = fopen("retour.clean", "w+");
    char buffer[TAILLEMAX];
    while (fgets(buffer, TAILLEMAX, file) != NULL)
    {
        //test_ligne(buffer);
        recup_pattern(buffer, dest);
    }
    fclose(file);
    fclose(dest);
    return 0;
}
*/
