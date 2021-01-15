
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
typedef struct s_Cellule
{
    Descripteur elt;
    struct s_Cellule *suivant;
}Cellule;

/**
 * @brief Structure d'une pile de mots avec occurences
 * 
 */
typedef Cellule* PILE;

//FONCTIONS POUR PILES DE MOTS

/**
 * @brief Permet de dépiler un élément d'une pile de mots
 * 
 * @param[in] p 
 * @param[in,out] elt 
 * @return La pile sans le dernier element 
 */
PILE dePILE(PILE p, Descripteur *elt);

/**
 * @brief Permet d'empiler un élément d'une pile de mots
 * 
 * @param[in] p 
 * @param[in] elt 
 * @return La pile avec elt
 */
PILE emPILE(PILE p, Descripteur elt);

/**
 * @brief Permet d'initialiser une pile de mots
 * 
 * @return une pile vide
 */
PILE init_pile();

/**
 * @brief Permet d'afficher une pile de mots
 * 
 * @param[in] p 
 */
void affiche_PILE(PILE p);

/**
 * @brief Permet de dire si une pile est vide ou non
 * 
 * @param[in] p 
 * @return 1 si vrai, 0 sinon
 */
int PILE_estVide(PILE p);

/**
 * @brief Permet de dire si un mot est dans une pile de mots
 * 
 * @param[in] p 
 * @param[in] buffer 
 * @return 1 si vrai, 0 sinon
 */
int estDanslaPile(PILE p,char *buffer);

int charger_PILE_Desc(PILE *p, char *save_descripteurs_textes);




/*#include <stdio.h>
#include <stdlib.h>
#include "descripteur.h"
typedef struct s_Cellule
{
    Descripteur elt;
    struct s_Cellule *suivant;
}Cellule;

typedef Cellule* PILE;



PILE init_PILE();
void affiche_PILE(PILE pile);
int PILE_estVide(PILE pile);
PILE emPILE(PILE pile,Descripteur elem);
PILE dePILE(PILE pile, Descripteur* elem);*/
//PILE saisir_PILE();
