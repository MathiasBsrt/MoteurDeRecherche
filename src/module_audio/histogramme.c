#include <stdio.h>
#include <stdlib.h>
#include "histogramme.h"

HISTOGRAMME_AUDIO init_HISTOGRAMME_AUDIO(int k, int m)
{
	HISTOGRAMME_AUDIO histo;
	histo.k = k; // Nombre de fenêtre d'analyse
	histo.m = m; // Nombre d'intervalles
	histo.mat = (int *) malloc(sizeof(int) * k * m);
	return histo;
}

void affiche_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO histo)
{
	int y, x;
	printf("y \\ x\n");
	for(y = 0; y < histo.k; y++)
	{
		/* Retirer car à re-programmer 
		   (affichage supérieur des indices de la matrice)
		if(y == -1) 
		{ 
			for(x = 0; x < histo.m; x++) printf("%d\t", x);
			printf("\n");
			for(x = 0; x < histo.m; x++) printf("-\t", x);
			printf("\n");
		}
		else*/
		for(x = -1; x < histo.m; x++)
		{
			if(x == -1) printf("%d | \t", y);
			else printf("%d\t", get_HISTOGRAMME_AUDIO(histo, y, x));
		}
		printf("\n");
	}
}

int get_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO histo, int k, int m)
{
	if(k < 0 || k >= histo.k || m < 0 || m >= histo.m)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de récuperer la valeur à l'index (%d,%d) OUT_OF_BOUND.\n", k, m);
		exit(1);
	}
	if(histo.mat == NULL)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de récuperer la valeur à l'index (%d,%d) HISTOGRAM_NOT_INIT.\n", k, m);
		exit(1);
	}
	return *(histo.mat + (k * histo.m + m));
}

void set_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO * histo, int k, int m, int val)
{
	if(k < 0 || k >= histo->k || m < 0 || m >= histo->m)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de mettre la valeur à l'index (%d,%d) OUT_OF_BOUND.\n", k, m);
		exit(1);
	}
	if(histo->mat == NULL)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible de mettre la valeur à l'index (%d,%d) DESC_NOT_INIT.\n", k, m);
		exit(1);
	}
	*(histo->mat + k * histo->m + m) = val;
}

void inc_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO * histo, int k, int m)
{
	if(k < 0 || k >= histo->k || m < 0 || m >= histo->m)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible d'incrementer la valeur à l'index (%d,%d) OUT_OF_BOUND.\n", k, m);
		exit(1);
	}
	if(histo->mat == NULL)
	{
		fprintf(stderr, "[HISTOGRAMME_AUDIO] Impossible d'incrementer la valeur à l'index (%d,%d) DESC_NOT_INIT.\n", k, m);
		exit(1);
	}
	set_HISTOGRAMME_AUDIO(histo, k, m, get_HISTOGRAMME_AUDIO(*histo, k, m) + 1);
}