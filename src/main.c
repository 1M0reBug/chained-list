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

  ma_liste = remplir(ma_liste,tab,10);
  afficher(ma_liste);

  supprimer(ma_liste, 4);

  printf("---\n");
  afficher(ma_liste);

  ajoute_position(ma_liste, 4, 4);

  printf("---\n");
  afficher(ma_liste);

  ajoute_debut(ma_liste, 0);

  printf("---\n");
  afficher(ma_liste);


  printf("---\n");
  printf("la valeur 10 a ete trouvee a la position : %d\n", rechercher(ma_liste, 10));

  vider(&ma_liste);


  return 0;
}
