#ifndef HISTOGRAMME_AUDIO_H_INCLUS 

#define HISTOGRAMME_AUDIO_H_INCLUS

#define HISTOGRAMME_CREER_SUCCES 0
#define HISTOGRAMME_CREER_ERREUR 1

/** Représentation d'un histogramme utile pour un descripteur audio */
typedef struct Histogramme_Audio_t
{
	unsigned int k; /**< k, nombre de fenêtre d'analyse (mémo: nb colonnes)*/
	unsigned int m; /**< m, nombre d'intervalles (mémo: nb ligne) */
	int * mat; /**< Histogramme, soit une matrice k x m,
						de points (double)
						Indices: [K, M]
						*/
} HISTOGRAMME_AUDIO;


/** Initilalise un histogramme audio
* Utilité: Générale
* @param int k nombre de fenêtre d'analyse
* @param int m nombre d'intervalles
*
* @return HISTOGRAMME_AUDIO histo l'histogramme audio initialisé
*/
HISTOGRAMME_AUDIO init_HISTOGRAMME_AUDIO(int, int);

/** Afficher l'histogramme comme une matrice
* Utilité: Générale
* @param HISTOGRAMME_AUDIO desc histogramme audio
*/
void affiche_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO);

/** Retourne l'entier à l'index k,m
* Utilité: Générale
* @param HISTOGRAMME_AUDIO desc histogramme audio
* @param int k index odronnée
* @param int m index abscisse
*
* @return double la valeur réel à l'index k,m
*/
int get_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, int, int);

/** Affecte un réels à l'index k,m
* Utilité: Générale
* @param HISTOGRAMME_AUDIO * desc pointeur d'histogramme audio
* @param int k index odronnée
* @param int m index abscisse
* @param double val valeur réel à affecter
*/
void set_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, int, int, int);

/** Incremente de 1 la valeur à l'index k,m
* Utilité: Indexation
* @param HISTOGRAMME_AUDIO * desc pointeur d'histogramme audio
* @param int k index odronnée
* @param int m index abscisse
*/
void inc_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, int, int);

/**
*	Compare deux histogrammes audio
* 	Utilité: Indexation
*
*	@param HISTOGRAMME_AUDIO histo1, premier histogramme à comparer
*	@param HISTOGRAMME_AUDIO histo2, second histogramme à comparer
*	@return int, 0 si égaux, != 0 si différents
*/
int compare_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, HISTOGRAMME_AUDIO);

/**
*	Evalue la comparaison des deux histogrammes audio passés en paramètres.
*   Attention ! Cette comparaison n'est pas la même qu'avec compare_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, HISTOGRAMME_AUDIO).
*	Celle-ci retourne un taux de ressemblance.
* 	Utilité: Recherche
*
*	@param HISTOGRAMME_AUDIO histo1, premier histogramme à évaluer
*	@param HISTOGRAMME_AUDIO histo2, second histogramme à évaluer
*	@param int duration1 durée du premier fichier
*	@param int duration2 durée du second fichier
*	@return double, l'évalution des deux histogrammes audio passés en paramètres
*/
double evaluer_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, HISTOGRAMME_AUDIO, int, int);


/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension TXT, BIN ou WAV.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO *, l'histogramme créé
*  @param char * chemin, chemin vers le fichier d'extension .txt, .bin ou .wav
*  @param int k, nombre de fenêtre d'analyse
*  @param int m, nombre d'intervalles
*
*  @return int, code de retour
*/
int generer_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, char *, int, int);

/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension TXT.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO *, l'histogramme créé
*  @param char * chemin, chemin vers le fichier d'extension .txt
*  @param int k, nombre de fenêtre d'analyse
*  @param int m, nombre d'intervalles
*
*  @return int, code de retour
*/
int creer_histogramme_TXT_DESC_AUDIO(HISTOGRAMME_AUDIO *, char *, int, int);

/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension BIN.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO *, l'histogramme créé
*  @param char * chemin, chemin vers le fichier d'extension .bin
*  @param int k, nombre de fenêtre d'analyse
*  @param int m, nombre d'intervalles
*
*  @return int, code de retour
*/
int creer_histogramme_BIN_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int n, int m);

/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension WAV.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO *, l'histogramme créé
*  @param char * chemin, chemin vers le fichier d'extension .wav
*  @param int k, nombre de fenêtre d'analyse
*  @param int m, nombre d'intervalles
*
*  @return int, code de retour
*/
int creer_histogramme_WAV_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int n, int m);

/** Libère la mémoire occupée par la matrice de l'histogramme passé en paramètre
* Utilité: Générale
* @param HISTOGRAMME_AUDIO histo histogramme audio
*/
void free_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *);

#endif