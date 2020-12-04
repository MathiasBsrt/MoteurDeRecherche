#include <assert.h>
#include <stdio.h>
#include "histogramme.h"
#include "files_handler.h"

int main(int argc, char * argv[])
{
	if(argc != 4)
	{
		fprintf(stderr, "Pour que le programme puisse fonctionner, des arguments sont attendus.\n");
		fprintf(stderr, "Usage: %s <fichier.txt> <k> <m>\n", argv[0]);
		return 1;
	}

	int k, m;

	sscanf(argv[2],"%d",&k);
	sscanf(argv[3],"%d",&m);

	HISTOGRAMME_AUDIO histo = creer_histogramme_TXT_DESC_AUDIO(argv[1], k, m);
	affiche_HISTOGRAMME_AUDIO(histo);
}