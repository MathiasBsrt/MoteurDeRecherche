/**
 * @file header.h
 * @author Baptiste POMARELLE
 * @brief 
 * @version 0.1
 * @date 2021-01-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../module_texte/Header.h"
#include "../module_image/moteur_recherche/moteur.h"
#include "../module_audio/base_descripteur.h"

//1. Outils pour le menu administrateur 

//1.1 Outils partie texte:

/**
 * @brief Sous-menu permettant de charger un descripteur de texte à partir du fichier de sauvegarde
 * 
 * @param[in,out] pile_desc la pile de descripteur a charger
 * @param[in,out] table_index la table d'index a charger 
 * @param[in,out] ind_sauv l'indice qui permet de savoir si l'administrateur à bien pensé à sauvegarder
 */
void chargement_desc_texte(PILE_descripteur_texte *pile_desc, Table_Index *table_index, int *ind_sauv);

/**
 * @brief sous menu permettant de gérer l'indexation de fichiers textes
 * 
 * @param[in,out] pile 
 * @param[in,out] table 
 */
void MenuIndexation_texte(PILE_descripteur_texte *pile, Table_Index* table);


//1.2 Outils partie image :
/**
 * @brief sous menu permettant de gérer l'indexation de fichiers images
 * 
 */
void MenuIndexation_image();


//1.3 Outils partie audio

/**
 * @brief sous menu permettant de gérer l'indexation de fichiers audios
 * 
 */
void MenuIndexation_audio(PILE_AUDIO *pile_audio);

//2 Outils pour le menu user

//3 outils généraux

/**
 * @brief Permet à l'utilisateur de décider de passer a autre chose
 * 
 */
void waiter();