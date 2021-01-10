/**
 * @file index.c
 * @author Baptiste POMARELLE
 * @brief Fonctions relatives aux index de mots
 * @version 0.1
 * @date 2020-12-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "index.h"

Table_Index Init_Index()
{
    return NULL;
}

int Table_indexEstVide(Table_Index table)
{
    return table == NULL;
}

Index *ExisteDansTable_Index(Table_Index table, char *mot)
{
    Index *parcours = NULL;
    if (!Table_indexEstVide(table))
    {
        int test = 0;
        parcours = table;
        while (parcours)
        {
            test = strcmp(parcours->mot, mot);
            if (test < 0)
                parcours = parcours->droit;
            else if (test > 0)
                parcours = parcours->gauche;
            else
            {
                break;
            }
        }
    }
    return parcours;
}

void Incremente_index(Index *index, int id, int nbr_occ)
{
    if (index->nb_occ == index->nb_max)
    {
        index->nb_max *= 2;
        for (int i = 0; i < 2; i++)
            index->idTxt_avec_occ[i] = realloc(index->idTxt_avec_occ[i], sizeof(int) * index->nb_max);
    }
    index->idTxt_avec_occ[0][index->nb_occ] = id;
    index->idTxt_avec_occ[1][index->nb_occ] = nbr_occ;

    index->nb_occ = index->nb_occ + 1;
}

Index *Ajout_Dans_Table_index(Table_Index *table, char *mot)
{
    int test;
    if (Table_indexEstVide(*table))
    {
        *table = malloc(sizeof(Index));
        for (int i = 0; i < 2; i++)
            (*table)->idTxt_avec_occ[i] = malloc(sizeof(int) * MAX_INDEX);
        (*table)->nb_max = MAX_INDEX;
        (*table)->nb_occ = 0;
        (*table)->gauche = NULL;
        (*table)->droit = NULL;
        strcpy((*table)->mot, mot);
    }
    else
    {

        test = strcmp((*table)->mot, mot);
        if (test > 0)
            Ajout_Dans_Table_index(&(*table)->gauche, mot);
        else
            Ajout_Dans_Table_index(&(*table)->droit, mot);
    }
}

void parcourInFixe(Table_Index a) //fonction intermédiaire pour l'affichage
{
    if (!Table_indexEstVide(a))
    {
        parcourInFixe(a->gauche);
        printf("Mot : %s\n", a->mot);
        printf("nombre de textes dans lequel il est present : %d\n", a->nb_occ);
        parcourInFixe(a->droit);
    }
}

void AFFICHE_table_index(Table_Index a)
{
    if (Table_indexEstVide(a))
        printf("cet arbre est vide");
    else
    {
        printf("Affichage des valeurs dans l'ordre :\n");
        parcourInFixe(a);
        printf("\n");
    }
}

void parcourInFixe2(Table_Index a, FILE *f) //fonction intermédiaire pour l'enregistrement
{
    if (!Table_indexEstVide(a))
    {
        parcourInFixe2(a->gauche,f);
        fwrite(a, sizeof(Index), 1, f);
        parcourInFixe2(a->droit,f);
    }
}

void enregistre_Table_Index(Table_Index table, char *save_table_index)
{
    if (!Table_indexEstVide(table))
    {
        FILE *f = fopen(save_table_index, "w");
        if (f)
        {
            parcourInFixe2(table, f);
            fclose(f);
        }
    }
    else
    {
        printf("la table est vide, rien n'a ete enregistre.\n");
    }
}

void Ajout_dans_table_pourCharger(Table_Index *table, Index index)
{
    int test;

    if (Table_indexEstVide(*table))
    {
        
        *table = malloc(sizeof(Index));
        (*table)->nb_max = index.nb_max;
        (*table)->nb_occ = index.nb_occ;
        for (int i = 0; i < 2; i++)
            (*table)->idTxt_avec_occ[i] = malloc(sizeof(int) * index.nb_max);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index.nb_occ;j++)
            {
                (*table)->idTxt_avec_occ[i][j]=index.idTxt_avec_occ[i][j];
            }
        }
        
        (*table)->gauche = NULL;
        (*table)->droit = NULL;
        strcpy((*table)->mot, index.mot);
    }
    else
    {

        test = strcmp((*table)->mot, index.mot);
        if (test > 0)
            Ajout_dans_table_pourCharger(&(*table)->gauche, index);
        else
            Ajout_dans_table_pourCharger(&(*table)->droit, index);
    }
}

void charger_Table_index(Table_Index *table, char *save_table_index)
{
    FILE *f = fopen(save_table_index, "r");
    if (f)
    {
        Index tmp;
        while (fread(&tmp, sizeof(Index), 1, f))
            {
                Ajout_dans_table_pourCharger(table,tmp);
            }
    }
}