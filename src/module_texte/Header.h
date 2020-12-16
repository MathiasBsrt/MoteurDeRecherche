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

//FONCTIONS PRINCIPALES

/**
 * @brief Permet d'obtenir un descripteur texte à partir du chemin d'un fichier xml
 * 
 * @param nom_fichier nom du fichier texte
 * @param pile_desc pile de descripteurs dans laquelle on ajoute le descripteur créé
 */
void Descripteur_texte_fichier(char* nom_fichier,PILE_descripteur_texte *pile_desc);
 /**
  * @brief Permet d'obtenir tous les descripteurs texte présents dans un dossier
  * 
  * @param nom_dossier Dossier a traiter
  * @param pile_desc pile de descripteurs dans laquelle on ajoute les descripteurs créés
  * @return int 1 si ça a marché, 0 sinon
  */
int Descripteur_texte_dossier(char* nom_dossier,PILE_descripteur_texte *pile_desc);





// SOUS-FONCTION NECESSAIRES AU FONCTIONNEMENT DES FONCTIONS PRINCIPALES

/**
 * @brief Permet de passer d'un fichier source xml brut à un fichier dest "nettoyé" de ses balises
 * 
 * @param src fichier source a traiter
 * @param dest fichier de sortie nettoyé
 */
void xml_cleaner(FILE *src, FILE *dest);

/**
 * @brief Permet d'obtenir un fichier "nettoyé" de ses stopwords ainsi que de sa ponctuation (et des majuscules)
 * 
 * @param src 
 * @param dest 
 */
void xml_filter(FILE *src, FILE *dest);






// OUTILS 
/**
 * @brief Permet de récupérer les noms de chaque fichier (qui ne sont pas des dossiers)
 * 
 * @param f le descripteur du fichier dans lequel on va enregistrer les noms de fichiers
 * @param nom_dossier le nom du dossier
 */
void lecture_dossier(FILE *f, char *nom_dossier);

/**
 * @brief Permet de mettre un chemin vers un fichier sous forme de chaine de caracteres
 * 
 * @param chemin 
 * @param nom_dossier 
 * @param nom_fichier 
 */
void path_maker(char *chemin, char *nom_dossier, char *nom_fichier);