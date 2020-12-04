#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> /* used for strrchr */
#include "files_handler.h"
#include "histogramme.h"


HISTOGRAMME_AUDIO creer_histogramme_TXT_DESC_AUDIO(char * chemin, int k, int m)
{
	// Vérification de l'extension du fichier donné.
	char * ext = strrchr(chemin, '.');
	if (!ext) 
	{
	    fprintf(stderr, "[FILES_HANDLER_TXT] Impossible de créer l'histogramme car le fichier donné n'est pas au bon format TXT (%s).\n", chemin);
		exit(1);
	} else if(strcmp((ext + 1), "txt") != 0){
	    fprintf(stderr, "[FILES_HANDLER_TXT] Impossible de créer l'histogramme car le fichier donné n'est pas au bon format TXT (%s).\n", chemin);
		exit(1);
	}

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
	HISTOGRAMME_AUDIO histo = init_HISTOGRAMME_AUDIO(k, m);

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
		inc_HISTOGRAMME_AUDIO(&histo, y, x);
	}
	/* printf("min: %lf, max: %lf\n", min, max); */
	return histo;
}