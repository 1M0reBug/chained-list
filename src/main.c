/**
  * Quagliatini Jordan + ROGAI Rayan
  * Description:
  *   Le TP sur les listes chainées
*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "liste.h"

int main(void) {
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


  return 0;
}
