#include "types.h"
#include "liste.h"
#include <stdio.h>

void afficher(liste* l) {
  liste *tmp = l;

  while(tmp != NULL)
  {
      printf("%d ", tmp->valeur);
      tmp = tmp->suivant;
  }
}

liste* ajoute_fin(liste* l, int entier) {
  liste *nouvelElement;
  nouvelElement->valeur = entier;
  nouvelElement->suivant = NULL;

  if(l == NULL){
    return nouvelElement;
  } else {
    liste* temp = l;
    while(temp->suivant != NULL)
    {
        temp = temp->suivant;
    }
    temp->suivant = nouvelElement;
    return l;
  }
  return l;
}

liste* ajoute_debut(liste* l, int entier) {

    return l;
}

liste* ajoute_position(liste* l, int entier) {

    return l;
}

liste* remplir(liste* l, int tab[], unsigned int nb) {

    int i = 0;
    liste* l_copy = l;
    for(i = 0; i < nb; i++) {
        l->valeur = tab[i];
        l = l->suivant;
    }
    return l_copy;

}

int rechercher(liste* l, int entier) {

    liste* courant = l;
    int j = 1;
    while(courant != NULL) {
        if(courant->valeur == entier) {
            return j;
        }
        courant = courant->suivant;
        j++;
    }

    return -1;
}

liste* supprimer(liste* l, int entier) {

    return l;
}

void vider(liste** l) {

}
