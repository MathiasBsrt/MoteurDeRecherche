#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "histogramme.h"
#include "descripteur.h"
#include "base_descripteur.h"
#include "wav_file_helper.h"


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

void avoir_min(int n, int in, double * input_values, int * index, double * values)
{
	double min = 999999999999999999;
	int mini = 0;
	int alreadyPicked = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < in; j++)
		{
			for(int k = 0; k < i; k++)
			{
				if(j == index[k]) { alreadyPicked = 1; break;}
			}
			if(alreadyPicked) { alreadyPicked = 0; continue; } 
			if(input_values[j] < min)
			{
				min = input_values[j];
				mini = j;
			}
		}
		index[i] = mini;
		values[i] = min;
		min = 999999999999999999;
		mini = 0;
	}
}

RES_EVAL_AUDIO evaluer_DESC_AUDIO(DESC_AUDIO desc1, DESC_AUDIO desc2, unsigned int nb)
{
	// On commence à créer un résultat vide.
	RES_EVAL_AUDIO resultat;
	resultat.n = 0;
	// On récupère le nom du fichier lié au descripteur 1.
	char * filename1 = fichier_lier_DESC_AUDIO(desc1);
	// Si le descripteur n'est pas lié à un fichier,
	// on annule tout car plus tard nous aurons besoin
	// du nom de ce fichier pour pouvoir récupérer
	// la durée total de celui-ci.
	if(filename1 == NULL) return resultat;
	// On récupère le nom du fichier lié au descripteur 2.
	char * filename2 = fichier_lier_DESC_AUDIO(desc2);
	// Même vérification avec le descripteur 2.
	if(filename2 == NULL) return resultat;

	// On récupère finalement les durées des fichiers WAV.
	int duration1 = wav_get_duration(filename1);
	int duration2 = wav_get_duration(filename2);

	// On vérifie bien que l'utilisateur de la méthode veut vérifier que le
	// descripteur 2 est contenue dans le descripteur 1.
	// Sinon (voir plus bas) on inverse les paramètres avec un appel récursif.
	if(duration1 >= duration2)
	{
		// On calcul le rapport entre les deux durées.
		double rapport = (double) duration1 / duration2;
		int new_duration1 = (int) (duration1 * rapport);
		//printf("Rapport = %f\n", rapport);

		// On calcul alors le nouveau 'n' pour le descripteur 1.
		int n = (int) (log2((double) desc1.histo.k) + log2(rapport));
		//printf("%f + %f = %d\n", log2((double) desc1.histo.k), log2(rapport), n);

		// On regénère le descripteur 1.
		HISTOGRAMME_AUDIO histo1 = init_HISTOGRAMME_AUDIO(n, desc1.histo.m);
		int code = generer_HISTOGRAMME_AUDIO(&histo1, filename1, n, histo1.m);
		// Si une erreure c'est produite lors de la génération du nouvel histogramme
		// on annule tout en retournant le resultat vide.
		if(code == HISTOGRAMME_CREER_ERREUR) return resultat;

		/*printf("Nouvelle génération de %s (k=%d, m=%d) avec maintenant (k=%d, m=%d)\n",
			filename1, desc1.histo.k, desc1.histo.m, histo1.k, histo1.m);*/

		//printf("histo1 (k=%d, m=%d)\n", histo1.k, histo1.m);
		//printf("desc2 (k=%d, m=%d)\n", desc2.histo.k, desc2.histo.m);
		
		// On déclare un ensemble de variable pour nous simplifier la suite.
		int index1 = 0, curseurIndex1 = 0;
		int curseurIndex2 = 0;
		// On créer notre buffer "min" pour stocker la valeur minimale.
		// On l'initialise avec la plus grande valeurs possible pour un double.
		// Cette notation permet de spécifier: 0x1.(mantisse)p(exposant réel)
		double min = 0x1.fffffffffffffp-1;
		int mini = 0;
		int mini2 = 0;
		int index1_max = (histo1.k * histo1.m) - 1;
		int index2_max = (desc2.histo.k * desc2.histo.m) - 1;
		int found_something = 0;
		int val1, val2;
		int padding = histo1.m;
		int size = (histo1.k * histo1.m) / padding;
		double scores[size];
		double currentScore;
		int test = 0;

		// L'objectif ici va être de "déplacer" l'histogramme 2 sur l'histogramme 1
		// et de calculer la distance entre les deux histogramme à chaque fois.
		// Cela nous génèrera un score qui sera stocké dans scores.
		while (index1 <= index1_max)
		{
			currentScore = 0.0;
			test = 0;
			while(curseurIndex2 <= index2_max)
			{
				val1 = histo1.mat[curseurIndex1];
				val2 = desc2.histo.mat[curseurIndex2];
				// On peut ici appliquer plusieurs formule:
				// Formule 1 (distance de Manhattan): val1 - val2
				// Formule 2 (distance euclidienne): sqrt(pow(val1 - val2, 2))
				currentScore += abs(val1 - val2);
				curseurIndex2++;
				curseurIndex1++;
				test++;
			}
			//printf("test %d: %f %d time = %f\n", index1 / padding, currentScore, test, ((double) index1 / index1_max) * duration1);
			scores[index1 / padding] = currentScore / (desc2.histo.k * desc2.histo.m);
			index1 += padding;
			curseurIndex1 = index1;
			curseurIndex2 = 0;
		}

		//printf("index1 = %d , min = %f , mini = %d, mini2 = %d, time = %f\n", index1, min, mini, mini2, ((double) mini / index1_max) * duration1);
		//printf("new_duration1 = %d , duration1 = %d\n", new_duration1, duration1);

		// On configure alors le réusltat
		resultat.n = nb;
		resultat.times = (double *) malloc(sizeof(double) * nb);
		double * values = (double *) malloc(sizeof(double) * nb);
		int * indicies = (int *) malloc(sizeof(double) * nb);
		// On récupère les nb meilleurs score
		avoir_min(nb, size, scores, indicies, values);
		for(int i = 0; i < nb; i++)
		{
			//printf("n = %d: ", i);
			//printf("min = %f , mini = %d, time = %f\n", values[i], indicies[i] * padding, ((double) (indicies[i] * padding) / index1_max) * duration1);
			
			// On calcul le temps vers lequel le programme à trouver
			// l'histogramme 2 dans l'histogramme 1.
			resultat.times[i] = ((double) (indicies[i] * padding) / index1_max) * duration1;
		}
		
	} else return evaluer_DESC_AUDIO(desc2, desc1, nb); // On inverse simplement les arguments
	// On retourne l'histogramme
	return resultat;
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