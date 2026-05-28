
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
#include "Catedra_M17.c"

#define EJ1
#define EJ2

void imprimirGrilla(NodoGrilla *first);
void printTargets(NodoGrilla **vec, int size);
Posicion findPos(NodoGrilla *rand);
void caminoCorto(NodoGrilla *nodo1, NodoGrilla *nodo2);
void printPaths(NodoGrilla *start, NodoGrilla **targets, int size, int distancia);

void printVec(uint8_t *vec, int size);
void printCirc(Node *first);
int genVec(uint8_t **vec, Node *first);

int main()
{
#ifdef EJ1
    printf("--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();
    /* Imprimir Grilla */
    imprimirGrilla(primerNodo);

    /* Info Item B  */
    NodoGrilla **targets;
    int size, distancia;
    NodoGrilla *start = CATEDRA_InfoRandom(primerNodo, &targets, &size, &distancia);

    /* Imprimir start y targets */
    printf("\nStart = %c", start->dato);
    printTargets(targets, size);
    printf("Distancia = %d\n", distancia);

    /* Imprimir los caminos que cumplan */
    printPaths(start, targets, size, distancia);

#endif // EJ1

#ifdef EJ2
    printf("--- EJERCICIO 2 ---\n\n");
    int tamanio = 0;
    Node *first = CATEDRA_CrearLista();

    /* Item a --> Lista original */
    printCirc(first);

    /* Item b --> Funcion */
    uint8_t *vec = NULL;
    int size = genVec(&vec, first);

    /* item c --> Lista final y vector*/
    printf("==== Clean ====\n");
    printf("Lista:\n");
    printCirc(first);
    printf("Vector:\n");
    printVec(vec, size);

#endif // EJ2
    return 0;
}

void imprimirGrilla(NodoGrilla *first)
{
    if (first == NULL)
        return;

    NodoGrilla *actual = NULL;
    while (first != NULL)
    {
        actual = first;
        while (actual != NULL)
        {
            printf("%c ", actual->dato);
            actual = actual->right;
        }
        printf("\n");
        first = first->down;
    }
}

void printTargets(NodoGrilla **vec, int size)
{
    printf("\nTargets = ");
    for (int i = 0; i < size; i++)
    {
        printf("%c - ", vec[i]->dato);
    }
    printf("\n");
    return;
}

Posicion findPos(NodoGrilla *rand)
{
    if (rand == NULL)
        return (Posicion){.fila = -1, .columna = -1};

    Posicion nRand = {0, 0};

    /* Si me muevo hacia arriba y a la izquierda, voy a llegar a first sin
     * importar donde este, y me ahorro tener que pasarle un argumento extra
     * a la funcion.
     */

    while (rand->up != NULL)
    {
        nRand.fila++;
        rand = rand->up;
    }
    while (rand->left != NULL)
    {
        nRand.columna++;
        rand = rand->left;
    }

    return nRand;
}

void caminoCorto(NodoGrilla *nodo1, NodoGrilla *nodo2)
{
    Posicion n1 = findPos(nodo1);
    Posicion n2 = findPos(nodo2);

    int dir = n2.columna - n1.columna;
    char cDir;

    /* Si es menor que 0, me muevo a la izquierda*/
    if (dir < 0)
    {
        cDir = 'l';
        /* quiero siempre un valor positivo para no tener que hace 4 loops */
        dir = -dir;
    }
    else
    {
        cDir = 'r';
    }

    for (dir; dir > 0; dir--)
    {
        if (cDir == 'l')
        {
            printf("%c < ", nodo1->dato);
            nodo1 = nodo1->left;
        }
        else if (cDir == 'r')
        {
            printf("%c > ", nodo1->dato);
            nodo1 = nodo1->right;
        }
    }

    /* Idem pero para arriba o abajo*/
    dir = n2.fila - n1.fila;

    if (dir < 0)
    {
        cDir = 'u';
        dir = -dir;
    }
    else
    {
        cDir = 'd';
    }

    for (dir; dir > 0; dir--)
    {
        if (cDir == 'u')
        {
            printf("%c ^ ", nodo1->dato);
            nodo1 = nodo1->up;
        }
        else if (cDir == 'd')
        {
            printf("%c v ", nodo1->dato);
            nodo1 = nodo1->down;
        }
    }
    printf("%c\n", nodo1->dato);
    return;
}

void printPaths(NodoGrilla *start, NodoGrilla **targets, int size, int distancia)
{
    if (start == NULL)
        return;

    Posicion startPos = findPos(start);
    Posicion auxPos;
    int any = 0;
    for (int i = 0; i < size; i++)
    {
        if (targets[i] == NULL)
            return;
        auxPos = findPos(targets[i]);

        /* Aca era importante que ambas distancias terminaran siendo positivas! */
        int distX = auxPos.fila - startPos.fila;
        if (distX < 0)
            distX = -distX;

        int distY = auxPos.columna - startPos.columna;
        if (distY < 0)
            distY = -distY;

        if ((distX + distY) == distancia) /* Puedo calcular distancia sin moverme por la grilla */
        {
            caminoCorto(start, targets[i]);
            any = 1;
        }
    }
    if (any == 0)
        printf("No hay caminos que cumplan!\n");
    return;
}

void printVec(uint8_t *vec, int size)
{
    if (vec == NULL)
        return;
    for (int i = 0; i < size; i++)
    {
        printf("%d - ", vec[i]);
    }
    printf("\n");
    return;
}

void printCirc(Node *first)
{
    if (first == NULL)
    {
        printf("Lista vacia");
        return;
    }

    Node *current = first;
    while (current->next != first)
    {
        printf("%hhu -> ", current->dato);
        current = current->next;
    }
    printf("%hhu\n", current->dato);
    return;
}
uint8_t _mask(uint8_t dato)
{
    if ((dato & 0b11) == 0b11)
        return 1;
    else
        return 0;
}

uint8_t *_expand_vec(uint8_t **vec, int *size, uint8_t dato)
{
    /* Me hago una funcion auxiliar que expanda el vector.
     * Aca lo mas importante era ser ordenados en el orden en que
     * uno hacia las cosas
     */
    uint8_t *aux = NULL;

    if (*vec == NULL)
    { /* Si vacio, lo creo y salgo */
        aux = (uint8_t *)malloc(sizeof(uint8_t));
        aux[0] = dato;
        *size = 1; /* Siempre mi size va a ser la cantidad de elementos q tenga el vector */
        return aux;
    }

    /* Podria hacer */
    aux = (uint8_t *)realloc(*vec, sizeof(uint8_t) * (*size + 1));
    if (aux == NULL)
        return *vec;

    aux[*size] = dato;
    *size += 1;
    /* Hay que tener cuidado con *size++ por que en vez de agrandar lo que hay en *size, mueve el puntero
     * Es decir:
     * size = 0xAA, *size = 3
     *
     * *size +=1 --> size = 0xAA, *size = 4
     *
     * Pero,
     *
     * *size++   --> size = 0xAB, *size = ?
     *
     * Lo mejor, es siempre usar parentesis:
     * (*size)++
     * (*size)+=1
     */

    return aux;
}

int genVec(uint8_t **vec, Node *first)
{
    if (first == NULL || first->next == NULL)
        return 0;

    /* El primer nodo es siempre impar, nunca se borra, por lo que arranco por el segundo */
    Node *current = first->next, *prev = first;

    int size = 0;
    int is_par = 1;
    while (current->next != first)
    {
        if (is_par && _mask(current->dato))
        {
            *vec = _expand_vec(vec, &size, current->dato);
            prev->next = current->next;
            free(current);
            current = prev->next;
            /* Si elimino el nodo, no cambio el valor de is_par.
             * De esta manera, tengo en cuenta el "movimiento" de los nodos al eliminar
             * uno
             */
        }
        else
        {
            /* Solo cambio mi is_par si me muevo en la lista! */
            prev = current;
            current = current->next;
            is_par = !is_par;
        }
    }

    if (is_par && _mask(current->dato))
    {
        prev->next == first;
        *vec = _expand_vec(vec, &size, current->dato);
        free(current);
    }

    return size;
}