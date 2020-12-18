#ifndef DESCRIPTEUR_AUDIO_H_INCLUS 

#define DESCRIPTEUR_AUDIO_H_INCLUS

#include <stdlib.h>
#include "histogramme.h"

/**	Definition de la structure d'un descripteur audio */
typedef struct Descripteur_Audio_t
{
	int id; /**< Identifiant du descripteur */
	HISTOGRAMME_AUDIO histo; /**< Histogramme du descripteur audio */
} DESC_AUDIO;

/* Initilalise un descripteur audio
* @param id id du descripteur
* @param n n^2 nombre de fenêtre d'analyse
* @param m nombre d'intervalles
* @param char * chemin chemin vers le fichier à traiter
*
* @return DESC_AUDIO desc le descripteur audio initialisé
*/
DESC_AUDIO init_DESC_AUDIO(int, int, int, char *);

/** Initilalise un descripteur audio vide
* @param int id id de l'histogramme
* @param int n 2^n nombre de fenêtre d'analyse
* @param int m nombre d'intervalles
* @param char * chemin chemin vers le fichier à traiter
*
* @return DESC_AUDIO desc, le descripteur audio initialisé
*/
DESC_AUDIO init_vide_DESC_AUDIO(int, int);

/** Retourne le réels à l'index k,m
* @param DESC_AUDIO desc descripteur audio
* @param int k index ordonné
* @param int m index abscisse
*
* @return double val la valeur réel à l'index k,m
*/
int get_DESC_AUDIO(DESC_AUDIO, int, int);

/** Affecte un réels à l'index k,m
* @param DESC_AUDIO * desc pointeur de descripteur audio
* @param int k index ordonné
* @param int m index abscisse
* @param double val valeur réel à affecter
*/
void set_DESC_AUDIO(DESC_AUDIO *, int, int, int);

/** Affiche un descripteur audio sur la sortie standard (printf)
* @param DESC_AUDIO desc le descripteur audio que l'on souhaite afficher
*/
void affiche_DESC_AUDIO(DESC_AUDIO);

/** Affecte les valeurs d'un descripteur audio à un autre
*  On affecte les valeurs du desc2 dans le desc1
* @param DESC_AUDIO desc1 descripteur destinataire de l'affectation
* @param DESC_AUDIO desc2 descripteur source de l'affectation
*/
void affecter_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO);

/** Compare deux descripteurs audio
*  Methode: Comparaison basé sur l'identifiant et sur l'histogramme
* @param DESC_AUDIO desc1 premier descripteur audio à comparer
* @param DESC_AUDIO desc2 second descripteur audio à comparer
* @return int val la comparaison des deux descripteurs
*/
int compare_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO);

#endif