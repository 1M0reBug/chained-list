#ifndef STRINGS_H
#define STRINGS_H

#include <string.h>
#include "types.h"

void str_afficher(strings* l);
strings* str_ajoute_fin(strings* l, char* chaine);
strings* str_ajoute_str_fin(strings* l, strings* e);
strings* str_ajoute_debut(strings* l, char* chaine);
strings* str_ajoute_position(strings* l, char* chaine, unsigned int position);
strings* str_remplir(strings* l, char* tab[], unsigned int nb);
int str_rechercher(strings* l, char* chaine);
strings* str_supprimer(strings* l, char* chaine);
void str_vider(strings** l);
int str_size(strings* l);
strings* fusion(strings* l, strings* l1, strings* l2);

void eclatement(strings* entree, strings** sortie1, strings** sortie2);
bool est_triee(strings* l);

#endif //STRINGS_H
