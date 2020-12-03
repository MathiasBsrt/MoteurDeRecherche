#include <stdio.h>
#include <stdlib.h>
#include "histogramme.h"

HISTOGRAMME_AUDIO init_HISTOGRAMME_AUDIO(int k, int m)
{
	HISTOGRAMME_AUDIO histo;
	histo.k = k; // Nombre de fenêtre d'analyse
	histo.m = m; // Nombre d'intervalles
	histo.mat = (double *) malloc(sizeof(double) * k * m);
	return histo;
}

double get_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO histo, int k, int m)
{
	if(k < 0 || k >= histo.k || m < 0 || m >= histo.m)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de récuperer la valeur réel à l'index (%d,%d) OUT_OF_BOUND.", k, m);
		exit(1);
	}
	if(histo.mat == NULL)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de récuperer la valeur réel à l'index (%d,%d) HISTOGRAM_NOT_INIT.", k, m);
		exit(1);
	}
	return *(histo.mat + (k * histo.m + m));
}

void set_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO * histo, int k, int m, double val)
{
	if(k < 0 || k >= histo->k || m < 0 || m >= histo->m)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de récuperer la valeur réel à l'index (%d,%d) OUT_OF_BOUND.", k, m);
		exit(1);
	}
	if(histo->mat == NULL)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de récuperer la valeur réel à l'index (%d,%d) DESC_NOT_INIT.", k, m);
		exit(1);
	}
	*(histo->mat + k * histo->m + m) = val;
}