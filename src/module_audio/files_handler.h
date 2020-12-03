#ifndef FILES_HANDLER_AUDIO_H_INCLUS 

#define FILES_HANDLER_AUDIO_H_INCLUS

#include "histogramme.h"

/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension TXT
*  @param char * chemin, chemin vers le fichier d'extension .txt
*  @param int k, nombre de fenêtre d'analyse
*  @param int m, nombre d'intervalles
*
*  @return HISTOGRAMME_AUDIO, l'histogramme créé
*/
HISTOGRAMME_AUDIO creer_histogramme_TXT_DESC_AUDIO(char *, int, int);


#endif