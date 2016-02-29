/**
  * Quagliatini Jordan + ROGAI Rayan
  * Description: Le TP sur les listes chainées
  *   Attention penser à bien vider la liste apres utilisation grace à la fonction vider(**liste)
*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "liste.h"
#include "strings.h"

void test_lists();
void test_strings();

int main() {

  int liste_triee = 0;
  int choix_liste = 0;  // Liste L1 = 0 et L2 = 1

  /*Initialisation des liste*/
  strings* ma_liste = NULL;
  strings* liste1 = NULL;
  strings* liste2 = NULL;
  strings* ma_liste_triee = NULL;

  char* tab[5];

  tab[0] = 1;
  tab[1] = 2;
  tab[2] ="ccc";
  tab[3] ="ddd";
  tab[4] ="eee";
  str_remplir(ma_liste, tab, 5);

  printf("La liste :\n");
  str_afficher(ma_liste);
  printf("---\n");

  while(liste_triee == 0)
  {
    //Eclatement
    while(ma_liste->suivant != NULL)
    {
      switch (choix_liste)
      {
        case 0:
          liste1->valeur = ma_liste->valeur;
          liste1->suivant = NULL;
        break;

        case 1:
          liste2->valeur = ma_liste->valeur;
          liste2->suivant = NULL;
        break;

        default :
          printf("Erreur de choix de liste\n");
      }

      if(ma_liste->suivant->valeur <= ma_liste->valeur)
      {
        if(choix_liste == 0)
          choix_liste = 1;
        else if (choix_liste == 1)
            choix_liste = 1;
        else
        printf("Erreur de choix de liste (2)\n");
      }
    }

    //Fusion


  }

  printf("Voici votre liste triée :\n");
  str_afficher(ma_liste);
  printf("---\n");


  //test_lists();
  //test_strings();
  return 0;
}

void test_strings() {
    strings* ma_liste = NULL;
    char* tab[5];
    strcpy(tab[0],"aaa");
    strcpy(tab[1],"bbb");
    strcpy(tab[2],"ccc");
    strcpy(tab[3],"ddd");
    strcpy(tab[4],"eee");
    strcpy(tab[5],"fff");

    printf("Remplir la liste :\n");
    ma_liste = str_remplir(ma_liste, tab, 5);
    str_afficher(ma_liste);
    printf("---\n");

    printf("\nSupprimer le 4 :\n");
    str_supprimer(ma_liste, "aaa");
    str_afficher(ma_liste);
    printf("---\n");

    printf("\nSuppression du premier:\n");
    ma_liste = str_supprimer(ma_liste, "aaa");
    str_afficher(ma_liste);
    printf("---\n");

    printf("\nAjoute position 4, 4:\n");
    str_ajoute_position(ma_liste, "zzz", 4);
    str_afficher(ma_liste);
    printf("---\n");


    printf("\nAjoute Debut 0:\n");
    str_ajoute_debut(ma_liste, 0);
    str_afficher(ma_liste);
    printf("---\n");


    printf("\nRecherche de la valeur 10:\n");
    printf("la valeur 'ccc' a ete trouvee a la position : %d\n", str_rechercher(ma_liste, "ccc"));
    printf("---\n");

    printf("\nVidange de la liste:\n");
    str_vider(&ma_liste);
    printf("---\n");
}

void test_lists() {
    liste* ma_liste = NULL;
    int tab[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("Remplir la liste :\n");
    ma_liste = remplir(ma_liste, tab, 10);
    afficher(ma_liste);
    printf("---\n");

    printf("\nSupprimer le 4 :\n");
    supprimer(ma_liste, 4);
    afficher(ma_liste);
    printf("---\n");

    printf("\nSuppression du premier:\n");
    ma_liste = supprimer(ma_liste, 1);
    afficher(ma_liste);
    printf("---\n");

    printf("\nAjoute position 4, 4:\n");
    ajoute_position(ma_liste, 4, 4);
    afficher(ma_liste);
    printf("---\n");


    printf("\nAjoute Debut 0:\n");
    ajoute_debut(ma_liste, 0);
    afficher(ma_liste);
    printf("---\n");


    printf("\nRecherche de la valeur 10:\n");
    printf("la valeur 10 a ete trouvee a la position : %d\n", rechercher(ma_liste, 10));
    printf("---\n");

    printf("\nVidange de la liste:\n");
    vider(&ma_liste);
    printf("---\n");
}
