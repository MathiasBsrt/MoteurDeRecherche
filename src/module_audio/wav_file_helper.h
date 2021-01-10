#ifndef WAV_FILE_HELPER_H_INCLUS 

#define WAV_FILE_HELPER_H_INCLUS

#define WAV_FILE_DOESNT_EXIST -1

/** Récupérer la durée d'un fichier wav.
* Retourne WAV_FILE_DOESNT_EXIST si le fichier n'existe pas.
* @param char * chemin chemin vers le fichier wav
-
* @return int durée exprimée en seconde
*/
int wav_get_duration(char *);

#endif