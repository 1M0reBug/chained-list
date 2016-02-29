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
void test_fusion();

int main() {
  int liste_triee = 0;

  /*Initialisation des liste*/
  strings* ma_liste_triee = NULL;
  strings* ma_liste = NULL;
  strings* liste1 = NULL;
  strings* liste2 = NULL;

  const char* tab[5];
  tab[0] = "bbb";
  tab[1] = "aaa";
  tab[2] = "eee";
  tab[3] = "ccc";
  tab[4] = "ddd";

  ma_liste = str_remplir(ma_liste, tab, 5);

  printf("La liste :\n");
  str_afficher(ma_liste);
  printf("---\n\n");

    eclatement(ma_liste, &liste1, &liste2);
    printf("Liste 1 :\n");
    str_afficher(liste1);
    printf("---\n\n");

    printf("Liste 2 :\n");
    str_afficher(liste2);
    printf("---\n\n");


  ma_liste_triee = str_remplir(ma_liste_triee, tab, 5); //temporaire pour eviter les seg fault (a supprimer apres avoir fait la fusion)
  printf("Voici votre liste triée :\n");
  str_afficher(ma_liste_triee);
  printf("---\n");


  //test_lists();
  //test_strings();
  return 0;
}

void test_strings() {
    strings* ma_liste = NULL;
    const char* tab[5];
    tab[0] = "aaa";
    tab[1] = "bbb";
    tab[2] = "ccc";
    tab[3] = "ddd";
    tab[4] = "eee";

    printf("Remplir la liste :\n");
    ma_liste = str_remplir(ma_liste, tab, 5);
    str_afficher(ma_liste);
    printf("---\n");

    printf("\nSupprimer le ccc :\n");
    ma_liste = str_supprimer(ma_liste, "ccc");
    str_afficher(ma_liste);
    printf("---\n");

    printf("\nSuppression du premier:\n");
    ma_liste = str_supprimer(ma_liste, "aaa");
    str_afficher(ma_liste);
    printf("---\n");

    printf("\nAjoute position 4, 'zzz':\n");
    str_ajoute_position(ma_liste, "zzz", 4);
    str_afficher(ma_liste);
    printf("---\n");


    printf("\nAjoute Debut 'www':\n");
    str_ajoute_debut(ma_liste, "www");
    str_afficher(ma_liste);
    printf("---\n");


    printf("\nRecherche de la valeur 10:\n");
    printf("la valeur 'bbb' a ete trouvee a la position : %d\n", str_rechercher(ma_liste, "bbb"));
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

void test_fusion() {
    strings* s1 = NULL;
    strings* s2 = NULL;
    char* tab1[2];
    tab1[0] = "aaa";
    tab1[1] = "ddd";

    char* tab2[3];
    tab2[0] = "ccc";
    tab2[1] = "bbb";
    tab2[2] = "eee";

    s1 = str_remplir(s1, tab1, 2);
    s2 = str_remplir(s2, tab2, 3);

    strings* dst = NULL;
    dst = fusion(s1, s2);

    str_afficher(dst);
    printf("---\n");

    str_vider(&dst);
    str_vider(&s1);
    str_vider(&s2);
}
