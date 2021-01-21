
/**
 * @file pile_dynamique.h
 * @author Baptiste POMARELLE
 * @brief Les fonctions relatives a la pile de mots (et de leurs occurences) et a la pile de descripteurs
 * @version 0.1
 * @date 2020-12-16
 *
 * @copyright Copyright (c) 2020
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "descripteur.h"

/**
 * @brief Structure d'une Cellule
 *
 */
typedef struct s_Cellule_image
{
    Descripteur_image elt;
    struct s_Cellule_image *suivant;
}Cellule_image;

/**
 * @brief Structure d'une pile de mots avec occurences
 *
 */
typedef Cellule_image* PILE_image;

//FONCTIONS POUR PILES DE MOTS

/**
 * @brief Permet de dépiler un élément d'une pile de mots
 *
 * @param[in] p
 * @param[in,out] elt
 * @return La pile sans le dernier element
 */
PILE_image dePILE_image(PILE_image p, Descripteur_image *elt);

/**
 * @brief Permet d'empiler un élément d'une pile de mots
 *
 * @param[in] p
 * @param[in] elt
 * @return La pile avec elt
 */
PILE_image emPILE_image(PILE_image p, Descripteur_image elt);

/**
 * @brief Permet d'initialiser une pile de mots
 *
 * @return une pile vide
 */
PILE_image init_pile_image();

/**
 * @brief Permet d'afficher une pile de mots
 *
 * @param[in] p
 */
void affiche_PILE_image(PILE_image p);

/**
 * @brief Permet de dire si une pile est vide ou non
 *
 * @param[in] p
 * @return 1 si vrai, 0 sinon
 */
int PILE_estVide_image(PILE_image p);

/**
 * @brief Permet de dire si un mot est dans une pile de mots
 *
 * @param[in] p
 * @param[in] buffer
 * @return 1 si vrai, 0 sinon
 */
int estDanslaPile_image(PILE_image p,char *buffer);

PILE_image chargerPILE_image(char* cheminFichier,int RGB_ou_NB);
PILE_image inverserPILE_image(PILE_image pile);



