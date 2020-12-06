#ifndef HISTOGRAMME_AUDIO_H_INCLUS 

#define HISTOGRAMME_AUDIO_H_INCLUS

#define HISTOGRAMME_CREER_SUCCES 0
#define HISTOGRAMME_CREER_ERREUR 1

typedef struct Histogramme_Audio_t
{
	int k; /* k, nombre de fenêtre d'analyse */
	int m; /* m, nombre d'intervalles */
	int * mat; /* Histogramme, soit une matrice k x m,
						de points (double)
						Indices: [K, M]
						*/
} HISTOGRAMME_AUDIO;


/* Initilalise un histogramme audio
Params:
	- int k, nombre de fenêtre d'analyse
	- int m, nombre d'intervalles

Returns:
	- HISTOGRAMME_AUDIO, l'histogramme audio initialisé
*/
HISTOGRAMME_AUDIO init_HISTOGRAMME_AUDIO(int, int);

/* Afficher l'histogramme comme une matrice
Params:
	- HISTOGRAMME_AUDIO desc, histogramme audio
*/
void affiche_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO);

/* Retourne l'entier à l'index k,m
Params:
	- HISTOGRAMME_AUDIO desc, histogramme audio
	- int k, index odronnée
	- int m, index abscisse

Returns:
	- double, la valeur réel à l'index k,m
*/
int get_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, int, int);

/* Affecte un réels à l'index k,m
Params:
	- HISTOGRAMME_AUDIO * desc, pointeur d'histogramme audio
	- int k, index odronnée
	- int m, index abscisse
	- double val, valeur réel à affecter
*/
void set_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, int, int, int);

/* Incremente de 1 la valeur à l'index k,m
Params:
	- HISTOGRAMME_AUDIO * desc, pointeur d'histogramme audio
	- int k, index odronnée
	- int m, index abscisse
*/
void inc_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, int, int);

/**
*	Compare deux histogrammes audio
*
*	@param HISTOGRAMME_AUDIO histo1, premier histogramme à comparer
*	@param HISTOGRAMME_AUDIO histo2, second histogramme à comparer
*	@return int, 0 si égaux, >!= 0 si différents
*/
int compare_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, HISTOGRAMME_AUDIO);


/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension TXT
*  @param HISTOGRAMME_AUDIO *, l'histogramme créé
*  @param char * chemin, chemin vers le fichier d'extension .txt
*  @param int k, nombre de fenêtre d'analyse
*  @param int m, nombre d'intervalles
*
*  @return int, code de retour
*/
int generer_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, char *, int, int);

int creer_histogramme_TXT_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int k, int m);

int creer_histogramme_BIN_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int k, int m);

int creer_histogramme_WAV_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int k, int m);

#endif