#include <stdio.h>
#include <stdlib.h>
#include "histogramme.h"
#include "descripteur.h"


DESC_AUDIO init_DESC_AUDIO(int id, int n, int m, char * chemin)
{
	DESC_AUDIO desc;
	desc.id = id;
	desc.histo = init_HISTOGRAMME_AUDIO(n, m);
	int code = generer_HISTOGRAMME_AUDIO(&(desc.histo), chemin, n, m);
	return desc;
}

DESC_AUDIO init_vide_DESC_AUDIO(int n, int m)
{
	DESC_AUDIO desc;
	desc.histo = init_HISTOGRAMME_AUDIO(n, m);
	return desc;
}

int get_DESC_AUDIO(DESC_AUDIO desc, int k, int m)
{
	return get_HISTOGRAMME_AUDIO(desc.histo, k, m);
}

void set_DESC_AUDIO(DESC_AUDIO * desc, int k, int m, int val)
{
	if(desc == NULL)
	{
		fprintf(stderr, "[DESC_AUDIO] Impossible de récuperer la valeur à l'index (%d,%d) DESC_NOT_INIT.\n", k, m);
		exit(1);
	}
	set_HISTOGRAMME_AUDIO(&(desc->histo), k, m, val);
}

int compare_DESC_AUDIO(DESC_AUDIO desc1, DESC_AUDIO desc2)
{
	if(desc1.id != desc2.id) return 1;
	return compare_HISTOGRAMME_AUDIO(desc1.histo, desc2.histo);
}

void affiche_DESC_AUDIO(DESC_AUDIO desc)
{
	printf("Identifiant: %d\nHistogramme:\n", desc.id);
	affiche_HISTOGRAMME_AUDIO(desc.histo);
}

void free_DESC_AUDIO(DESC_AUDIO * desc)
{
	free_HISTOGRAMME_AUDIO(&(desc->histo));
}