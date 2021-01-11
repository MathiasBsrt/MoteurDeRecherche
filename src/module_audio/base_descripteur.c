#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
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

	// On créé le fichier LISTE_BASE_FICHIER si il n'existe pas
	fp = fopen(LISTE_BASE_FICHIER, "ab+");
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
		//fprintf(baseDescFichier, "%d %d %d ", desc.id, desc.histo.k, desc.histo.m);
		fwrite(&(desc.id), 4, 1, baseDescFichier);
		fwrite(&(desc.histo.k), 4, 1, baseDescFichier);
		fwrite(&(desc.histo.m), 4, 1, baseDescFichier);
		fwrite(desc.histo.mat, 4, desc.histo.k * desc.histo.m, baseDescFichier);
		/*
		int y, x;
		for(y = 0; y < desc.histo.k; y++)
			for(x = 0; x < desc.histo.m; x++)
			{
				fprintf(baseDescFichier, "%d ", get_HISTOGRAMME_AUDIO(desc.histo, y, x));
			}
		fprintf(baseDescFichier, "%c", '\n');
		*/
	}
	//fprintf(baseDescFichier, "%d", EOF);
	int pEOF = EOF;
	fwrite(&pEOF, 4, 1, baseDescFichier);
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
	//fscanf(baseDescFichier, "%d ", &val);
	fread(&val, 4, 1, baseDescFichier);
	do
	{
		fread(&k, 4, 1, baseDescFichier);
		fread(&m, 4, 1, baseDescFichier);
		//fscanf(baseDescFichier, "%d %d", &k, &m);
		desc = (DESC_AUDIO *) malloc(sizeof(DESC_AUDIO));
		desc->id = val;
		desc->histo = init_HISTOGRAMME_AUDIO((int) log2(k), m);
		fread(desc->histo.mat, 4, desc->histo.k * desc->histo.m, baseDescFichier);
		/*for(y = 0; y < desc->histo.k; y++)
			for(x = 0; x < desc->histo.m; x++)
			{
				fscanf(baseDescFichier, "%d ", &val);
				set_DESC_AUDIO(desc, y, x, val);
			}
		*/
		PILE_DESCRIPTEUR_AUDIO = emPILE(PILE_DESCRIPTEUR_AUDIO, *desc);

		//fscanf(baseDescFichier, "%d ", &val);
		fread(&val, 4, 1, baseDescFichier);
	} while(val != EOF);

	fclose(baseDescFichier);
	return PILE_DESCRIPTEUR_AUDIO;
}

PILE init_MULTIPLE_DESC_AUDIO(int start_id, int n, int m, char * cheminDir)
{
	struct dirent *dir;
    DIR *d = opendir(cheminDir);
    PILE pile = init_PILE();
    DESC_AUDIO * desc;
    int id = start_id;

    while ((dir = readdir(d)) != NULL)
    {

        if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
            ; //on evite de lire les "." et ".."
        else
        {
            struct stat InfosFile;
            char chemin[128];
            strcpy(chemin, cheminDir);
		    strcat(chemin, "/");
		    strcat(chemin, dir->d_name);
            stat(chemin, &InfosFile);            //on recupere les stat du fichier lu pour savoir si c' est un dossier
            if (S_ISREG(InfosFile.st_mode) != 0) //on vérifie si c'est un fichier
            {
            	printf("%s\n", chemin);
            	desc = (DESC_AUDIO *) malloc(sizeof(DESC_AUDIO));
            	*desc = init_DESC_AUDIO(id, n, m, chemin);
            	pile = emPILE(pile, *desc);
            	id++;
            }
        }
    }
    closedir(d);
    return pile;
}


int lier_DESC_AUDIO_FICHIER(DESC_AUDIO desc, char * chemin)
{
	FILE * listeBaseFichier = fopen(LISTE_BASE_FICHIER, "rw");
	char tmpFichier[100];
	strcpy(tmpFichier, LISTE_BASE_FICHIER);
	strcat(tmpFichier, "_tmp");
	FILE * tmp = fopen(tmpFichier, "ab+");
	int returnCode = 0;
	int id;
	char fichier[100];
	fscanf(listeBaseFichier, "%d %s", &id, fichier);
	while(id != EOF)
	{
		if(id == desc.id) // Le descripteur est déjà lié.
		{
			fprintf(tmp, "%d %s\n", desc.id, chemin);
			returnCode = 1;
		} else
		{
			fprintf(tmp, "%d %s\n", id, fichier);
		}
		fscanf(listeBaseFichier, "%d %s", &id, fichier);	
	}
	if(returnCode == 0) fprintf(tmp, "%d %s\n", desc.id, chemin);
	fprintf(tmp, "%d", EOF);

	fclose(listeBaseFichier);
	fclose(tmp);

	char command[100];
	strcpy(command, "mv ");
	strcat(command, tmpFichier);
	strcat(command, " ");
	strcat(command, LISTE_BASE_FICHIER);
	system(command);

	return returnCode;
}


char * fichier_lier_DESC_AUDIO(DESC_AUDIO desc)
{
	char * filename = (char *) malloc(sizeof(char) * 100);
	FILE * listeBaseFichier = fopen(LISTE_BASE_FICHIER, "rw");
	if(listeBaseFichier == NULL) return NULL;

	int id;
	char * chemin;
	do
	{
		fscanf(listeBaseFichier, "%d", &id);
		if(id == EOF) break;
		fscanf(listeBaseFichier, "%s", filename);
	} while(id != desc.id);
	if(id == EOF) return NULL;
	return filename;
}