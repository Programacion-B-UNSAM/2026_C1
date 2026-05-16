#ifndef _DEF_H
#define _DEF_H

#include <stdint.h>

typedef enum accion_t
{
    SET = 14,
    RESET = 3
} accion_t;

typedef struct M13_t
{
    accion_t act;
    uint8_t nrBits; // Debe ser 1..16
} M13_t;

typedef struct qnode_t
{
    struct qnode_t *up;
    struct qnode_t *down;
    struct qnode_t *right;
    struct qnode_t *left;
    int valor;
} qnode_t;

typedef struct dnode_t
{
    int dato;
    struct dnode_t *next;
    struct dnode_t *prev;
} dnode_t;

#endif