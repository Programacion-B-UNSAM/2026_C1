#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define EJ1
#define EJ2

typedef struct bst_node_t {
    int data;
    struct bst_node_t* left;
    struct bst_node_t* right;
} BSTNode;

typedef struct tnode_info_t {
    char nombre_padre;
    char nombre_propio;
    int dist_a_padre;
} tnode_info_t;

typedef struct graph_node_t {
    char nombre;
    int dist_a_padre;
    struct graph_node_t** children;
    int num_children;
} GraphNode;

/* EJERCICIO 1 */
void createTree(int* arr, int size, BSTNode** root);
int findNode(BSTNode* root, int value);

/* EJERCICIO 2 */
void createGraph(tnode_info_t* info, int size, GraphNode** root);
void minDistAtLevel(GraphNode* root, int level);

/* Test functions */
void testEjercicio1(void);
void testEjercicio2(void);

#endif /* HEADER_H */