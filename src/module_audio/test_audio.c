#include <assert.h>
#include <stdio.h>
#include "descripteur.h"

int main()
{
	printf("--- DEBUT DES TESTS AUDIO --- \n");
	printf("  --- DESCRIPTEUR --- \n");
	printf("    --- Initialisation du descripteur --- \n");
	// Initialisation du descripteur
	int k = 10;
	int m = 15;
	DESC_AUDIO desc = init_DESC_AUDIO(k, m);
	assert(desc.histo.k == k);
	assert(desc.histo.m == m);
	printf("      Descripteur: id=%d, k=%d, m=%d\n", desc.id, desc.histo.k, desc.histo.m);

	int y, x;

	printf("    --- SET DESC AUDIO --- \n");
	for(y = 0; y < k; y++)
		for(x = 0; x < m; x++)
			set_DESC_AUDIO(&desc, y, x, (double) (y * desc.histo.m + x));

	printf("    --- GET DESC AUDIO --- \n");
	for(y = 0; y < k; y++)
		for(x = 0; x < m; x++)
			assert(get_DESC_AUDIO(desc, y, x) == (double) (y * desc.histo.m + x));



	printf("--- FIN DES TEST AUDIO --- \n");
}