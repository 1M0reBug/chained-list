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
  * ajoute un élément à la fin de la string
  * passée en paramètrue
  * @param l: strings* la liste à laquelle il faut
  *           ajouter un élément à la fin
  * @param entier: int un entier à ajouter à la fin de la strings
  * @return strings* la strings modifiée
  */
strings* str_ajoute_fin(strings* l, char* chaine) {
  strings *nouvelElement = malloc(sizeof(strings));
  nouvelElement->valeur = chaine;
  nouvelElement->suivant = NULL;

  if(l == NULL){
    l = nouvelElement;
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
    _l->valeur = "";
    _l->valeur = l->valeur;
    _l->suivant = l->suivant;

    l->valeur = chaine;
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
    fin->valeur = chaine;
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
strings* str_remplir(strings* l, const char* tab[], unsigned int nb) {

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
        if(strcmp(courant->valeur, chaine) == 0) {
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
        if(strcmp(courant->valeur, chaine) == 0) {
            l = courant->suivant;
            free(courant);
            courant = NULL;
            return l;

        } else if(strcmp((courant->suivant)->valeur, chaine) == 0) {
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

int str_size(strings* l) {
    strings* courant = l;
    int i = 0;
    while(courant) {
        courant = courant->suivant;
        i++;
    }
    return i;
}

strings* fusion(strings* l1, strings* l2) {

    strings* c1 = l1;
    strings* c2 = l2;
    strings* l = NULL;
    while(c1 || c2) {
        if(!c2 || c1 && c2 && str_size(c1) < str_size(c2)) {
            l=str_ajoute_fin(l, c1->valeur);
            c1 = c1->suivant;
        } else {
            l=str_ajoute_fin(l, c2->valeur);
            c2 = c2->suivant;
        }
    }
    return l;
}

void eclatement(strings* ma_liste, strings** liste1, strings** liste2) {
  int choix_liste = 0;
  char* courant = "";
  while(ma_liste)
  {
    if(strcmp(ma_liste->valeur, courant) < 0)
    {
      /*switch de liste */
      if(choix_liste == 0)
        choix_liste = 1;
      else if (choix_liste == 1)
        choix_liste = 0;
      else
        printf("Erreur de choix de liste (2)\n");
    }
    switch (choix_liste)
    {
      case 0:
        *liste1 = str_ajoute_fin(*liste1, ma_liste->valeur);
        courant = ma_liste->valeur;
        break;

      case 1:
        *liste2 = str_ajoute_fin(*liste2, ma_liste->valeur);
        courant = ma_liste->valeur;
        break;

      default :
        printf("Erreur de choix de liste\n");
    }

    ma_liste = ma_liste->suivant;
  }

}
