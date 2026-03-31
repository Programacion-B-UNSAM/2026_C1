
#include <stdio.h>
#include <stdint.h>
#include "header.h"

extern int global_int;
extern int local_int;

void print_externs(void)
{
  printf("Estoy imprimiendo una variable global externa --> %d\n", global_int);
  /* Esta linea evita que el programa compile, porque no tengo acceso a variables locales de otro archivo */
  // printf("Estoy imprimiendo una variable local externa --> %d\n", local_int);
}

uint64_t power(uint64_t base)
{
  static int cuantas_veces = 0;
  uint64_t pow = 1;
  for (int i = 0; i < POW; ++i)
  {
    pow *= base;
  }
  cuantas_veces += 1;
  if (cuantas_veces > 10)
  {
    printf("Estas usando esta funcion un monton!\n");
  }
  return pow;
}
