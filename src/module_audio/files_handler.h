#ifndef FILES_HANDLER_AUDIO_H_INCLUS 

#define FILES_HANDLER_AUDIO_H_INCLUS

/* Créer un histogramme pour un descripteur audio
   à partir d'un fichier d'extension TXT
Params:
	- char * chemin, chemin vers le fichier d'extension .txt
	- int k, nombre de fenêtre d'analyse
	- int m, nombre d'intervalles

Returns:
	- double *, l'histogramme créer
*/
double * creer_histogramme_TXT_DESC_AUDIO(char *, int, int);


#endif