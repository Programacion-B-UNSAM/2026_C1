#include <stdio.h>

typedef struct
{
  int a;
  int b;
  float c;
} nums_t;

void argumento_por_referencia(int *a, int *b, int *c)
{
  (*a)++;
  *b = 300;
  *c = *b - *a;
}

void print_memory(int a)
{
  printf("&a = \t%p\n", &a);
  a = 50; /* modifica lo que esta en la direccion de memoria &a, que no es lo mismo que la direccion de memoria &var */
}

int main(void)
{

  int var = 10, var1 = 20, var2 = 30;
  int *ptr = &var;

  printf("&var = \t%p \n", ptr);
  print_memory(var);

  printf("\nvar = %d", var);
  printf("\nvar1 = %d", var1);
  printf("\nvar2 = %d\n", var2);
  argumento_por_referencia(ptr, &var1, &var2);
  printf("\n--> FUNCION <--\n");

  printf("\nvar = %d", var);
  printf("\nvar1 = %d", var1);
  printf("\nvar2 = %d\n", var2);

  return 0;
}
