#include <assert.h>
#include <stdio.h>
#include "descripteur.h"
#include "histogramme.h"

int main(int argc, char * argv[])
{
	if(argc != 4)
	{
		fprintf(stderr, "Pour que les tests puissent fonctionner, des arguments sont attendus.\n");
		fprintf(stderr, "Usage: %s <fichier.txt> <k> <m>\n", argv[0]);
		return 1;
	}
	printf("--- DEBUT DES TESTS AUDIO --- \n");
	printf("  --- DESCRIPTEUR --- \n");
	printf("    --- Initialisation du descripteur --- \n");
	// Initialisation du descripteur
	int k, m;

	sscanf(argv[2],"%d",&k);
	sscanf(argv[3],"%d",&m);

	DESC_AUDIO desc = init_DESC_AUDIO(k, m);
	assert(desc.histo.k == k);
	assert(desc.histo.m == m);
	printf("      Descripteur: id=%d, k=%d, m=%d\n", desc.id, desc.histo.k, desc.histo.m);

	int y, x;

	printf("    --- SET DESC AUDIO --- \n");
	for(y = 0; y < k; y++)
		for(x = 0; x < m; x++)
			set_DESC_AUDIO(&desc, y, x, (y * desc.histo.m + x));

	printf("    --- GET DESC AUDIO --- \n");
	for(y = 0; y < k; y++)
		for(x = 0; x < m; x++)
			assert(get_DESC_AUDIO(desc, y, x) == (y * desc.histo.m + x));

	printf("    --- CREER HISTOGRAMME TXT DESC AUDIO --- \n");

	HISTOGRAMME_AUDIO histo;
	int code = generer_HISTOGRAMME_AUDIO(&histo, argv[1], k, m);
	if(code != HISTOGRAMME_CREER_SUCCES) exit(code);
	affiche_HISTOGRAMME_AUDIO(histo);

	printf("--- FIN DES TEST AUDIO --- \n");
}