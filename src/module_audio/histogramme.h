#ifndef HISTOGRAMME_AUDIO_H_INCLUS 

#define HISTOGRAMME_AUDIO_H_INCLUS

#define HISTOGRAMME_CREER_SUCCES 0
#define HISTOGRAMME_CREER_ERREUR 1

/** @struct HISTOGRAMME_AUDIO
 * Représentation d'un histogramme utile pour un descripteur audio 
 */
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
* @param int nombre de fenêtre d'analyse (k)
* @param int nombre d'intervalles (m)
*
* @return HISTOGRAMME_AUDIO l'histogramme audio initialisé
*/
HISTOGRAMME_AUDIO init_HISTOGRAMME_AUDIO(int, int);

/** Afficher l'histogramme comme une matrice
* Utilité: Générale
* @param HISTOGRAMME_AUDIO histogramme audio
*/
void affiche_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO);

/** Retourne l'entier à l'index k,m
* Utilité: Générale
* @param HISTOGRAMME_AUDIO histogramme audio
* @param int index odronnée (k)
* @param int index abscisse (m)
*
* @return double la valeur réel à l'index k,m
*/
int get_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, int, int);

/** Affecte un réels à l'index k,m
* Utilité: Générale
* @param HISTOGRAMME_AUDIO * pointeur d'histogramme audio
* @param int index odronnée (k)
* @param int index abscisse (m)
* @param double valeur réel à affecter
*/
void set_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, int, int, int);

/** Incremente de 1 la valeur à l'index k,m
* Utilité: Indexation
* @param HISTOGRAMME_AUDIO * pointeur d'histogramme audio
* @param int index odronnée (k)
* @param int index abscisse (m)
*/
void inc_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, int, int);

/**
*	Compare deux histogrammes audio
* 	Utilité: Indexation
*
*	@param HISTOGRAMME_AUDIO premier histogramme à comparer
*	@param HISTOGRAMME_AUDIO second histogramme à comparer
*	@return int 0 si égaux, != 0 si différents
*/
int compare_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, HISTOGRAMME_AUDIO);

/**
*	Evalue la comparaison des deux histogrammes audio passés en paramètres.
*   Attention ! Cette comparaison n'est pas la même qu'avec compare_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, HISTOGRAMME_AUDIO).
*	Celle-ci retourne un taux de ressemblance.
* 	Utilité: Recherche
*
*	@param HISTOGRAMME_AUDIO premier histogramme à évaluer
*	@param HISTOGRAMME_AUDIO second histogramme à évaluer
*	@param int durée du premier fichier
*	@param int durée du second fichier
*	@return double l'évalution des deux histogrammes audio passés en paramètres
*/
double evaluer_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO, HISTOGRAMME_AUDIO, int, int);


/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension TXT, BIN ou WAV.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO * l'histogramme créé
*  @param char * chemin vers le fichier d'extension .txt, .bin ou .wav
*  @param int nombre de fenêtre d'analyse (k)
*  @param int nombre d'intervalles (m)
*
*  @return int code de retour
*/
int generer_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *, char *, int, int);

/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension TXT.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO * l'histogramme créé
*  @param char * chemin vers le fichier d'extension .txt
*  @param int nombre de fenêtre d'analyse (k)
*  @param int nombre d'intervalles (m)
*
*  @return int code de retour
*/
int creer_histogramme_TXT_DESC_AUDIO(HISTOGRAMME_AUDIO *, char *, int, int);

/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension BIN.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO * l'histogramme créé
*  @param char * chemin vers le fichier d'extension .bin
*  @param int nombre de fenêtre d'analyse (k)
*  @param int nombre d'intervalles (m)
*
*  @return int code de retour
*/
int creer_histogramme_BIN_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int n, int m);

/** Créer un histogramme pour un descripteur audio
*   à partir d'un fichier d'extension WAV.
* 	Utilité: Indexation
*  @param HISTOGRAMME_AUDIO * l'histogramme créé
*  @param char * chemin vers le fichier d'extension .wav
*  @param int nombre de fenêtre d'analyse (k)
*  @param int nombre d'intervalles (m)
*
*  @return int code de retour
*/
int creer_histogramme_WAV_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int n, int m);

/** Libère la mémoire occupée par la matrice de l'histogramme passé en paramètre
* Utilité: Générale
* @param HISTOGRAMME_AUDIO * histogramme audio
*/
void free_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO *);

#endif