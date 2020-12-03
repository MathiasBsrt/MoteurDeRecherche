#include <stdio.h>
#include <stdlib.h>
#include "histogramme.h"
#include "descripteur.h"

DESC_AUDIO init_DESC_AUDIO(int k, int m)
{
	DESC_AUDIO desc;
	desc.histo = init_HISTOGRAMME_AUDIO(k, m);
	return desc;
}

double get_DESC_AUDIO(DESC_AUDIO desc, int k, int m)
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