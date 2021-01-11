#ifndef DESCRIPTEUR_AUDIO_H_INCLUS 

#define DESCRIPTEUR_AUDIO_H_INCLUS

#include <stdlib.h>
#include "histogramme.h"

/**	@struct DESC_AUDIO
 * Definition de la structure d'un descripteur audio
 */
typedef struct Descripteur_Audio_t
{
	int id; /**< Identifiant du descripteur */
	HISTOGRAMME_AUDIO histo; /**< Histogramme du descripteur audio */
} DESC_AUDIO;

/**	@struct RES_EVAL_AUDIO
 * Definition de la structure d'un résultat d'évalutation
 */
typedef struct Resultat_Evalutation_t
{
	int n; /* < Nombre de temps */
	double * times; /* < Les temps trouvés */
} RES_EVAL_AUDIO;

/** Initilalise un descripteur audio
* Utilité: Générale
* @param int id du descripteur
* @param int n^2 nombre de fenêtre d'analyse
* @param int nombre d'intervalles
* @param char * chemin vers le fichier à traiter
*
* @return DESC_AUDIO le descripteur audio initialisé
*/
DESC_AUDIO init_DESC_AUDIO(int, int, int, char *);

/** Initilalise un descripteur audio vide
* @param int id de l'histogramme
* @param int 2^n nombre de fenêtre d'analyse
* @param int nombre d'intervalles
* @param char * chemin vers le fichier à traiter
*
* @return DESC_AUDIO le descripteur audio initialisé
*/
DESC_AUDIO init_vide_DESC_AUDIO(int, int);

/** Retourne le réels à l'index k,m
* Utilité: Générale
* @param DESC_AUDIO descripteur audio
* @param int index ordonné (k)
* @param int index abscisse (m)
*
* @return double la valeur réel à l'index k,m
*/
int get_DESC_AUDIO(DESC_AUDIO, int, int);

/** Affecte un réels à l'index k,m
* Utilité: Générale
* @param DESC_AUDIO * pointeur de descripteur audio
* @param int index ordonné (k)
* @param int index abscisse (m)
* @param double valeur réel à affecter
*/
void set_DESC_AUDIO(DESC_AUDIO *, int, int, int);

/** Affiche un descripteur audio sur la sortie standard (printf)
* Utilité: Générale
* @param DESC_AUDIO le descripteur audio que l'on souhaite afficher
*/
void affiche_DESC_AUDIO(DESC_AUDIO);

/** Affecte les valeurs d'un descripteur audio à un autre
*  On affecte les valeurs du desc2 dans le desc1
* Utilité: Générale
* @param DESC_AUDIO descripteur destinataire de l'affectation
* @param DESC_AUDIO descripteur source de l'affectation
*/
void affecter_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO);

/** Compare deux descripteurs audio
* Utilité: Indexation
*  Methode: Comparaison basé sur l'identifiant et sur l'histogramme
* @param DESC_AUDIO premier descripteur audio à comparer
* @param DESC_AUDIO second descripteur audio à comparer
* @return int la comparaison des deux descripteurs
*/
int compare_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO);

/**
*	Evalue la comparaison des deux descripteur audio passés en paramètres.
*   Attention ! Cette comparaison n'est pas la même qu'avec compare_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO).
*	Celle-ci retourne un taux de ressemblance.
* 	Utilité: Recherche
*
*	@param DESC_AUDIO premier descripteur à évaluer
*	@param DESC_AUDIO second descripteur à évaluer
*	@param unsigned nombre de résultat souhaité.
*	@return RES_EVAL_AUDIO le résultat de l'évalutation audio
*/
RES_EVAL_AUDIO evaluer_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO, unsigned int);


/** Libère la mémoire occupée par l'histogramme du descripteur donné en paramètre
* Utilité: Générale
* @param DESC_AUDIO descripteur audio
*/
void free_DESC_AUDIO(DESC_AUDIO *);

/** Initialise un résultat d'une évalutation audio
 * @return RES_EVAL_AUDIO le résultat de l'évaluation audio encore vide.
 */
RES_EVAL_AUDIO init_RES_EVAL_AUDIO();

#endif