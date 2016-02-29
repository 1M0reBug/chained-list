#ifndef STRINGS_H
#define STRINGS_H

#include <string.h>
#include "types.h"

void str_afficher(strings* l);
strings* str_ajoute_fin(strings* l, const char* chaine);
strings* str_ajoute_debut(strings* l, const char* chaine);
strings* str_ajoute_position(strings* l, char* chaine, unsigned int position);
strings* str_remplir(strings* l, const char* tab[], unsigned int nb);
int str_rechercher(strings* l, char* chaine);
strings* str_supprimer(strings* l, char* chaine);
void str_vider(strings** l);

#endif //STRINGS_H
