#ifndef _DEF_H
#define _DEF_H

#include <stdint.h>

#define EJ1
#define EJ2

typedef struct node_t{
    char dato;
    struct node_t *next;
}node_t;

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


/* Prototipos Ejercicio 1 */
node_t *create_node_t(char data);
void ins_first(node_t **first, char new_data);
void print_list(node_t *first);
void del_last(node_t **first);
void free_list(node_t **first);
void toggle_circ(node_t **first);

/* Prototipos Ejercicio 2 */
void showGrilla(qnode_t *up_left);
void printMinas(qnode_t *up_left);
void findMina(qnode_t *up_left, int fila, int col);

#endif