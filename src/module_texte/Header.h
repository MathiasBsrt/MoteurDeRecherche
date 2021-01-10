/**
 * @file Header.h
 * @author Baptiste POMARELLE
 * @brief Header de toute la partie Texte
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "pile/pile_dynamique.h"
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * @def  Correspond au maximum d'une string de 512 caractères
 * 
 */
#define MAX 512

/**
 * @def Correspond a la taille d'un index 
 * 
 */
#define INDEX_LENGTH 64

//FONCTIONS PRINCIPALES

/**
 * @brief Permet d'obtenir un descripteur texte à partir du chemin d'un fichier xml
 * 
 * @param[in] nom_fichier nom du fichier texte
 * @param[in,out] pile_desc pile de descripteurs dans laquelle on ajoute le descripteur créé
 */
void Descripteur_texte_fichier(char *nom_fichier, PILE_descripteur_texte *pile_desc,Table_Index *table_index);


 /**
  * @brief Permet d'obtenir tous les descripteurs texte présents dans un dossier
  * 
  * @param[in] nom_dossier Dossier a traiter
  * @param[in,out] pile_desc pile de descripteurs dans laquelle on ajoute les descripteurs créés
  * @return int 1 si ça a marché, 0 sinon
  */
int Descripteur_texte_dossier(char *nom_dossier, PILE_descripteur_texte *pile_desc,Table_Index *table_index);





// SOUS-FONCTION NECESSAIRES AU FONCTIONNEMENT DES FONCTIONS PRINCIPALES

/**
 * @brief Permet de passer d'un fichier source xml brut à un fichier dest "nettoyé" de ses balises
 * 
 * @param[in] src fichier source a traiter
 * @param[in] dest fichier de sortie nettoyé
 */
void xml_cleaner(FILE *src, FILE *dest);

/**
 * @brief Permet d'obtenir un fichier "nettoyé" de ses stopwords ainsi que de sa ponctuation (et des majuscules)
 * 
 * @param[in] src 
 * @param[in] dest 
 */
void xml_filter(FILE *src, FILE *dest);






// OUTILS 
/**
 * @brief Permet de récupérer les noms de chaque fichier (qui ne sont pas des dossiers)
 * 
 * @param[in] f le descripteur du fichier dans lequel on va enregistrer les noms de fichiers
 * @param[in] nom_dossier le nom du dossier
 */
void lecture_dossier(FILE *f, char *nom_dossier);

/**
 * @brief Permet de mettre un chemin vers un fichier sous forme de chaine de caracteres
 * 
 * @param[in,out] chemin 
 * @param[in] nom_dossier 
 * @param[in] nom_fichier 
 */
void path_maker(char *chemin, char *nom_dossier, char *nom_fichier);