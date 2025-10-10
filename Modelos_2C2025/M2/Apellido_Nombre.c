/* Modelo Parcial */

/* Consideraciones Generales
 * - Escriba su código sobre este archivo.
 * - Las funciones deben estar definidas en el archivo funciones.c
 */

/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

#include "definiciones.h"
#include "funciones.c"
#include "Catedra_2.c"

int main()
{
#ifdef EJ1
    printf("\n\n========== Ejercicio 1 ==========\n\n");

    /* Comienzo de su codigo */

    /* Fin de su codigo */
#endif

#ifdef EJ2
    printf("\n\n========== Ejercicio 2 ==========\n\n");
    Node *primerNodo = CATEDRA_CrearListaEnlazada();

    /* Comienzo de su codigo */

    /* Fin de su codigo */
#endif

#ifdef EJ3
    printf("\n\n========== Ejercicio 3 ==========\n\n");
    dNode *ultimoNodo = NULL, *primerNodo = NULL;
    CATEDRA_CrearListaDoble(&primerNodo, &ultimoNodo);

    /* Comienzo de su codigo */

    /* Fin de su codigo */
#endif
    return 0;
}
