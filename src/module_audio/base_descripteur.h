#ifndef BASE_DESC_AUDIO_H_INCLUS 

#define BASE_DESC_AUDIO_H_INCLUS

#include "descripteur.h"
#include "histogramme.h"
#include "pile_dynamique.h"

/** Chemin vers le fichier contenant les descripteurs audios sauvegardés. */
#define BASE_DESC_FICHIER "base_descripteur_audio"

/** Chemin vers le fichier contenant les liens entre descripteurs et fichier */
#define LISTE_BASE_FICHIER "liste_base_audio"

/** Initialise le controleur du fichier BASE_DESC_FICHIER
* @param PILE la pile de descripteurs audios
*/
void init_FICHIER_BASE_DESC(PILE);

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
*
* @return PILE pile la pile de descripteurs audios chargée.
*/
PILE charger_PILE_DESC_AUDIO();

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

/** Récupère le fichier lier au descripteur donné en parmaètre
* @param DESC_AUDIO descripteur audio
*
* @return char * chemin vers le fichier
*/
char * fichier_lier_DESC_AUDIO(DESC_AUDIO);


#endif