#include <stdio.h>
#include "definiciones.h"
#include "Catedra_M13.c"

#define EJ1
#define EJ2

int main(void)
{
#ifdef EJ1
  printf("\n ==== EJERCICIO 1 ==== \n");

#endif

#ifdef EJ2
  printf("\n ==== EJERCICIO 2 ==== \n");
  qnode_t *qfirst = CATEDRA_CrearGrilla();

#endif

  /* Libere la memoria dinamica utilizada*/

  return 0;
}