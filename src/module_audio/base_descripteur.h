#ifndef BASE_DESC_AUDIO_H_INCLUS 

#define BASE_DESC_AUDIO_H_INCLUS

#include "descripteur.h"
#include "histogramme.h"
#include "pile_dynamique.h"

/** Chemin vers le fichier contenant les descripteurs audios sauvegardés. */
#define BASE_DESC_FICHIER "base_descripteur_audio"

/** Chemin vers le fichier contenant les liens entre descripteurs et fichier */
#define LISTE_BASE_FICHIER "liste_base_audio"

#define ID_NOT_FOUND -1
#define ALREADY_GENERATED 1

#define RECHERCHE_ERREUR 1
#define RECHERCHE_OK 0

/**	@struct RES_RECHERCHE_AUDIO
 * Definition de la structure d'un résultat de recherche
 */
typedef struct Resultat_Recheche_t
{
    int n; /* < Nombre de résultat */
	RES_EVAL_AUDIO * resultats; /* < Liste des résultats */
} RES_RECHERCHE_AUDIO;

/** Initialise le controleur du fichier BASE_DESC_FICHIER
*/
void init_FICHIER_BASE_DESC();

/** Sauvegarde un descripteur audio dans la pile des descripteurs
* @param PILE la pile de descripteurs audios
* @param DESC_AUDIO le descripteur audio à ajouter
*
* @return PILE la nouvelle version de la pile de descripteurs audios
*/
PILE sauvegarder_DESC_AUDIO(PILE, DESC_AUDIO);

/** Sauvegarde la pile de descripteurs dans le fichier BASE_DESC_FICHIER
* @param PILE la pile de descripteurs audios
*/
void sauvegarder_PILE_DESC_AUDIO(PILE);

/** Charge dans une nouvelle pile de descripteurs les descripteurs présents
* dans le fichier BASE_DESC_FICHIER
* @param nb_charge retourne le nombre de descripteurs chargés (peut être NULL).
*
* @return PILE la pile de descripteurs audios chargée.
*/
PILE charger_PILE_DESC_AUDIO(int * nb_charge);

/** Charge un descripteur audio enregistrer dans BASE_DESC_FICHIER à partir de son identifiant
*
* @return DESC_AUDIO le descripteur chargé.
*/
DESC_AUDIO charger_byid_DESC_AUDIO(int);

/** Charge un descripteur audio enregistrer dans BASE_DESC_FICHIER à partir de son fichier.
* C'est à dire que cette méthode va simplement chercher le descripteur déjà généré.
*
* @return DESC_AUDIO le descripteur chargé.
*/
DESC_AUDIO charger_byname_DESC_AUDIO(char *);

/** Initialise des descripteurs audios à partir d'un chemin vers un dossier comprenant les fichiers audio.
* @param int premier id du premier descripteur (incrémenté à chaque descripteur créé)
* @param int n^2 nombre de fenêtre d'analyse
* @param int nombre d'intervalles
* @param char * chemin vers le dossier contenant les fichiers à tratier
*
* @return PILE pile pile contenant les descripteurs créés
*/
PILE init_MULTIPLE_DESC_AUDIO(int, int, int, char *);

/** Lie un descripteur audio à un fichier
* @param DESC_AUDIO  descripteur audio à lier à un fichier
* @param char * chemin vers le fichier
*
* @return int 1 si le fichier était déjà lier et qu'il a était sur-lié, 0 si il a été ajouté sans aucune autre manipulation.
*/
int lier_DESC_AUDIO_FICHIER(DESC_AUDIO, char *);

/** Récupère l'identifiant du descripteur audio associé à ce fichier.
 *  @param char * chemin vers le fichier
 * 
 *  @return int identifiant du descripteur
 */
int get_id_byname_DESC_AUDIO(char *);

/** Permet de savoir si un descripteur a déjà été généré à partir du fichier donné
 *  @param char * chemin vers le fichier
 * 
 *  @return int ALREADY_GENERATED (= 1) si déjà généré, 0 sinon
 */
int deja_genere_DESC_AUDIO(char *);


/** Récupère le fichier lier au descripteur donné en parmaètre
* @param DESC_AUDIO descripteur audio
*
* @return char * chemin vers le fichier
*/
char * fichier_lier_DESC_AUDIO(DESC_AUDIO);

/** Effectue une recherche pour le module audio
 *  @param char * chemin vers le fichier source à trouver dans d'autres fichiers déjà indexés
 *  @param unsigned int chercher les n meilleurs temps
 *  @param double seuil de sécurité (voir #define EVAL_... dans descripteur.h)
 *  @param int * code d'erreur (voir #define RECHERCHE_... dans base_descripteur.h)
 * 
 *  @return RES_RECHERCHE_AUDIO le résultat de la recherche
 */
RES_RECHERCHE_AUDIO rechercher_DESC_AUDIO(char *, unsigned int, double, int *);

/**
 * @brief Libère la mémoire occupée par un résultat d'une rechercher par le module audio.
 * 
 * @param resultat le résultat de la recherche
 */
void free_RES_RECHERCHE_AUDIO(RES_RECHERCHE_AUDIO resultat);




#endif