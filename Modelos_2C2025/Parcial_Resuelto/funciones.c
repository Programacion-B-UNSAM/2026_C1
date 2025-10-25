/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


/* === EJERCICIO 1 === */
node_t *create_node_t(char data){
    node_t *newnode_t = (node_t *)malloc(sizeof(node_t));
    if (!newnode_t)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newnode_t->dato = data;
    newnode_t->next = NULL;
    return newnode_t;
}

void ins_first(node_t **first, char new_data){
  node_t *newnode = create_node_t(new_data);
  if (first == NULL || *first == NULL)
  {
      *first = newnode;
      return;
  }
  newnode->next = *first;

  node_t *aux = *first;
  while (aux){
    if (aux->next == NULL){
      break;
    }

    if (aux->next == *first){
      aux->next = newnode;
      break;
    }
    aux = aux->next;
  }
  *first = newnode;

  return;
}

void print_list(node_t *first){

  if (first == NULL){
    printf("NULL\n");
    return;
  }

  node_t *aux = first;
  while(aux->next != NULL && aux->next != first){ 
    printf("%c -> ", aux->dato);
    aux = aux->next;
  }

  if(aux->next == NULL){
    printf("%c -> NULL\n", aux->dato);

  }else{
    printf("%c -> %c -> ...\n", aux->dato, aux->next->dato);
  }
  return;
}

void del_last(node_t **first){
  if (*first == NULL){
    printf("La lista ya esta vacia!\n");
    return;
  }

  if ((*first)->next == NULL || (*first)->next == *first){
    free(*first);
    *first = NULL;
    return;
  }

  node_t *aux = *first;

  while(aux->next->next != NULL && aux->next->next != *first){ /* voy hasta el ante-ultimo */
    aux = aux->next;
  }

  node_t *aux2 = aux->next;

  if (aux->next->next == NULL){
    aux->next = NULL;
  }else{
    aux->next = *first;
  }
  free(aux2);
  return;

}

void free_list(node_t **first){
  node_t *prev, *aux = *first;
  if (*first == NULL){
    printf("Lista vacia\n");
    return;
  }

  while (aux != NULL && aux != *first){
    prev = aux;
    aux = aux->next;
    free(prev);
  }
  *first = NULL;
  return;

}

void toggle_circ(node_t **first){

  if (*first == NULL){
    printf("Lista vacia!\n");
    return;
  }
  node_t *aux = *first;

  while (aux){
    if (aux->next == NULL){
      aux->next = *first;
      return;
    }

    if (aux->next == *first){
      aux->next = NULL;
      return;
    }
    aux = aux->next;
  }
  return;
}

/* === EJERCICIO 2 === */
void showGrilla(qnode_t *up_left)
{
  qnode_t *leftmost = up_left;
  qnode_t *current = leftmost;

  while (leftmost != NULL)
  {
    while (current != NULL)
    {
      printf("%2d ", current->valor);
      current = current->right;
    }
    printf("\n");
    leftmost = leftmost->down;
    current = leftmost;
  }
}

static int quinto_bit(int dato){
  int aux = dato ^ 0b10000;

  return (aux % 7 == 0); /* si es multiplo de 7 devuelve 1, sino 0*/

  // // Otras formas de resolverlo:
  // if (dato >> 0b1000){ /* Si el 5to bit es 1 */
  //   aux = dato & ~(0b1000); /* ~0b10000 = 0b1111111111... 1110 1111*/
  //   aux = dato - 16; /* 16 = 0b10000*/
  // }else{ /* Si el 5to bit es un 0 */
  //   aux = dato | 0b10000; /* 0b0000000000000 ... 0001 0000 */
  //   aux = dato + 16; /* 16 = 0b10000*/
  // }
}

void printMinas(qnode_t *up_left){

  qnode_t *leftmost = up_left;
  qnode_t *current = leftmost;

  while (leftmost != NULL)
  {
    while (current != NULL)
    {
      if (quinto_bit(current->valor)){
        printf("X ");
      }else{
        printf(". ");
      }
      current = current ->right;
    }
    printf("\n");
    leftmost = leftmost->down;
    current = leftmost;
  }
}


void findDimensions(qnode_t *up_left, int *rows, int *columns)
{
  qnode_t *current = up_left;

  *rows = 0;
  while (current != NULL)
  {
    (*rows)++;
    current = current->down;
  }
  current = up_left;
  *columns = 0;
  while (current != NULL)
  {
    (*columns)++;
    current = current->right;
  }
}


void findMina(qnode_t *up_left, int fil, int col){
  int max_f, max_c;
  findDimensions(up_left, &max_f, &max_c);
  printf("Dimensiones = %d x %d\n", max_f, max_c);

  if(fil > max_f || col > max_c || fil <= 0 || col <= 0){
    printf("Posicicon no valida\n");
    return;
  }

  qnode_t *cur = up_left;
  /* Ambas formas son equivalentes */
  for (int i = 0; i < col-1; i++){ 
    cur = cur->right;
  }
  for (int i = 0; i < fil-1; i++, cur = cur->down){
    
  }

  if (quinto_bit(cur->valor)){
    printf("Mina!\n");
    return;
  }
  int suma = 0;

  /* Verifico vecinos */
  if (cur->up){
    suma += quinto_bit(cur->up->valor);
    if (cur->up->left){
      suma += quinto_bit(cur->up->left->valor);
    }
    if (cur->up->right){
      suma += quinto_bit(cur->up->right->valor);
    }
  } 

  if (cur->right){
    suma += quinto_bit(cur->right->valor);
  }

  if (cur->down){
    suma += quinto_bit(cur->down->valor);
    if (cur->down->right){
      suma += quinto_bit(cur->down->right->valor);
    } 
    if (cur->down->left){
      suma += quinto_bit(cur->down->left->valor);
    }
  }    
  if (cur->left){
    suma += quinto_bit(cur->left->valor);
  }
  
  if (suma){
    printf("Hay %d vecinos que son mina\n", suma);
  }else{
    printf("Banderita!\n");
  }

  return;
}



