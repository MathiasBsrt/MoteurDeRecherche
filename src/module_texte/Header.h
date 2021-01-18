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
#include <unistd.h>

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
 * @return l'id du texte indexé.
 */
int Descripteur_texte_fichier(char *nom_fichier, PILE_descripteur_texte *pile_desc,Table_Index *table_index,int seuil);


 /**
  * @brief Permet d'obtenir tous les descripteurs texte présents dans un dossier
  * 
  * @param[in] nom_dossier Dossier a traiter
  * @param[in,out] pile_desc pile de descripteurs dans laquelle on ajoute les descripteurs créés
  * @return int 1 si ça a marché, 0 sinon
  */
int Descripteur_texte_dossier(char *nom_dossier, PILE_descripteur_texte *pile_desc,Table_Index *table_index,int seuil);

// Fonction de recherche
/***
 * Compare 2 descripteurs de même type
 * @param Table_Index t1
 * @param Table_Index t2
 * @param double seuilSimilarité => pourcentage de similarité entre 2 mêmes cases de l'histogramme
 * @return 0 si égaux, 1 si similaires, 2 si trop différent
 */
int comparaison(Descripteur_texte *d1, Descripteur_texte *d2, double seuil);

/***
 * Recherche par critère
 * Cette fonction permet de rechercher des documents en fonction d'un critère donné
 * @param String mot à chercher
 * @param Strin[] resultats de la recherche, sous forme de chemin des documents
 * @param double seuilSimilarité 
 */
void rechercheParCritere(char *mot, char *fichiersSimilaires[], int *nbF, double seuilSimilarite);
/***
 * Recherche par document
 * Cette fonction permet de rechercher des documents en fonction d'un document donné
 * @param String cheminVersDocument
 * @param File[] tableau à remplir
 * @param int seuilSimilarité 
 */
void rechercheParDocument(char *cheminVersDocument, char *fichiersSimilaires[], int *nbF, double seuilSimilarite);







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

/***
 * Verifie si un texte a déjà été indexé
 * @param char[] chemin du fichier
 * @return id du fichier si existe sinon 0
 */
int texte_deja_indexe(char *path_to_xml);

/***
 * 
 */

Table_Index rechercheMot(Table_Index a, char *mot);
/***
 * 
 */
Descripteur_texte* getDescripteur_Texte(int id, PILE_descripteur_texte *p);
/***
 * 
 */
void getChemin(int id, char chemin[]);
