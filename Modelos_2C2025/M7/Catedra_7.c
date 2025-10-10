#include "definiciones.h"
#include <stdlib.h>
#include <stdio.h>

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

qnode_t *CATEDRA_CrearGrilla(void)
{

  int matrix[9][13] = {
      {9, 23, 35, 6, 11, 27, 34, 12, 36, 31, 20, 25, 26},
      {2, 39, 30, 5, 8, 29, 37, 13, 17, 6, 7, 36, 0},
      {4, 33, 9, 1, 14, 21, 11, 28, 18, 38, 22, 32, 3},
      {35, 15, 10, 26, 12, 37, 39, 13, 19, 7, 4, 3, 30},
      {16, 24, 8, 27, 0, 31, 2, 18, 38, 19, 17, 15, 25},
      {22, 20, 1, 10, 5, 21, 23, 29, 28, 34, 14, 32, 8},
      {6, 36, 33, 7, 2, 11, 24, 26, 13, 12, 16, 9, 0},
      {4, 27, 5, 31, 23, 3, 18, 25, 21, 10, 17, 39, 29},
      {15, 1, 35, 20, 38, 37, 30, 19, 8, 7, 14, 22, 28}};

  qnode_t *node_matrix[9][13];
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 13; ++j)
    {
      node_matrix[i][j] = create_node(matrix[i][j]);
    }
  }

  /* @brief: porque no lo optimize?
   * Hay muchas conexiones que no las podes hacer mientras creas la matriz de nodos
   * porque los nodos con los que tenes que conectar no fueron creados todavia. Seguro
   * se puede optimizar esto un poco mas, pero la verdad que el trabajo que resulta
   * hacerlo no me valio la pena :P
   */
  /* first row */
  for (int j = 0; j < 12; ++j)
  {
    node_matrix[0][j]->down = node_matrix[1][j];
    node_matrix[0][j]->right = node_matrix[0][j + 1];
  }
  for (int j = 12; j > 0; --j)
    node_matrix[0][j]->left = node_matrix[0][j - 1];

  /* first collumn */
  for (int i = 0; i < 8; ++i)
  {
    node_matrix[i][0]->right = node_matrix[i][1];
    node_matrix[i][0]->down = node_matrix[i + 1][0];
  }
  for (int i = 8; i > 0; --i)
    node_matrix[i][0]->up = node_matrix[i - 1][0];

  /* middle things */
  for (int i = 1; i < 8; ++i)
  {
    for (int j = 1; j < 12; ++j)
    {
      node_matrix[i][j]->up = node_matrix[i - 1][j];
      node_matrix[i][j]->down = node_matrix[i + 1][j];
      node_matrix[i][j]->left = node_matrix[i][j - 1];
      node_matrix[i][j]->right = node_matrix[i][j + 1];
    }
  }

  /* last row */
  for (int j = 0; j < 12; ++j)
  {
    node_matrix[8][j]->up = node_matrix[7][j];
    node_matrix[8][j]->right = node_matrix[8][j + 1];
  }
  for (int j = 12; j > 0; --j)
    node_matrix[8][j]->left = node_matrix[8][j - 1];

  /* last column */
  for (int i = 0; i < 8; ++i)
  {
    node_matrix[i][12]->left = node_matrix[i][11];
    node_matrix[i][12]->down = node_matrix[i + 1][12];
  }
  for (int i = 8; i > 0; --i)
    node_matrix[i][12]->up = node_matrix[i - 1][12];

  return node_matrix[0][0];
}

static void C_showGrilla(qnode_t *up_left)
{
  qnode_t *leftmost = up_left;
  qnode_t *current = leftmost;

  while (leftmost != NULL)
  {
    while (current != NULL)
    {
      printf("%3d  ", current->valor);
      current = current->right;
    }
    printf("\n");
    leftmost = leftmost->down;
    current = leftmost;
  }
}

// int main(void)
// {

//   qnode_t *up_left = CATEDRA_CrearGrilla();

//   C_showGrilla(up_left);

//   return 0;
// }
