#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "funciones.c"

int global_int = 333;

int main(void)
{

  uint64_t resultado = 3;

  int local_int = 111;

  print_externs();

  for (int i = 0; i < 11; ++i)
  {
    /* resultado es una variable local, pero puedo modificarla utilizando el return de una funcion! */
    resultado = power(resultado);
    // printf("%llu <-- result\n", result); /* Por si quieren ver los valores intermedios (escala rapido)*/
  }

  printf("%llu <-- resultado\n", resultado);

  return 0;
}