#ifndef BASE_DESC_AUDIO_H_INCLUS 

#define BASE_DESC_AUDIO_H_INCLUS

#include "descripteur.h"
#include "histogramme.h"
#include "pile_dynamique.h"

/** Chemin vers le fichier contenant les descripteurs audios sauvegardés. */
#define BASE_DESC_FICHIER "base_descripteur_audio"

/** Initialise le controleur du fichier BASE_DESC_FICHIER
* @param PILE pile la pile de descripteurs audios
*/
void init_FICHIER_BASE_DESC(PILE);

/** Sauvegarde un descripteur audio dans la pile des descripteurs
* @param PILE pile la pile de descripteurs audios
* @param DESC_AUDIO desc le descripteur audio à ajouter
*
* @return PILE pile la nouvelle version de la pile de descripteurs audios
*/
PILE sauvegarder_DESC_AUDIO(PILE, DESC_AUDIO);

/** Sauvegarde la pile de descripteurs dans le fichier BASE_DESC_FICHIER
* @param PILE pile la pile de descripteurs audios
*/
void sauvegarder_PILE_DESC_AUDIO(PILE);

/** Charge dans une nouvelle pile de descripteurs les descripteurs présents
* dans le fichier BASE_DESC_FICHIER
*
* @return PILE pile la pile de descripteurs audios chargée.
*/
PILE charger_PILE_DESC_AUDIO();



#endif