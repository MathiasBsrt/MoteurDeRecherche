#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

int generer_HISTOGRAMME_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int k, int m)
{
	char * ext = strrchr(chemin, '.');
	if(!ext)
	{
		fprintf(stderr, "[CREER_HISTO] Impossible de créer l'histogramme car le fichier donné n'a pas un format supporté (%s).\n", chemin);
		return HISTOGRAMME_CREER_ERREUR;
	} else if(strcmp((ext + 1), ".txt") != 0){
	    return creer_histogramme_TXT_DESC_AUDIO(histo, chemin, k, m);
	}
	else
	{
		fprintf(stderr, "[CREER_HISTO] Impossible de créer l'histogramme car le fichier donné n'a pas un format supporté (%s).\n", chemin);
		return HISTOGRAMME_CREER_ERREUR;
	}

}

int creer_histogramme_TXT_DESC_AUDIO(HISTOGRAMME_AUDIO * histo, char * chemin, int k, int m)
{
	// Vérification de l'extension du fichier donné.
	char * ext = strrchr(chemin, '.');
	if (!ext) 
	{
	    fprintf(stderr, "[CREER_HISTO_TXT] Impossible de créer l'histogramme car le fichier donné n'est pas au bon format TXT (%s).\n", chemin);
		return HISTOGRAMME_CREER_ERREUR;
	} else if(strcmp((ext + 1), "txt") != 0){
	    fprintf(stderr, "[CREER_HISTO_TXT] Impossible de créer l'histogramme car le fichier donné n'est pas au bon format TXT (%s).\n", chemin);
		return HISTOGRAMME_CREER_ERREUR;
	}

	*histo = init_HISTOGRAMME_AUDIO(k, m);
	FILE * audioTXT; // Fichier audio .txt
	audioTXT = fopen(chemin, "r");
	// Si le programme n'arrive pas à lire le fichier demandé.
	if(audioTXT == NULL)
	{
		fprintf(stderr, "[FILES_HANDLER_TXT] Impossible de lire le fichier %s.", chemin);
		exit(1);
	}

	int lines = 0;
	char ch;

	// Compter le nombre de ligne
	while(!feof(audioTXT))
	{
		ch = fgetc(audioTXT);
		if(ch == '\n')
		{
			lines++;
		}
	}
	audioTXT = fopen(chemin, "r");

	// Lecture des valeurs
	double y_ratio = lines / (double) k;
	double x_ratio = 2.0 / m;

	/* DEBUG Things
	printf("Nb lines: %d\n", lines);
	printf("lines / k: %f\n", y_ratio);
	printf("2 / m: %f\n", x_ratio);
	*/

	int y, x;
	int line;
	double val;
	/* double min = 50; DEBUG VALUES
	double max = -50; */
	for(line = 0; line < lines; line++)
	{
		// Ici, l'espace avant le %lf est important
		// car dans le fichier .txt se trouve un espace avant le nombre réel.
		fscanf(audioTXT, " %lf", &val);
		/*if(val > max) max = val;
		if(val < min) min = val;*/
		y = floor(line / y_ratio);
		x = floor((val + 1) / x_ratio);
		//printf("y:%d, x:%d, val: %lf, line: %d\n", y, x, val, line);
		inc_HISTOGRAMME_AUDIO(histo, y, x);
	}
	/* printf("min: %lf, max: %lf\n", min, max); */
	return HISTOGRAMME_CREER_SUCCES;
}