#include <stdio.h>
#include <stdlib.h>

struct FICHE
{
  float longueur_sepale;
  float largeur_sepale;
  float longueur_petale;
  float largeur_petale;
  char setosa;
  char versicolor;
  char virginica;
};
typedef struct FICHE F;

F *IrisLecture(int nb_samples)
{
  int i;
  i = 0;
  FILE *ftxt;

  F info;

  printf("aled");

  ftxt = fopen("iris_data.txt", "r");
  if (ftxt == NULL)
    return NULL;

  //def alloc
  F *tab_info = (F *)malloc(150 * sizeof(F));
  int nb_entrees, nb_sorties;
  printf("aled");

  fscanf(ftxt, "%d %s", &nb_entrees, (char *)NULL);
  fscanf(ftxt, "%d %s", &nb_sorties, (char *)NULL);

  while (fscanf(ftxt, "%f %f %f %f %c %c %c",
                &tab_info[i].largeur_sepale, &tab_info[i].largeur_sepale, &tab_info[i].longueur_petale, &tab_info[i].largeur_sepale, &tab_info[i].setosa, &tab_info[i].versicolor, &tab_info[i].virginica) != EOF)
  {
  }

  return tab_info;
}

int main(void)
{

  F *tab = IrisLecture(120);
  printf("aled");
  int i;

  for (i = 0; i < 10; i++)
  {
    printf("%lf", tab[i].longueur_petale);
  }
}