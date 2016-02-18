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

  remplir(ma_liste,tab,10);
  afficher(ma_liste);
  vider(&ma_liste);


  return 0;
}
