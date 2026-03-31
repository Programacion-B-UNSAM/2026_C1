#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_LEN 5

// #define MALLOC
// #define CALLOC
#define REALLOC
#define TIME

void print_array(const int *arr, int len, const char *label)
{
  printf("%s: ", label);
  for (size_t i = 0; i < len; ++i)
  {
    printf(" %d -", arr[i]);
  }
  printf("\n");
}

int main()
{

#ifdef MALLOC
  printf("\n=== malloc() ===\n");
  int *malloc_array = (int *)malloc(ARRAY_LEN * sizeof(int)); /* No - inicializado */

  if (!malloc_array)
  { /* equivalente a malloc_array == NULL */
    perror("malloc failed");
    return 1;
  }

  for (int i = 0; i < ARRAY_LEN; ++i)
  {
    malloc_array[i] = i + 1; /* Inicializo */
  }
  print_array(malloc_array, ARRAY_LEN, "malloc_array");
  free(malloc_array);
#endif

#ifdef CALLOC
  printf("\n=== calloc() ===\n");
  int *calloc_array = (int *)calloc(ARRAY_LEN, sizeof(int));

  if (!calloc_array)
  {
    perror("calloc failed");
    return 1;
  }
  /* No necesito inicializarlo, estoy seguro que va a ser 0 */
  print_array(calloc_array, ARRAY_LEN, "calloc_array");
  free(calloc_array);
#endif

#ifdef REALLOC
  printf("\n=== realloc() - Caso a: re-asignacion en el lugar ===\n");
  int *realloc_array = (int *)malloc(5 * sizeof(int)); /* creo bloque */
  if (!realloc_array)
  {
    perror("malloc failed");
    return 1;
  }
  for (int i = 0; i < ARRAY_LEN; i++)
    realloc_array[i] = i + 10; /* inicializo miembros */
  print_array(realloc_array, ARRAY_LEN, "Original array");

  int *original_ptr = realloc_array;
  printf("Original pointer --> %p\n", original_ptr);
  realloc_array = (int *)realloc(realloc_array, (ARRAY_LEN + 1) * sizeof(int)); /* Intento modificar */
  if (!realloc_array)
  { /* esto me indica que falle */
    perror("realloc failed");
    free(original_ptr); /* antes de salir del programa, libero la memoria del bloque original */
    return 1;
  }
  /* Si no falle, continuo */

  /* el bloque original iba de realloc_array[0] a realloc_array[4] --> longitud 5 (ARRAY_LEN)
   * despues de modificarlo, le agregue un miembro, por lo que voy de
   * realloc_array[0] a realloc_array[ARRAY_LEN]
   */
  //   realloc_array[ARRAY_LEN] = 99;

  /* i.e. 0x02 + ARRAY_LEN * sizeof(int) = 0x16 = &realloc_array[ARRAY_LEN]*/
  *(realloc_array + ARRAY_LEN) = 100;
  print_array(realloc_array, ARRAY_LEN + 1, "realloc array");
  printf("New pointer      --> %p\n", realloc_array);

  printf("\n\n\n\n=== realloc() - Case b: El bloque se mueve de lugar ===\n");

  /* uso bloques grandes para 'asegurar' el movimiento */
  int *big = (int *)malloc(1000000 * sizeof(int));
  printf("Original block pointer (big)  --> %p\n", big);

  int *moved = (int *)realloc(big, 2000000 * sizeof(int)); /* Es gigante, ppr lo que probablemente se mueva */
  if (moved)
  {
    printf("→ Large block successfully resized. (it may have moved)\n");
    printf("Moved block pointer (moved)   --> %p\n", moved);
    free(moved);
  }
  else
  {
    printf("→ Failed to realloc large block.\n");
    free(big);
  }

  printf("\n\n\n");

  printf("\n\n\n\n=== realloc() - Case c: No logro modificar el tamanio del bloque ===\n");
  /* Simulo caso de falla usando bloques gigantes */
  int *huge = (int *)malloc(1000 * sizeof(int));
  int *attempt = (int *)realloc(huge, 10000000000000000); /* absurdamente grande */
  if (!attempt)
  { /* me fijo si funciona */
    printf("→ realloc no logro expandir el bloque de memoria .\n\n\n");
    free(huge); /* Importante liberar el original */
  }
  else
  {
    free(attempt);
  }

#endif

#ifdef TIME

  int big_array = 100000000;
  clock_t start, end;
  double cpu_time_used;

  start = clock();
  int *malloc_time = (int *)malloc(big_array * sizeof(int));
  if (malloc_time == NULL)
    printf("malloc failed\n");
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("malloc time: %lf seconds\n", cpu_time_used);

  start = clock();
  int *calloc_time = (int *)calloc(big_array, sizeof(int));
  end = clock();
  if (calloc_time == NULL)
    printf("calloc failed\n");
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("calloc time: %lf seconds\n", cpu_time_used);

  free(calloc_time);
  free(malloc_time);
#endif

  return 0;
}
