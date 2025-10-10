#ifndef _DEF_H
#define _DEF_H

#define EJ1
// #define EJ2

typedef struct qnode_t
{
  struct qnode_t *up;
  struct qnode_t *down;
  struct qnode_t *right;
  struct qnode_t *left;
  int valor;
} qnode_t;

#endif