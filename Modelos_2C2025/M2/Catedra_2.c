#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "definiciones.h"

Node *CATEDRA_createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *CATEDRA_insFirst(Node *PrimerNode, int new_data)
{
    Node *newNode = CATEDRA_createNode(new_data);
    if (PrimerNode == NULL)
    {
        return newNode;
    }
    Node *current = PrimerNode;
    newNode->next = current;
    return newNode;
}

Node *CATEDRA_CrearListaEnlazada(void)
{ /* funciona */
    int aux_lista[] = {3463, 2661, 1897, 2184, 1411, 1549, 5341, 367, 3889, 2413};
    int lista_size = sizeof(aux_lista) / sizeof(aux_lista[0]);
    Node *nuevo_Node = NULL;
    for (int i = lista_size; i > 0; i--)
    {
        nuevo_Node = CATEDRA_insFirst(nuevo_Node, aux_lista[i - 1]);
    }
    return nuevo_Node;
}

dNode *CATEDRA_create_dNode(int data)
{
    dNode *new_dNode = (dNode *)malloc(sizeof(dNode));

    if (!new_dNode)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    new_dNode->data = data;
    new_dNode->next = NULL;
    new_dNode->prev = NULL;
    return new_dNode;
}

dNode *CATEDRA_insDFirst(dNode *primer_dNode, int new_data)
{
    dNode *new_dNode = CATEDRA_create_dNode(new_data);
    if (primer_dNode == NULL)
    {
        return new_dNode;
    }
    dNode *current = primer_dNode;
    new_dNode->next = current;
    new_dNode->prev = NULL;
    current->prev = new_dNode;
    return new_dNode;
}
void CATEDRA_CrearListaDoble(dNode **first, dNode **last)
{
    int aux_lista[] = {53, 17, 70, 69, 59, 94, 69, 93, 89, 62, 48, 68, 29, 40, 36};
    int lista_size = sizeof(aux_lista) / sizeof(aux_lista[0]);
    /* creo lista doble */
    dNode *nuevo_dNode = NULL;
    for (int i = lista_size; i > 0; i--)
        nuevo_dNode = CATEDRA_insDFirst(nuevo_dNode, aux_lista[i - 1]);
    /* rompo la lista doble */
    dNode *actual = nuevo_dNode;
    srand(time(NULL));
    int random = rand() % lista_size;
    // int random = 4;

    if (random < 4 || random > lista_size - 2)
        random = lista_size / 2; /* ya no es tan random */

    for (int i = 0; i < random; i++)
    {
        if (actual->next != NULL)
            actual = actual->next;
    }
    if (random % 2 == 0)
    {
        actual->next = actual->next->next;
    }
    else
    {
        if (actual->prev->prev && actual->prev->prev->prev)
            actual->prev = actual->prev->prev->prev;
    }
    actual = nuevo_dNode;
    while (actual->next != NULL)
        actual = actual->next;

    *first = nuevo_dNode;
    *last = actual;
}
