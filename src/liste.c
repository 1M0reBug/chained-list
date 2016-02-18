#include "types.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void afficher(liste* l) {
  liste *tmp = l;

  while(tmp != NULL)
  {
      printf("%d ", tmp->valeur);
      tmp = tmp->suivant;
  }
}

liste* ajoute_fin(liste* l, int entier) {
  liste *nouvelElement = malloc(sizeof(liste));
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

    liste* _l = malloc(sizeof(liste));
    _l->valeur = l->valeur;
    _l->suivant = l->suivant;

    l->valeur = entier;
    l->suivant = l;

    return l;
}

liste* ajoute_position(liste* l, int entier, unsigned int position) {

    unsigned int i = 1;
    liste* courant = l;

    for(i = 1; i < position && courant->suivant != NULL; i++) {
        courant = courant->suivant;
    }

    liste* fin = malloc(sizeof(liste));
    fin->valeur = entier;
    fin->suivant = NULL;
    courant->suivant = fin;

    return l;
}

liste* remplir(liste* l, int tab[], unsigned int nb) {

    unsigned int i = 0;
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
    liste* courant;
    liste* precedent;
    courant = l;
    while(courant->suivant != NULL) {
        if((courant->suivant)->valeur == entier) {
            precedent = courant;
            courant = courant->suivant;
            precedent->suivant = courant->suivant;
            return l;
        }

        courant = courant->suivant;
    }
    return l;
}

void vider(liste** l) {
  liste* tmp = *l;
  liste* tmpnxt = malloc(sizeof(liste));

  while(tmp != NULL)
  {
    tmpnxt = tmp->suivant;
    free(tmp);
    tmp = tmpnxt;
  }
}
