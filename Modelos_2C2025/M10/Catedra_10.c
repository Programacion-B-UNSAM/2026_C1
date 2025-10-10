#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"

dnode_t *CATEDRA_CrearNodo(int num, char let)
{

    data_t *new_data = (data_t *)malloc(sizeof(data_t));
    dnode_t *new_node = (dnode_t *)malloc(sizeof(dnode_t));

    new_data->let = let;
    new_data->num = num;

    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void CATEDRA_InsLast(dnode_t **first, dnode_t *new_node)
{

    if (*first == NULL)
    {
        *first = new_node;
        return;
    }

    dnode_t *current = *first;
    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
    new_node->prev = current;
    new_node->next = NULL; /* porlas */
    return;
}

dnode_t *CATEDRA_CrearLista(void)
{
    char let_list[] = {'a', 'b', 'c', 'a', 'c', 'd', 'j', 'f', 'm', 'm', 'f'};
    int num_list[] = {1, 2, 3, 5, 6, 7, 0, 1, 3, 7, 8};

    dnode_t *first = NULL, *aux = NULL;
    for (int i = 0; i < 11; i++)
    {
        aux = CATEDRA_CrearNodo(num_list[i], let_list[i]);
        CATEDRA_InsLast(&first, aux);
    }

    aux->next = first;
    first->prev = aux;

    return first;
}
