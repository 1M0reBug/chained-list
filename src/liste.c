#include "types.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>


/**
  * @author Jordan QUAGLIATINI, Rayan ROGAÏ
  * @date 18/02/2016
  * Ce fichier regroupe l'ensemble des fonctions de manipulation
  * d'une liste chainée.
  */


/**
  * Cette méthode affiche une liste
  * en la parcourant élément par élément
  * @param l : liste* la liste à afficher
  */
void afficher(liste* l) {
  liste *tmp = l;

  while(tmp)
  {
      printf("%d \n", tmp->valeur);
      tmp = tmp->suivant;
  }
}

/**
  * ajoute un élément à la fin de la liste
  * passée en paramètrue
  * @param l: liste* la liste à laquelle il faut
  *           ajouter un élément à la fin
  * @param entier: int un entier à ajouter à la fin de la liste
  * @return liste* la liste modifiée
  */
liste* ajoute_fin(liste* l, int entier) {
  liste *nouvelElement = malloc(sizeof(liste));
  nouvelElement->valeur = entier;
  nouvelElement->suivant = NULL;

  if(l == NULL){
    return nouvelElement;
  } else {
    liste* temp = l;
    while(temp->suivant)
    {
        temp = temp->suivant;
    }
    temp->suivant = nouvelElement;
    return l;
  }
  return l;
}

/**
  * ajoute un élément à la place de la tête de
  * la liste
  * @param l: liste* la liste à modifier
  * @param entier: int l'entier à ajouter au début de la liste
  * @return liste* la liste modifiée
  */
liste* ajoute_debut(liste* l, int entier) {

    liste* _l = malloc(sizeof(liste));
    _l->valeur = l->valeur;
    _l->suivant = l->suivant;

    l->valeur = entier;
    l->suivant = _l;

    return l;
}

/**
  * ajoute un élément à une position donnée dans la liste
  * @param l: liste* la liste à modifier
  * @param entier: int l'entier à ajouter dans la liste
  * @param position: unsigned int la position à laquelle il faut
  *                  ajouter entier
  * @return liste* la liste modifiée
  */
liste* ajoute_position(liste* l, int entier, unsigned int position) {

    unsigned int i = 1;
    liste* courant = l;

    for(i = 1; i < position-1 && courant->suivant; i++) {
        courant = courant->suivant;
    }

    liste* fin = malloc(sizeof(liste));
    fin->valeur = entier;
    fin->suivant = courant->suivant;
    courant->suivant = fin;

    return l;
}

/**
  * remplit la liste avec les éléments d'un tableau
  * de taille nb
  * @param l: liste* la liste à modifier
  * @param tab: int[] un tableau d'entiers
  * @param nb: unsigned int la taille du tableau tab
  * @return liste* la liste remplie
  */
liste* remplir(liste* l, int tab[], unsigned int nb) {

    unsigned int i = 0;
    liste* l_copy = l;
    for(i = 0; i < nb; i++) {
      l = ajoute_fin(l,tab[i]);
      if(l_copy == NULL) {
          l_copy = l;
      }
    }
    return l_copy;

}

/**
  * recherche un entier dans la liste donnée en paramètre et
  * renvoie sa position dans la liste.
  * @param l: liste* la liste à modifier
  * @param entier: un entier à chercher dans la liste
  * @return int la position de l'entier recherché
  */
int rechercher(liste* l, int entier) {

    liste* courant = l;
    int j = 1;
    while(courant) {
        if(courant->valeur == entier) {
            return j;
        }
        courant = courant->suivant;
        j++;
    }

    return -1;
}

/**
  * supprime un élément dans la liste passée en paramètre
  * @param l: liste* la liste à modifier
  * @param entier: int l'entier à supprimer de la liste
  * @return liste* la liste modifiée
  */
liste* supprimer(liste* l, int entier) {
    liste* courant;
    liste* precedent;
    courant = l;
    while(courant->suivant) {
        if(courant->valeur == entier) {
            l = courant->suivant;
            free(courant);
            return l;

        } else if((courant->suivant)->valeur == entier) {
            precedent = courant;
            courant = courant->suivant;
            precedent->suivant = courant->suivant;
            free(courant);
            return l;
        }

        courant = courant->suivant;
    }

    return l;
}

/**
  * vide et libère la mémoire occupée par la liste
  * @param l: liste** un pointeur sur la tête de la liste
  */
void vider(liste** l) {
  liste* tmp = *l;
  liste* del;

  while(tmp) {
    del = tmp;
    tmp = tmp->suivant;
    free(del);
  }

  l = NULL;
}
