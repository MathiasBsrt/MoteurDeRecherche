#include <assert.h>
#include <stdio.h>
#include "descripteur.h"
#include "histogramme.h"

int main(int argc, char * argv[])
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
			set_DESC_AUDIO(&desc, y, x, (y * desc.histo.m + x));

	printf("    --- GET DESC AUDIO --- \n");
	for(y = 0; y < k; y++)
		for(x = 0; x < m; x++)
			assert(get_DESC_AUDIO(desc, y, x) == (y * desc.histo.m + x));

	
	printf("    --- CREER HISTOGRAMME TXT DESC AUDIO --- \n");

	HISTOGRAMME_AUDIO histoTXT;
	int codeTXT = generer_HISTOGRAMME_AUDIO(&histoTXT, "./TEST_SON/corpus_fi.txt", k, m);
	if(codeTXT != HISTOGRAMME_CREER_SUCCES) exit(codeTXT);
	affiche_HISTOGRAMME_AUDIO(histoTXT);
	

	printf("    --- CREER HISTOGRAMME BIN DESC AUDIO --- \n");

	HISTOGRAMME_AUDIO histoBIN;
	int codeBIN = generer_HISTOGRAMME_AUDIO(&histoBIN, "./TEST_SON/corpus_fi.bin", k, m);
	if(codeBIN != HISTOGRAMME_CREER_SUCCES) exit(codeBIN);
	affiche_HISTOGRAMME_AUDIO(histoBIN);

	printf("    --- CREER HISTOGRAMME WAV DESC AUDIO --- \n");

	HISTOGRAMME_AUDIO histoWAV;
	int codeWAV = generer_HISTOGRAMME_AUDIO(&histoWAV, "./TEST_SON/corpus_fi.wav", k, m);
	if(codeWAV != HISTOGRAMME_CREER_SUCCES) exit(codeWAV);
	affiche_HISTOGRAMME_AUDIO(histoWAV);

	printf("    --- VERIFICATION D'EGALITE --- \n");
	printf("      --- HISTO TXT == HISTO BIN --- \n");
	printf("        %s\n", (compare_HISTOGRAMME_AUDIO(histoTXT, histoBIN) == 0 ? "Vrai" : "Faux"));
	printf("      --- HISTO TXT == HISTO WAV --- \n");
	printf("        %s\n", (compare_HISTOGRAMME_AUDIO(histoTXT, histoWAV) == 0 ? "Vrai" : "Faux"));
	printf("      --- HISTO BIN == HISTO WAV --- \n");
	printf("        %s\n", (compare_HISTOGRAMME_AUDIO(histoBIN, histoWAV) == 0 ? "Vrai" : "Faux"));


	printf("--- FIN DES TEST AUDIO --- \n");
}