
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "CATEDRA_M16.c"
#include "funcs.c"

#define EJ1
#define EJ2

int main()
{

#ifdef EJ1
    printf("--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();
    /* Imprimir Grilla */

    /* Posicion nodo random */
    NodoGrilla *nodoRand = CATEDRA_NodoRandom(primerNodo);

    /* Camino mas corto  - prueben con distintas combinaciones! */
    Posicion n1 = {.fila = 0, .columna = 0};
    Posicion n2 = {.fila = 4, .columna = 6};

#endif // EJ1

#ifdef EJ2
    printf("--- EJERCICIO 2 ---\n\n");
    int tamanio = 0;
    customElement *vec = CATEDRA_CrearVector(&tamanio);

#endif // EJ2
    return 0;
}