#ifndef LISTE_H
#define LISTE_H

void afficher(liste* l);
liste* ajoute_fin(liste* l, int entier);
liste* ajoute_debut(liste* l, int entier);
liste* ajoute_position(liste* l, int entier, unsigned int position);
liste* remplir(liste* l, int tab[], unsigned int nb);
int rechercher(liste* l, int entier);
liste* supprimer(liste* l, int entier);
void vider(liste** l);

#endif //LISTE_H
