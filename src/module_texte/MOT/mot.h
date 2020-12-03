#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD 128

/**
 * @struct ELEMENT
 * @brief Element de type MOTS
 * */
typedef struct f_mots
{
    char mot[MAX_WORD];
}MOT;

/**
 * @brief Fonction permettant d'afficher un element
 * @param MOT e
 * */
void affiche_MOT(MOT e);

/**
 * @brief Fonction permettant d'entrer un mot a la main
 * 
 * @param MOT *e 
 */

void saisir_MOT(MOT *e);

/**
 * @brief Fonction permettant de comparer deux mots
 * 
 * @param MOT a 
 * @param MOT b 
 * @return The test result
 */
int compare_MOT(MOT a,MOT b);

/**
 * @brief permet d'affecter une valeur a un mot
 * 
 * @param word 
 * @return un mot 
 */
MOT affecter_MOT(char* word);
