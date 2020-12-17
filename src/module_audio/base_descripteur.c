#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pile_dynamique.h"
#include "base_descripteur.h"
#include "descripteur.h"
#include "histogramme.h"

void init_FICHIER_BASE_DESC(PILE PILE_DESCRIPTEUR_AUDIO)
{
	PILE_DESCRIPTEUR_AUDIO = init_PILE();
	// On créé le fichier BASE_DESC_FICHIER si il n'existe pas
	FILE *fp = fopen(BASE_DESC_FICHIER, "ab+");
	fclose(fp);
}

PILE sauvegarder_DESC_AUDIO(PILE PILE_DESCRIPTEUR_AUDIO, DESC_AUDIO desc)
{
	PILE_DESCRIPTEUR_AUDIO = emPILE(PILE_DESCRIPTEUR_AUDIO, desc);
	// TODO sauvegarder PILE
	return PILE_DESCRIPTEUR_AUDIO;
}


void sauvegarder_PILE_DESC_AUDIO(PILE PILE_DESCRIPTEUR_AUDIO)
{
	if(PILE_DESCRIPTEUR_AUDIO == NULL)
	{
		fprintf(stderr, "[SAUVEGARDER_PILE_DESC_AUDIO] Vous devez d'abord initialiser la PILE avant de pouvoir la sauvegarder.");
		exit(1);
	}
	FILE * baseDescFichier = fopen(BASE_DESC_FICHIER, "w");
	if(baseDescFichier == NULL)
	{
		fprintf(stderr, "[SAUVEGARDER_PILE_DESC_AUDIO] Impossible de charger le fichier %s en écriture.", BASE_DESC_FICHIER);
		exit(1);
	}
	DESC_AUDIO desc;
	while(!PILE_estVide(PILE_DESCRIPTEUR_AUDIO))
	{
		PILE_DESCRIPTEUR_AUDIO = dePILE(PILE_DESCRIPTEUR_AUDIO, &desc);
		fprintf(baseDescFichier, "%d %d %d ", desc.id, desc.histo.k, desc.histo.m);
		int y, x;
		for(y = 0; y < desc.histo.k; y++)
			for(x = 0; x < desc.histo.m; x++)
			{
				fprintf(baseDescFichier, "%d ", get_HISTOGRAMME_AUDIO(desc.histo, y, x));
			}

		fprintf(baseDescFichier, "%c", '\n');
	}
		fprintf(baseDescFichier, "%d", EOF);
	fclose(baseDescFichier);
}


PILE charger_PILE_DESC_AUDIO()
{
	PILE PILE_DESCRIPTEUR_AUDIO = init_PILE();
	FILE * baseDescFichier = fopen(BASE_DESC_FICHIER, "r");
	if(baseDescFichier == NULL)
	{
		fprintf(stderr, "[SAUVEGARDER_PILE_DESC_AUDIO] Impossible de charger le fichier %s en lecture.", BASE_DESC_FICHIER);
		exit(1);
	}
	DESC_AUDIO * desc;
	int val;
	int k, m;
	int y, x;
	fscanf(baseDescFichier, "%d ", &val);
	do
	{
		fscanf(baseDescFichier, "%d %d", &k, &m);
		desc = (DESC_AUDIO *) malloc(sizeof(DESC_AUDIO));
		desc->id = val;
		desc->histo = init_HISTOGRAMME_AUDIO((int) log2(k), m);
		for(y = 0; y < desc->histo.k; y++)
			for(x = 0; x < desc->histo.m; x++)
			{
				fscanf(baseDescFichier, "%d ", &val);
				set_DESC_AUDIO(desc, y, x, val);
			}
		PILE_DESCRIPTEUR_AUDIO = emPILE(PILE_DESCRIPTEUR_AUDIO, *desc);

		fscanf(baseDescFichier, "%d ", &val);
	} while(val != EOF);

	fclose(baseDescFichier);
	return PILE_DESCRIPTEUR_AUDIO;
}