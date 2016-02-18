#ifndef TYPES_H
#define TYPES_H

typedef struct _liste liste;
typedef struct _strings strings;

struct _liste {
    int valeur;
    liste *suivant;
};

struct _strings {
    char* valeur;
    strings *suivant;
};

typedef enum {false, true} bool;

#endif //TYPE_H
