#ifndef BASE_DESC_AUDIO_H_INCLUS 

#define BASE_DESC_AUDIO_H_INCLUS

#include "descripteur.h"
#include "histogramme.h"
#include "pile_dynamique.h"

#define BASE_DESC_FICHIER "base_descripteur_audio"

void init_FICHIER_BASE_DESC(PILE);

PILE sauvegarder_DESC_AUDIO(PILE, DESC_AUDIO);

void sauvegarder_PILE_DESC_AUDIO(PILE);

PILE charger_PILE_DESC_AUDIO();



#endif