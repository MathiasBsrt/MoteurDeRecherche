#include <stdio.h>
#include <math.h>
#include "descripteur.h"
#include "histogramme.h"
#include "base_descripteur.h"

int main(int argc, char * argv[])
{
    printf("--- DEBUT DES TESTS AUDIO --- \n");
    printf("  --- DESCRIPTEUR --- \n");
    int n = 2;
    int k = pow(2, n);
    int m = 15;
    printf("    --- Paramètres généraux proposés: --- \n");
    printf("      n = %d \n", n);
    printf("      k = 2^%d = %d \n", n, k);
    printf("      m = %d \n", m);
    printf("    --- Initialisation du descripteur --- \n");
    // Initialisation du descripteur

    DESC_AUDIO desc = init_vide_DESC_AUDIO(n, m);
    if(desc.histo.k != k) return 1;
    if(desc.histo.m != m) return 1;
    printf("      Descripteur: id=%d, k=%d, m=%d\n", desc.id, desc.histo.k, desc.histo.m);

    int y, x;

    printf("    --- SET DESC AUDIO --- \n");
    for(y = 0; y < k; y++)
        for(x = 0; x < m; x++)
            set_DESC_AUDIO(&desc, y, x, (y * desc.histo.m + x));

    printf("    --- GET DESC AUDIO --- \n");
    for(y = 0; y < k; y++)
        for(x = 0; x < m; x++)
            if(get_DESC_AUDIO(desc, y, x) != (y * desc.histo.m + x)) return 1;

    
    printf("    --- CREER HISTOGRAMME TXT DESC AUDIO --- \n");

    HISTOGRAMME_AUDIO histoTXT;
    int codeTXT = generer_HISTOGRAMME_AUDIO(&histoTXT, "./TEST_SON/corpus_fi.txt", n, m);
    if(codeTXT != HISTOGRAMME_CREER_SUCCES) return 1;
    //affiche_HISTOGRAMME_AUDIO(histoTXT);
    

    printf("    --- CREER HISTOGRAMME BIN DESC AUDIO --- \n");

    HISTOGRAMME_AUDIO histoBIN;
    int codeBIN = generer_HISTOGRAMME_AUDIO(&histoBIN, "./TEST_SON/corpus_fi.bin", n, m);
    if(codeBIN != HISTOGRAMME_CREER_SUCCES) return 1;
    //affiche_HISTOGRAMME_AUDIO(histoBIN);

    printf("    --- CREER HISTOGRAMME WAV DESC AUDIO --- \n");

    HISTOGRAMME_AUDIO histoWAV;
    int codeWAV = generer_HISTOGRAMME_AUDIO(&histoWAV, "./TEST_SON/corpus_fi.wav", n, m);
    if(codeWAV != HISTOGRAMME_CREER_SUCCES) return 1;
    //affiche_HISTOGRAMME_AUDIO(histoWAV);

    printf("    --- VERIFICATION D'EGALITE --- \n");
    int compareTXTBIN = compare_HISTOGRAMME_AUDIO(histoTXT, histoBIN);
    int compareTXTWAV = compare_HISTOGRAMME_AUDIO(histoTXT, histoWAV);
    int compareBINWAV = compare_HISTOGRAMME_AUDIO(histoBIN, histoWAV);
    printf("      --- HISTO TXT == HISTO BIN --- \n");
    printf("        %s\n", (compareTXTBIN == 0 ? "Vrai" : "Faux"));
    if(compareTXTBIN != 0) return 1;
    printf("      --- HISTO TXT == HISTO WAV --- \n");
    printf("        %s\n", (compareTXTWAV == 0 ? "Vrai" : "Faux"));
    if(compareTXTWAV != 0) return 1;
    printf("      --- HISTO BIN == HISTO WAV --- \n");
    printf("        %s\n", (compareBINWAV == 0 ? "Vrai" : "Faux"));
    if(compareBINWAV != 0) return 1;


    printf("  --- CONTROLEUR BASE DESCRIPTEUR --- \n");
    printf("    --- Initialisation du controleur --- \n");
    PILE pileDescripteur = init_PILE();
    init_FICHIER_BASE_DESC(pileDescripteur);

    printf("    --- Création du descripteur audio de TEST_SON/corpus_fi.wav --- \n");
    DESC_AUDIO descCorpusWAV = init_DESC_AUDIO(0, n, m, "TEST_SON/corpus_fi.wav");
    lier_DESC_AUDIO_FICHIER(descCorpusWAV, "TEST_SON/corpus_fi.wav");
    
    printf("    --- Sauvegarde du descripteur --- \n");
    pileDescripteur = sauvegarder_DESC_AUDIO(pileDescripteur, descCorpusWAV);

    printf("    --- Sauvegarde de la pile de descripteurs --- \n");
    sauvegarder_PILE_DESC_AUDIO(pileDescripteur);

    printf("    --- Création du descripteur audio de TEST_SON/jingle_fi.wav --- \n");
    DESC_AUDIO descJingleWAV = init_DESC_AUDIO(1, n + 2, m, "TEST_SON/jingle_fi.wav");
    lier_DESC_AUDIO_FICHIER(descJingleWAV, "TEST_SON/jingle_fi.wav");
    
    printf("    --- Sauvegarde du descripteur --- \n");
    pileDescripteur = sauvegarder_DESC_AUDIO(pileDescripteur, descJingleWAV);

    printf("    --- Sauvegarde de la pile de descripteurs --- \n");
    sauvegarder_PILE_DESC_AUDIO(pileDescripteur);

    printf("    --- Chargement des descripteurs enregistrés --- \n");
    PILE secondePile = charger_PILE_DESC_AUDIO();

    printf("       --- Pile est vide ? --- \n");
    printf("          %s \n", (PILE_estVide(secondePile) ? "Oui" : "Non"));
    if(PILE_estVide(secondePile) != 0) return 1;

    printf("       --- Depile premier descripteur --- \n");
    DESC_AUDIO descDepile1;
    secondePile = dePILE(secondePile, &descDepile1);

    printf("         --- Descripteur depile1 == celui empile ? --- \n");
    int compareDepile1Empile = compare_DESC_AUDIO(descDepile1, descCorpusWAV);
    printf("           %s\n", (compareDepile1Empile == 0 ? "Vrai" : "Faux"));
    if(compareDepile1Empile != 0) return 1;

    printf("       --- Pile est vide ? --- \n");
    printf("          %s \n", (PILE_estVide(secondePile) ? "Oui" : "Non"));
    if(PILE_estVide(secondePile) != 0) return 1;

    printf("       --- Depile second descripteur --- \n");
    DESC_AUDIO descDepile2;
    secondePile = dePILE(secondePile, &descDepile2);

    printf("         --- Descripteur depile2 == celui empile ? --- \n");
    int compareDepile2Empile = compare_DESC_AUDIO(descDepile2, descJingleWAV);
    printf("           %s\n", (compareDepile2Empile == 0 ? "Vrai" : "Faux"));
    if(compareDepile2Empile != 0) return 1;

    printf("       --- Pile est vide ? --- \n");
    printf("          %s \n", (PILE_estVide(secondePile) ? "Oui" : "Non"));
    if(PILE_estVide(secondePile) != 1) return 1;

    printf("    --- Création des descripteurs audio du dossier TEST_SON --- \n");
    PILE pileDescDossier = init_MULTIPLE_DESC_AUDIO(0, 2, 15, "TEST_SON");

    DESC_AUDIO depileDesc;
    while(!PILE_estVide(pileDescDossier))
    {
    	pileDescDossier = dePILE(pileDescDossier, &depileDesc);
        char * chemin = fichier_lier_DESC_AUDIO(depileDesc);
        printf(" Fichier associé au descripteur %d: %s\n", depileDesc.id, 
            chemin != NULL ? chemin : "Introuvable");
    	if(chemin != NULL) free(chemin);
        //affiche_DESC_AUDIO(depileDesc);
    }
   
    printf("  --- RECHERCHE --- \n");
    printf("    --- Recherche TEST_SON/jingle_fi.wav  dans TEST_SON/corpus_fi.wav avec les 3 meilleurs résultats --- \n");

    DESC_AUDIO desc1 = init_DESC_AUDIO(0, 5, 30, "TEST_SON/corpus_fi.wav");
    DESC_AUDIO desc2 = init_DESC_AUDIO(1, 5, 30, "TEST_SON/jingle_fi.wav");
    RES_EVAL_AUDIO resultat = evaluer_DESC_AUDIO(desc1, desc2, 3);
    printf("      Temps trouvés:\n");
    for(int i = 0; i < resultat.n; i++)
    {
        printf("      i = %d: %f\n", i, resultat.times[i]);
    }
    //affiche_DESC_AUDIO(desc1);
    //affiche_DESC_AUDIO(desc2);


    printf("--- FIN DES TEST AUDIO --- \n");
    return 0;
}