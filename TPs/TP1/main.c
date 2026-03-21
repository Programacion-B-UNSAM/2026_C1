#include <stdint.h>
#include <stdio.h>

#include "header.h"

int main() {
#ifdef EJ1
    testEjercicio1();
#endif

#ifdef EJ2
    testEjercicio2();
#endif

#ifdef EJ3
    testEjercicio3();
#endif

    return 0;
}
