#ifndef TYPES_H
#define TYPES_H

typedef struct _liste liste;

struct _liste {
    int valeur;
    liste *suivant;
}

#endif //TYPE_H
