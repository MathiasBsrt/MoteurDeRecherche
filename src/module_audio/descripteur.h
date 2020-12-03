#ifndef DESCRIPTEUR_AUDIO_H_INCLUS 

#define DESCRIPTEUR_AUDIO_H_INCLUS

#include <stdlib.h>
#include "histogramme.h"

/*	Definition de la structure d'un descripteur audio 
Alias: DESC_AUDIO
*/
typedef struct Descripteur_Audio_t
{
	int id; /* Identifiant du descripteur */
	HISTOGRAMME_AUDIO histo;
} DESC_AUDIO;

/* Initilalise un descripteur audio
Params:
	- int k, nombre de fenêtre d'analyse
	- int m, nombre d'intervalles

Returns:
	- DESC_AUDIO, le descripteur audio initialisé
*/
DESC_AUDIO init_DESC_AUDIO(int, int);

/* Retourne le réels à l'index k,m
Params:
	- DESC_AUDIO desc, descripteur audio
	- int k, index odronnée
	- int m, index abscisse

Returns:
	- double, la valeur réel à l'index k,m
*/
double get_DESC_AUDIO(DESC_AUDIO, int, int);

/* Affecte un réels à l'index k,m
Params:
	- DESC_AUDIO * desc, pointeur de descripteur audio
	- int k, index odronnée
	- int m, index abscisse
	- double val, valeur réel à affecter
*/
void set_DESC_AUDIO(DESC_AUDIO *, int, int, double);

/* Affiche un descripteur audio sur la sortie standard (printf)
Params:
	- DESC_AUDIO desc, le descripteur audio que l'on souhaite afficher
*/
void affiche_DESC_AUDIO(DESC_AUDIO);

/* Affecte les valeurs d'un descripteur audio à un autre
	On affecte les valeurs du desc2 dans le desc1
Params:
	- DESC_AUDIO desc1, descripteur destinataire de l'affectation
	- DESC_AUDIO desc2, descripteur source de l'affectation
*/
void affecter_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO);

/* Compare deux descripteurs audio
Params:
	- DESC_AUDIO desc1, premier descripteur audio à comparer
	- DESC_AUDIO desc2, second descripteur audio à comparer
Returns:
	- int, la comparaison des deux descripteurs
	Methode: Comparaison basé sur l'identifiant
*/
int compare_DESC_AUDIO(DESC_AUDIO, DESC_AUDIO);



#endif