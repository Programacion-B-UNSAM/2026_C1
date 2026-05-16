#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "definiciones.h"

#define ROWS 15
#define COLS 20

static qnode_t *create_node(int num)
{
    qnode_t *new_node = (qnode_t *)malloc(sizeof(qnode_t));
    if (new_node == NULL)
    {
        perror("Memory allocation failed!\n");
        exit(1);
    }

    new_node->up = NULL;
    new_node->down = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    new_node->valor = num;

    return new_node;
}

static void rng_seed(unsigned seed)
{
    if (seed == 0)
        seed = (unsigned)time(NULL);
    srand(seed);
}

// Devuelve un entero en [lo, hi] (inclusivo). Si hi < lo, devuelve lo.
static uint8_t rand_incl(uint8_t lo, uint8_t hi)
{
    if (hi < lo)
        return lo;                         // evita modulo 0 o rangos inválidos
    unsigned span = (unsigned)hi - lo + 1; // tamaño del rango
    return (uint8_t)(lo + (rand() % span));
}

static uint8_t gen_row(int half)
{
    uint8_t lo, hi;
    if (half == 0)
    {
        lo = 1;
        hi = (uint8_t)((ROWS / 2) - 1);
    }
    else
    {
        lo = (uint8_t)(ROWS / 2);
        hi = (uint8_t)(ROWS - 2);
    }
    return rand_incl(lo, hi);
}

static uint8_t gen_col(int half)
{
    uint8_t lo, hi;
    if (half == 0)
    {
        lo = 1;
        hi = (uint8_t)((COLS / 2) - 1);
    }
    else
    {
        lo = (uint8_t)(COLS / 2);
        hi = (uint8_t)(COLS - 2);
    }
    return rand_incl(lo, hi);
}

qnode_t *CATEDRA_CrearGrilla(void)
{
    int matrix[ROWS][COLS] = {
        {9, 22, 35, 6, 11, 27, 34, 11, 36, 31, 20, 25, 26, 60, 73, 31, 20, 25, 26, 60},
        {2, 39, 9, 57, 23, 30, 33, 13, 17, 6, 17, 36, 0, 58, 68, 51, 17, 36, 0, 37},
        {4, 7, 9, 1, 30, 23, 33, 28, 18, 38, 22, 32, 3, 68, 51, 58, 22, 32, 3, 8},
        {35, 15, 10, 10, 23, 30, 33, 39, 13, 19, 7, 4, 3, 51, 58, 68, 7, 4, 3, 37},
        {18, 14, 24, 26, 51, 58, 68, 31, 18, 38, 19, 17, 15, 51, 58, 6, 19, 17, 15, 37},
        {22, 20, 1, 10, 52, 21, 38, 29, 28, 34, 14, 32, 8, 4, 82, 34, 14, 32, 8, 46},
        {6, 36, 87, 7, 2, 11, 24, 26, 13, 21, 4, 9, 0, 73, 37, 21, 4, 9, 0, 73},
        {96, 27, 52, 31, 87, 3, 1, 25, 21, 10, 17, 39, 29, 45, 32, 10, 17, 39, 29, 93},
        {5, 23, 35, 2, 38, 37, 31, 19, 8, 7, 14, 22, 28, 67, 6, 7, 14, 22, 51, 68},
        {10, 12, 9, 14, 19, 13, 17, 27, 21, 26, 24, 18, 21, 31, 41, 26, 24, 40, 47, 31},
        {15, 4, 7, 86, 93, 6, 8, 7, 76, 3, 1, 15, 22, 34, 45, 23, 40, 47, 22, 34},
        {25, 38, 29, 36, 23, 5, 75, 38, 87, 20, 19, 28, 13, 86, 51, 30, 19, 28, 13, 14},
        {18, 24, 8, 27, 0, 5, 12, 16, 23, 30, 33, 40, 47, 51, 58, 19, 17, 15, 25, 37},
        {22, 20, 1, 10, 52, 21, 38, 29, 75, 86, 93, 96, 8, 46, 82, 34, 14, 32, 8, 46},
        {9, 22, 35, 34, 11, 73, 31, 20, 25, 6, 11, 2, 3, 31, 20, 25, 26, 60, 26, 60},
    };

    qnode_t *node_matrix[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            node_matrix[i][j] = create_node(matrix[i][j]);
        }
    }

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (i > 0)
            {
                node_matrix[i][j]->up = node_matrix[i - 1][j];
            }
            if (i < ROWS - 1)
            {
                node_matrix[i][j]->down = node_matrix[i + 1][j];
            }
            if (j > 0)
            {
                node_matrix[i][j]->left = node_matrix[i][j - 1];
            }
            if (j < COLS - 1)
            {
                node_matrix[i][j]->right = node_matrix[i][j + 1];
            }
        }
    }

    rng_seed(0);
    int rand_col = gen_col(0);
    int rand_row = gen_row(0);
    node_matrix[rand_row][rand_col]->right = NULL;

    rand_col = gen_col(1);
    rand_row = gen_row(1);
    node_matrix[rand_row][rand_col]->right = NULL;

    return node_matrix[0][0];
}

dnode_t *CATEDRA_CrearDList(void)
{
    int list[] = {12, 3, 25, 7, 19, 0, 27, 14, 5, 22, 9, 1, 17, 11, 26, 27};
    int size = (int)(sizeof(list) / sizeof(list[0]));

    dnode_t *firstNode = NULL;
    dnode_t *prevNode = NULL;

    for (int i = 0; i < size; ++i)
    {
        dnode_t *node = (dnode_t *)malloc(sizeof(dnode_t));
        if (!node)
        {
            return NULL;
        }
        node->dato = list[i];
        node->next = NULL;
        node->prev = prevNode;

        if (prevNode)
        {
            prevNode->next = node;
        }
        else
        {
            firstNode = node;
        }
        prevNode = node;
    }

    rng_seed(0);
    int random_idx = (int)rand_incl(1, (uint8_t)(size - 2));

    dnode_t *aux = firstNode;
    for (int i = 0; i < random_idx; ++i)
    {
        aux = aux->next;
    }

    return aux;
}
