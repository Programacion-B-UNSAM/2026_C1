#include <stdio.h>
#include <stdlib.h>

#include "Catedra_M12.c"
#include "definiciones.h"
#include "funciones.c"

int main(void) {

#ifdef EJ1
    printf("\n=== EJERCICIO 1 ===\n");

#endif

#ifdef EJ2
    printf("\n=== EJERCICIO 2 ===\n");
    qnode_t* first = CATEDRA_CrearGrilla();

#endif

    return 0;
}