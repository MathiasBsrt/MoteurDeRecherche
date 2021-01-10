/**
 * @file pile_dynamique.c
 * @author Baptiste POMARELLE
 * @brief Les fonctions relatives a la pile de mots (et de leurs occurences) et a la pile de descripteurs
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "pile_dynamique.h"

PILE init_pile()
{
    PILE p;
    p = NULL;
    return p;
}

int PILE_estVide(PILE p)
{
    return (p == NULL);
}

void affiche_PILE(PILE p)
{
    if (PILE_estVide(p))
        fprintf(stderr, "La pile est vide\n");

    else
    {
        Cellule *parcours = p;
        printf("\n\n\t AFFICHAGE DES MOTS ET LEURS OCCURENCES\n");
        do
        {
            affiche_MOT(parcours->elt);
            parcours = parcours->suivant;
        } while (parcours != NULL);
        printf("\n");
    }
}

PILE emPILE(PILE p, MOT elt)
{
    Cellule *cel = malloc(sizeof(Cellule));
    cel->suivant = NULL;
    cel->elt = elt;
    if (PILE_estVide(p))
    {
        p = cel;
    }
    else
    {
        Cellule *parcours = p;
        while (parcours->suivant != NULL)
            parcours = parcours->suivant;
        parcours->suivant = cel;
    }
    return p;
}

PILE dePILE(PILE p, MOT *elt)
{
    if (PILE_estVide(p))
        fprintf(stderr, "La pile est deja vide");
    else
    {
        if (p->suivant == NULL)
        {
            *elt = p->elt;
            p = NULL;
        }
        else
        {
            Cellule *parcour = p;
            Cellule *marqueur;
            while (parcour->suivant != NULL)
                parcour = parcour->suivant;
            *elt = parcour->elt;
            marqueur = parcour;
            parcour = p;
            while (parcour->suivant != marqueur)
                parcour = parcour->suivant;
            parcour->suivant = NULL;
            free(marqueur);
        }
    }

    return p;
}

int estDanslaPile(PILE p, char *buffer)
{
    Cellule *parcours = NULL;
    if (!PILE_estVide(p))
    {
        int test = 0;
        parcours = p;
        while (parcours && !test)
        {
            test = compare_MOT(parcours->elt, affecter_MOT(buffer));
            if (test)
                parcours->elt.nbr_occurrence = parcours->elt.nbr_occurrence + 1;
            parcours = parcours->suivant;
        }
        return test;
    }
    else
    {
        return 0;
    }
}

PILE_descripteur_texte init_PILE_desc()
{
    PILE_descripteur_texte p;
    p = NULL;
    return p;
}

int PILE_desc_estVide(PILE_descripteur_texte d)
{
    return (d == NULL);
}

int total_mot(PILE p, int *nombre_de_mots_differents)
{
    *nombre_de_mots_differents = 0;
    Cellule *parcours = p;
    int total = 0;
    if (PILE_estVide(p))
    {
        perror("la pile est vide");
        exit(1);
    }
    while (parcours)
    {
        total += parcours->elt.nbr_occurrence;
        *nombre_de_mots_differents = *nombre_de_mots_differents + 1;
        parcours = parcours->suivant;
    }
    return total;
}

void Index_from_pile(Table_Index *table, PILE pile, int id_texte)
{
    if (!PILE_estVide(pile))
    {
        Cellule *parcours = pile;
        Index *index;
        int passage = 0;
        while (parcours)
        {

            if (!(index = ExisteDansTable_Index(*table, parcours->elt.mot)))
            {
                index=Ajout_Dans_Table_index(table, parcours->elt.mot);
                Incremente_index(index,id_texte,parcours->elt.nbr_occurrence);
            }
            else
            {
                Incremente_index(index, id_texte, parcours->elt.nbr_occurrence);
            }
            parcours = parcours->suivant;
        }
    }
}

void EMPILE_desc_from_pile(PILE p, PILE_descripteur_texte *d, char *path_to_xml, Table_Index *table)
{
    FILE *liste_descripteurs = fopen("liste_base_descripteurs", "a");
    Index *index;
    int mots_retenus;

    //on remplit le descripteur a empiler
    Descripteur_texte *descripteur = malloc(sizeof(Descripteur_texte));
    descripteur->suivant = NULL;
    descripteur->pile_mot = p;
    descripteur->nombre_mots_total = total_mot(p, &mots_retenus); //on remplit le descripteur avec toutes les informations connues
    descripteur->nbr_mots_retenus = mots_retenus;

    if (PILE_desc_estVide(*d))
    {
        descripteur->id = 1;
        *d = descripteur;
        fprintf(liste_descripteurs, "%s %d\n", path_to_xml, descripteur->id);
    }
    else
    {
        int id = 2;
        Descripteur_texte *parcours = *d;
        while (parcours->suivant != NULL)
        {
            id++;
            parcours = parcours->suivant;
        }
        descripteur->id = id;
        fprintf(liste_descripteurs, "%s %d\n", path_to_xml, descripteur->id);

        parcours->suivant = descripteur;
    }
    Index_from_pile(table, p, descripteur->id);
}

void copie_descripteur(Descripteur_texte *a, Descripteur_texte b)
{
    a->id = b.id;
    a->nbr_mots_retenus = b.nbr_mots_retenus;
    a->nombre_mots_total = b.nombre_mots_total;
    a->pile_mot = b.pile_mot;
    a->suivant = NULL;
}

void EMPILE_desc(PILE_descripteur_texte *d, Descripteur_texte descripteur)
{
    Descripteur_texte *ajout = malloc(sizeof(Descripteur_texte));
    copie_descripteur(ajout, descripteur);
    if (PILE_desc_estVide(*d))
    {
        *d = ajout;
    }
    else
    {
        Descripteur_texte *parcours = *d;
        while (parcours->suivant != NULL)
        {
            parcours = parcours->suivant;
        }
        parcours->suivant = ajout;
    }
}

void DEPILE_desc(PILE_descripteur_texte *p)
{
    if (PILE_desc_estVide(*p))
        fprintf(stderr, "La pile est deja vide");
    else
    {
        if ((*p)->suivant == NULL)
        {
            free(*p);
        }
        else
        {
            Descripteur_texte *parcours = *p;
            Descripteur_texte *marqueur;
            while (parcours->suivant != NULL)
                parcours = parcours->suivant;
            marqueur = parcours;
            parcours = *p;
            while (parcours->suivant != marqueur)
                parcours = parcours->suivant;
            parcours->suivant = NULL;
            free(marqueur);
        }
    }
}

void enregistre_PILE_Desc(PILE_descripteur_texte p, char *save_descripteurs_textes)
{
    if (PILE_desc_estVide(p))
    {
        fprintf(stderr, "La pile est vide");
    }
    else
    {
        FILE *f = fopen(save_descripteurs_textes, "w");

        if (f)
        {
            Descripteur_texte *parcours = p;
            while (parcours)
            {
                fwrite(parcours, sizeof(Descripteur_texte), 1, f);
                parcours = parcours->suivant;
            }
            fclose(f);
        }
    }
}

void charger_PILE_Desc(PILE_descripteur_texte *p, char *save_descripteurs_textes)
{
    FILE *f = fopen(save_descripteurs_textes, "r");
    if (f)
    {
        Descripteur_texte tmp;
        while (fread(&tmp, sizeof(Descripteur_texte), 1, f))
        {
            EMPILE_desc(p, tmp);
        }
        fclose(f);
    }
}