#include "strings.h"
#include <stdio.h>
#include <stdlib.h>


/**
  * @author Jordan QUAGLIATINI, Rayan ROGAÏ
  * @date 18/02/2016
  * Ce fichier regroupe l'ensemble des fonctions de manipulation
  * d'une liste chainée de chaines de caractères.
  */


/**
  * Cette méthode affiche une liste
  * en la parcourant élément par élément
  * @param l : strings* la liste à afficher
  */
void str_afficher(strings* l) {
  strings *tmp = l;

  while(tmp)
  {
      printf("%s \n", tmp->valeur);
      tmp = tmp->suivant;
  }
}

/**
  * ajoute un élément à la fin de la strings
  * passée en paramètrue
  * @param l: strings* la liste à laquelle il faut
  *           ajouter un élément à la fin
  * @param entier: int un entier à ajouter à la fin de la strings
  * @return strings* la strings modifiée
  */
strings* str_ajoute_fin(strings* l, char* chaine) {
  strings *nouvelElement = malloc(sizeof(strings));
  strcpy(nouvelElement->valeur, chaine);
  nouvelElement->suivant = NULL;

  if(l == NULL){
    return nouvelElement;
  } else {
    strings* temp = l;
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
  * la strings
  * @param l: strings* la strings à modifier
  * @param entier: int l'entier à ajouter au début de la strings
  * @return strings* la strings modifiée
  */
strings* str_ajoute_debut(strings* l, char* chaine) {

    strings* _l = malloc(sizeof(strings));
    strcpy(_l->valeur, l->valeur);
    _l->suivant = l->suivant;

    strcpy(l->valeur, chaine);
    l->suivant = _l;

    return l;
}

/**
  * ajoute un élément à une position donnée dans la strings
  * @param l: strings* la strings à modifier
  * @param entier: int l'entier à ajouter dans la strings
  * @param position: unsigned int la position à laquelle il faut
  *                  ajouter entier
  * @return strings* la strings modifiée
  */
strings* str_ajoute_position(strings* l, char* chaine, unsigned int position) {

    unsigned int i = 1;
    strings* courant = l;

    for(i = 1; i < position-1 && courant->suivant; i++) {
        courant = courant->suivant;
    }

    strings* fin = malloc(sizeof(strings));
    strcpy(fin->valeur, chaine);
    fin->suivant = courant->suivant;
    courant->suivant = fin;

    return l;
}

/**
  * remplit la strings avec les éléments d'un tableau
  * de taille nn
  * @param l: strings* la strings à modifier
  * @param tab: int[] un tableau d'entiers
  * @param nb: unsigned int la taille du tableau tab
  * @return strings* la strings remplie
  */
strings* str_remplir(strings* l, char* tab[], unsigned int nb) {

    unsigned int i = 0;
    strings* l_copy = l;
    for(i = 0; i < nb; i++) {
      l = str_ajoute_fin(l,tab[i]);
      if(l_copy == NULL) {
          l_copy = l;
      }
    }
    return l_copy;

}

/**
  * recherche un entier dans la strings donnée en paramètre et
  * renvoie sa position dans la strings.
  * @param l: strings* la strings à modifier
  * @param entier: un entier à chercher dans la strings
  * @return int la position de l'entier recherché
  */
int str_rechercher(strings* l, char* chaine) {

    strings* courant = l;
    int j = 1;
    while(courant) {
        if(strcmp(courant->valeur, chaine)) {
            return j;
        }
        courant = courant->suivant;
        j++;
    }

    return -1;
}

/**
  * supprime un élément dans la strings passée en paramètre
  * @param l: strings* la strings à modifier
  * @param entier: int l'entier à supprimer de la strings
  * @return strings* la strings modifiée
  */
strings* str_supprimer(strings* l, char* chaine) {
    strings* courant;
    strings* precedent;
    courant = l;
    while(courant->suivant) {
        if(strcmp(courant->valeur, chaine)) {
            l = courant->suivant;
            free(courant);
            return l;

        } else if(strcmp((courant->suivant)->valeur, chaine) ) {
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
  * vide et libère la mémoire occupée par la strings
  * @param l: strings** un pointeur sur la tête de la strings
  */
void str_vider(strings** l) {
  strings* tmp = *l;
  strings* del;

  while(tmp) {
    del = tmp;
    tmp = tmp->suivant;
    free(del);
  }

  l = NULL;
}