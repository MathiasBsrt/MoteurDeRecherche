/***
 * Ici les tests de l'indexation
 */
//#SI notre prog de test retourn 1 : echec de la pipeline
#include <stdio.h>
#include <stdlib.h>

// Includes pour tests son
#include <math.h>
#include "../src/module_audio/wav_file_helper.h"
#include "../src/module_audio/descripteur.h"
#include "../src/module_audio/histogramme.h"
#include "../src/module_audio/base_descripteur.h"

int indexationImage(){
    //Lancer une indexation pour tous les fichiers du dossier de test
    //On récupere les fichiers générés base_descripteur_image et lier_base_image
    //On compare ces deux fichiers avec nos fichiers base_descripteur_image_OK et lier_base_image_OK => ces deux fichiers sont une version confirmée de nos indexations
    int res = 0;

    //if base_descripteur_image != base_descripteur_OK || lier_base_image != lier_base_image_OK

    if(res){
        printf("ERREUR DANS L'INDEXATION DES IMAGES");
    }else{
        printf("SUCCES DANS L'INDEXATION DES IMAGES");
    }
    return res;
}

int indexationTexte(){
    return 0;
}

int indexationSon(){
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
    
    printf("    --- Sauvegarde du descripteur --- \n");
    pileDescripteur = sauvegarder_DESC_AUDIO(pileDescripteur, descCorpusWAV);

    printf("    --- Sauvegarde de la pile de descripteurs --- \n");
    sauvegarder_PILE_DESC_AUDIO(pileDescripteur);

    printf("    --- Création du descripteur audio de TEST_SON/jingle_fi.wav --- \n");
    DESC_AUDIO descJingleWAV = init_DESC_AUDIO(1, n + 2, m, "TEST_SON/jingle_fi.wav");
    
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
        if(depileDesc.id == 0) if(strcmp(chemin, "TEST_SON/corpus_fi.wav") != 0)
        {
            fprintf(stderr, "Le chemin trouvé n'est pas le bon, il doit être TEST_SON/corpus_fi.wav au lieu de %s !\n", chemin);
            return 1;   
        }
        if(depileDesc.id == 1) if(strcmp(chemin, "TEST_SON/jingle_fi.wav") != 0)
        {
            fprintf(stderr, "Le chemin trouvé n'est pas le bon, il doit être TEST_SON/jingle_fi.wav au lieu de %s !\n", chemin);
            return 1;   
        }
    	if(chemin != NULL) free(chemin);
        //affiche_DESC_AUDIO(depileDesc);
    }

    printf("  --- RECHERCHE --- \n");
    printf("    --- Recherche TEST_SON/jingle_fi.wav  dans TEST_SON/corpus_fi.wav avec les 3 meilleurs résultats --- \n");

    // On pose une marge de 1.0 seconde pour le calcul de la position du jingle dans le corpus.
    double marge = 1.0;

    DESC_AUDIO desc1 = init_DESC_AUDIO(0, 5, 30, "TEST_SON/corpus_fi.wav");
    DESC_AUDIO desc2 = init_DESC_AUDIO(1, 5, 30, "TEST_SON/jingle_fi.wav");
    RES_EVAL_AUDIO resultat = evaluer_DESC_AUDIO(desc1, desc2, 3);
    if(resultat.n == 0)
    {
        fprintf(stderr, "Aucun résultat trouvé .. Normalement le programme doit trouver le jingle à +/- 29s.\n");
        return 1;
    }
    printf("      Temps trouvés:\n");
    for(int i = 0; i < resultat.n; i++)
    {
        printf("      i = %d: %f\n", i, resultat.times[i]);
    }
    if(resultat.times[0] < 29 - marge || resultat.times[0] > 29 + marge)
    {
        fprintf(stderr, "Le résultat trouvé n'est pas bon.\n");
        fprintf(stderr, "Le programme a trouvé %f et cette valeur n'est pas dans l'interval [%d ; %f]\n", resultat.times[0], resultat.times[0] - marge, resultat.times[0] + marge);
        return 1;
    }
    printf("--- FIN DES TEST AUDIO --- \n");
    return 0;
}

int main(int argc, char const *argv[])
{
    int res = 0;
    res = res || indexationImage();
    res = res || indexationSon();
    res = res || indexationTexte();
    
    return res;
}
