#include <stdint.h>
#include <stdio.h>

#include "header.h"

#include "catedra.c"
#include "functions.c"

int main() {
#ifdef EJ1
    testEjercicio1();
#endif

#ifdef EJ2
    testEjercicio2();
#endif
    return 0;
}