/**
 * @file moteur.h
 * @author DUVIVIER Davy et BOSSAERTS Mathias
 * @brief header de la partie recherche des images
 * @date 2020-12-16
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <stdio.h>
//#include "../pile_dynamique.h"
#include "../controle_descripteur.h"
#define SEUIL_DOMINANTE 30
#define SEUIL_RGB 70
#define SEUIL_NB 85


int comparaison_image(Descripteur_image d1, Descripteur_image d2, double seuil,int RGB_ou_NB, double* pourcentage);


void rechercheParCritere_image(RGB couleurDominante, FILE *fichiersSimilaires, int seuilSimilarite);


void rechercheParDocument_RGB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite);

void rechercheParDocument_NB(char *cheminVersDocument, FILE *fichiersSimilaires, int seuilSimilarite);

void id_to_chemin_image(int id,int NB_RGB,char* chemin);

int chemin_to_id_image(char* chemin, int nb_RGB);
