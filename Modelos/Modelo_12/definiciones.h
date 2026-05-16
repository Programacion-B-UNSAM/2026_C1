#ifndef _DEF_H
#define _DEF_H

#include <stdint.h>

#define EJ1
#define EJ2

typedef struct M12_t{
    char       dato;
    uint16_t  mask;
} M12_t;

typedef struct qnode_t {
    struct qnode_t* up;
    struct qnode_t* down;
    struct qnode_t* right;
    struct qnode_t* left;
    int valor;
} qnode_t;

#endif